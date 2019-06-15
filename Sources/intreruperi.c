/*
 * intreruperi.c
 *
 *  Created on: Jun 5, 2019
 *      Author: ESD
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "comenzi.h"
#include "stari.h"
#include "package.h"

extern unsigned char semnalizare_stanga, semnalizare_dreapta;
extern unsigned char numarare_timer;
extern unsigned char fanion_timer, fanion_receptie;
extern unsigned char cmp_address, data_adress;
extern unsigned char data_acceleratie;

extern struct package pack;

//rutina intrerupere Timer 1
interrupt 11 void TPM1_timerInt()
{
    byte  varTOF;
    varTOF = TPM1SC;    // clear TOF; first read and then write 0 to the flag
    TPM1SC &= 0x7F;
    
    if(numarare_timer == 0) {
    	if(semnalizare_stanga == 1) 
    	    PTFD |= 0x80;
    	if(semnalizare_dreapta == 1)
    	    PTFD |= 0x01;
    }

    if(numarare_timer == 3)
    	PTFD &= 0x7E;
    	
    if(numarare_timer == 4)
        fanion_timer = 1;
    
    
    numarare_timer++;
    numarare_timer %= 5;
}  


//rutina intrerupere Receptie seriala
interrupt 17 void SCI1_receive()
{
    unsigned char rc, sci1d_copy;
    unsigned char sum = 0x00;
    int i;
    rc = SCI1S1;
    sci1d_copy = SCI1D;
    
    
    switch(cmp_address) {
        case P_ID: 
            pack.ID = sci1d_copy;
            cmp_address = P_SIZE;
            break;
        case P_SIZE: 
            pack.size = sci1d_copy;
            if(pack.size == 0)
                cmp_address = P_CHECKSUM;
            else cmp_address = P_DATA;
            data_adress = 0;
            break;
        case P_DATA: 
            pack.data[data_adress] = sci1d_copy;
            data_adress++;
            if(data_adress == pack.size)
                cmp_address = P_CHECKSUM;
            break;
        case P_CHECKSUM:
            pack.checksum = sci1d_copy;
            sum = pack.ID;
            sum += pack.size;
            for(i = 0; i < data_adress; i++)
                sum += pack.data[i];
            if(sum == pack.checksum) {
                fanion_receptie = 1;
            }
            cmp_address = P_ID;
            break;
    }
    //caracter_receptionat = SCI1D;
    //fanion_receptie = 1;
 
}



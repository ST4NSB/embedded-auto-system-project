#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "comenzi.h"

#define P_ID 0
#define P_SIZE 1
#define P_DATA 2
#define P_CHECKSUM 3

int cmp_address = 0, data_adress = 0;

struct package {
    unsigned char ID;
    unsigned char size;
    unsigned char data[5];
    unsigned char checksum;
}pack;

unsigned char caracter_receptionat;        // caracterul receptionat pe intrerupere   
unsigned char numarare_timer;
unsigned char semnalizare_stanga, semnalizare_dreapta;

unsigned char fanion_timer            = 0;  // avem de tratat un eveniment de timer 
unsigned char fanion_receptie         = 0;  // avem de tratat un eveniment de receptie caracter 
unsigned char validare_ecou           = 0;     // validare transmitere in ecou a caracterului primit 
unsigned char validare_stare_automata = 0;    // validare tramsnmitere automata a starii



void Init(){
      //configurare procesor
    SOPT  = 0x00;     /* Disable COP    */
    ICGC2  = 0X00;       // Set up ICG control register 2
    ICGC1  = 0X78;       // Set up ICG for FEE, 4MHz external crystal, busclk = 8MHz
    while(!(ICGS1 & 0x08));

    // configurare PORT F
    PTFDD = 0xFF;     // set port f as outputs for LED operation
    
    //configurare PORT C
    PTCDD = ~0x44; // SW1 si SW2 pentru intrare
    PTCPE = 0x44;
   
     //configurare timer 1 - 1s
    TPM1SC = 0x4F;    
    TPM1MODH = 0x33;    
    TPM1MODL = 0x33;
    
   
    //configurare seriala 1
    SCI1BD = 8000000/16/19200;
    SCI1C1 = 0;
    SCI1C2 = 0x2C; //validare transmisie prin interogare si receptie prin intrerupere
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


void tratare_seriala() {
    caracter_receptionat = pack.ID;
    switch(caracter_receptionat) {
      case SPS: semnalizare_stanga = 1; break;
      case SOS: semnalizare_stanga = 0; break;
      case SPD: semnalizare_dreapta = 1; break;
      case SOD: semnalizare_dreapta = 0; break;
      case SPA: semnalizare_stanga = 1; 
      	  	  	semnalizare_dreapta = 1;
      	  	  	break;
      case SOA: semnalizare_stanga = 0;
      	  	  	semnalizare_dreapta = 0;
      	  	  	break;
    /*
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7': PTFD = 0x01 << (caracter_receptionat - '0'); break;
      
      case '8': PTFD = 0xff;break;
      case '9': PTFD = 0x0;break;
      
      case 'p':
      case 'P': validare_ecou = 1; break;
      case 'o':
      case 'O': validare_ecou = 0; break;
      
      case 'b':
      case 'B': validare_stare_automata = 1; break;
      case 'e':
      case 'E': validare_stare_automata = 0; break;
      
      case 's':
      case 'S':
               while(!(SCI1S1 & 0x80)); //asteptam terminare transmisie  - verific daca pot sa transmit
                   if( (PTCD & 0x04) == 0x04) 
                       SCI1D = 'L';
                   else
                       SCI1D = 'A';
               break;    
      */         
      default:  
            if (validare_ecou) {
              
               while(!(SCI1S1 & 0x80)); //asteptam terminare transmisie  - verific daca pot sa transmit
               SCI1D = caracter_receptionat;
            }
     }
 }

void tratare_timer()
{
	
}

void main(void) {
  Init();
  EnableInterrupts; /* enable interrupts */
  /* include your code here */

  
  for(;;) {
  
    if(fanion_timer==1)        // avem de tratat eveniment de timer
        {
          tratare_timer();
          fanion_timer = 0;
        }
      if(fanion_receptie==1)    // avem de tratat eveniment de receptie caracter
        {
          tratare_seriala();
          fanion_receptie = 0;
        }
  } /* loop forever */
  /* please make sure that you never leave main */
}



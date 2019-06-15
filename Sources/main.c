#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "comenzi.h"
#include "stari.h"
#include "package.h"

struct package pack;

struct stransition {
	unsigned char state;
	unsigned char cmd;
	unsigned char new_state;
	unsigned char output[2];
};

struct stransition strans[14] = {
	{DEFAULT, SPS, SS, 1, 0},
	{DEFAULT, SPA, AV, 1, 1},			
	{DEFAULT, SPD, SD, 0, 1},
	{SS, SOS, DEFAULT, 0, 0},
	{SS, SPA, SSAV, 1, 1},
	{SD, SOD, DEFAULT, 0, 0},
	{SD, SPA, SDAV, 1, 1},
	{AV, SPS, SSAV, 1, 1},
	{AV, SOA, DEFAULT, 0, 0},
	{AV, SPD, SDAV, 1, 1},
	{SSAV, SOA, SS, 1, 0},
	{SSAV, SOS, AV, 1, 1},
	{SDAV, SOA, SD, 0, 1},
	{SDAV, SOD, AV, 1, 1}
};

unsigned char current_state = DEFAULT; // fost int

unsigned char caracter_receptionat;        // caracterul receptionat pe intrerupere   
unsigned char numarare_timer;
unsigned char semnalizare_stanga, semnalizare_dreapta;
unsigned char cmp_address = 0, data_adress = 0; // fost int

unsigned char acc_level = 0;

unsigned char fanion_timer            = 0;  // avem de tratat un eveniment de timer 
unsigned char fanion_receptie         = 0;  // avem de tratat un eveniment de receptie caracter 
unsigned char validare_ecou           = 0;     // validare transmitere in ecou a caracterului primit 
unsigned char validare_stare_automata = 0;    // validare tramsnmitere automata a starii

unsigned char data_acceleratie = 0;



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

void cautare_comanda(unsigned char comanda) {
	
	// tratare comenzi 1-6
	unsigned char val_acceleratie = 25;
	int i;
	
	// cazu cand data_acc = 0
	PTFD &= 0x81;

	for(i = 0; i < (sizeof(strans)/sizeof(strans[0])); i++) {
		if((strans[i].state == current_state) && (strans[i].cmd == comanda)) {
			current_state = strans[i].new_state;
			semnalizare_stanga = strans[i].output[0];
			semnalizare_dreapta = strans[i].output[1];
			break;
		}
	}
	
	if(comanda == ACA) {
		if(data_acceleratie + val_acceleratie > 255)
			data_acceleratie = 255;
		else data_acceleratie += val_acceleratie;
	}
		
	if(comanda == ASA) {
		if(data_acceleratie - val_acceleratie < 1)
			data_acceleratie = 0;
		else data_acceleratie -= val_acceleratie;
	}
	
	if(comanda == AIA) {
		data_acceleratie = pack.data[0];
	}
	
	if(comanda == PIP) {
		unsigned char sum = 0x00;
		unsigned char pip_size = 0x01;
		sum = (unsigned char)PRI + pip_size + data_acceleratie;
		while(!(SCI1S1 & 0x80)); //asteptam terminare transmisie 
		SCI1D = PRI;
		while(!(SCI1S1 & 0x80));
		SCI1D = pip_size;
		while(!(SCI1S1 & 0x80));
		SCI1D = data_acceleratie;
		while(!(SCI1S1 & 0x80));
		SCI1D = sum;
	}

	 if(data_acceleratie >= 1 && data_acceleratie <= 51)
	    	PTFD |= 0x40;	
	 else if(data_acceleratie >= 52 && data_acceleratie <= 102)
	    	PTFD |= 0x60;
	 else if(data_acceleratie >= 103 && data_acceleratie <= 153)
	    	PTFD |= 0x70;
	 else if(data_acceleratie >= 154 && data_acceleratie <= 204)
	    	PTFD |= 0x78;
	 else if(data_acceleratie >= 205 && data_acceleratie <= 254)
	    	PTFD |= 0x7c;
	 else if(data_acceleratie == 255)
	    	PTFD |= 0x7e;
}

void tratare_seriala() {
    caracter_receptionat = pack.ID;
    cautare_comanda(caracter_receptionat);
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


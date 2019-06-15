# Automotive Main-Board System Simulation (Ro)
HCS08 Microcontrollers Family, MC9S08AW60 Series

## Structuri
### Trimitere pachete de date

```c
struct package {
   unsigned char ID;
   unsigned char size;
   unsigned char data[5];
   unsigned char checksum;
}pack;
```

* ```pack.ID``` este ID-ul comenzii trimise
* ```pack.size``` este lungimea vectorului de date (```pack.data[size]```) din pachetul trimis  
* ```pack.data[..]``` este vectorul de date
* ```pack.checksum``` este calculat ca suma valorilor hex din: ```pack.ID```, ```pack.size```, ```pack.data[..]``` 

### FSM semnalizari
Semnalizarile folosesc **finite state machine** care definesc functionarea acestora  
![fsm](fsm.png)

## Comenzi
#### SEMNALIZARE 
* **SPS** Pornire stanga  
* **SOS** Oprire stanga  
* **SPD** Pornire dreapta  
* **SOD** Oprire dreapta  
* **SPA** Pornire avarie  
* **SOA** Oprire avarie  

#### ACCELERATIE
* **AIA** Impunere acceleratie
* **ACA** Crestere acceleratie
* **ASA** Scadere acceleratie  

#### PARAMETRII
* **PIP** Interogare parametrii -> raspuns cu **PRI**

## Exemple
### Definitii ID comenzi
```c
#define SPS 1  
#define SOS 2  
#define SPD 3  
#define SOD 4  
#define SPA 5  
#define SOA 6  
#define AIA 7
#define ACA 8
#define ASA 9
#define PIP 10
#define PRI 11 (raspuns la PIP)
```

### Exemple pachete de date
Pornire LED stanga (valori hex): ```01 00 01``` -> 01 ```pack.ID```, 00 ```pack.size```, 01 ```pack.checksum```  
Pornire LED-uri avarie (valori hex): ```05 00 05``` -> 05 ```pack.ID```, 00 ```pack.size```, 05 ```pack.checksum```  
Oprire LED-uri dreapta (valori hex): ```04 00 04``` -> 04 ```pack.ID```, 00 ```pack.size```, 04 ```pack.checksum```  
Impunere acceleratie(aprinde toate LED-urile de acceleratie):  ```07 01 ff 07``` -> 07 ```pack.ID```, 01 ```pack.size```, ff ```pack.data[0]```, 07 ```pack.checksum```    
Interogare parametrii:  ```10 00 10``` -> 10 ```pack.ID```, 00 ```pack.size```, 10 ```pack.checksum``` 

(in cazurile cand se lucreaza cu semnalizarile, LED-urile vor fi aprinse 60% dintr-o secunda si vor fi stinse in rest)


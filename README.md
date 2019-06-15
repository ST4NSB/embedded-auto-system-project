# Automotive Main-Board System Simulation (Ro)
HCS08 Microcontrollers Family, MC9S08AW60 Series

## Structura
Foloseste pachete de date implementate printr-o structura C

```c
struct package {
   unsigned char ID;
   unsigned char size;
   unsigned char data[5];
   unsigned char checksum;
}pack;
```

* ```pack.size``` este lungimea vectorului de date (```pack.data[size]```) din pachetul trimis  
* ```pack.checksum``` este calculat ca suma valorilor hex din: ```pack.ID```, ```pack.size```, ```pack.data[..]``` 

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
#define PRI 11
```

### Exemple pachete de date
Pornire LED stanga (valori hex): ```01 00 01``` -> 01 ```pack.ID```, 00 ```pack.size```, 01 ```pack.checksum```  
Pornire LED-uri avarie (valori hex): ```05 00 05``` -> 05 ```pack.ID```, 00 ```pack.size```, 05 ```pack.checksum```  
Oprire LED-uri dreapta (valori hex): ```04 00 04``` -> 04 ```pack.ID```, 00 ```pack.size```, 04 ```pack.checksum```  
Impunere acceleratie(aprinde toate LED-urile de acceleratie):  ```07 01 ff 07``` -> 07 ```pack.ID```, 01 ```pack.size```, ff ```pack.data[0]```, 07 ```pack.checksum```    

(in cazurile cand se lucreaza cu LED-ul, acesta va fi aprins 60% dintr-o secunda si va fi stins in rest)


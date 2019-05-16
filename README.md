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
### 1. Semnalizare 
* **SPS** Pornire stanga  
* **SOS** Oprire stanga  
* **SPD** Pornire dreapta  
* **SOD** Oprire dreapta  
* **SPA** Pornire avarie  
* **SOA** Oprire avarie

## Exemple
### Definitii ID comenzi
```c
#define SPS 1  
#define SOS 2  
#define SPD 3  
#define SOD 4  
#define SPA 5  
#define SOA 6  
```

### Exemple pachete de date
Pornire LED stanga (valori hex): ```01 00 01``` -> 01 ```pack.ID```, 00 ```pack.size```, 01 ```pack.checksum```  
Pornire LED-uri avarie (valori hex): ```05 00 05``` -> 05 ```pack.ID```, 00 ```pack.size```, 05 ```pack.checksum```  
Oprire LED-uri dreapta (valori hex): ```04 00 04``` -> 04 ```pack.ID```, 00 ```pack.size```, 04 ```pack.checksum```  

(in cazurile cand se lucreaza cu LED-ul, acesta va fi aprins 60% dintr-o secunda si va fi stins in rest)


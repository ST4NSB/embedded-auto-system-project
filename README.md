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

* ```pack.size``` este lungimea vectorului de date care trebuie procesat (```pack.data[size]```)   
* ```pack.checksum``` este calculat ca suma valorilor hex: ```pack.ID```, ```pack.size```, ```pack.data[..]``` 


## Comenzi
1.### Semnalizare 
* **SPS** Pornire stanga  
* **SOS** Oprire stanga  
* **SPD** Pornire dreapta  
* **SOD** Oprire dreapta  
* **SPA** Pornire avarie  
* **SOA** Oprire avarie   

## Exemple

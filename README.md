# Embedded System - Automotive Main-Board System Simulation  
HCS08 Family,
MC9S08AW60 Series

## Structure

Uses package implementation with struct

```c
struct package {
	unsigned char ID;
	unsigned char size;
	unsigned char data[5];
	unsigned char checksum;
}pack;
```

where ```pack.size``` is the size of incoming data values (```pack.data[size]```)   
& ```pack.checksum``` is calculated as the sum of the hex values of ```pack.ID```, ```pack.size```, ```pack.data[..]```

## Instructions


## Examples

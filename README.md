# embedded-auto-system-project
HCS08 Family,
MC9S08AW60 Series

Uses package implementation with struct

```c
struct package {
	unsigned char ID;
	unsigned char size;
	unsigned char data[5];
	unsigned char checksum;
}pack;
```

where ```c pack.size``` is the size of incoming data values (```c pack.data[size]```)   
& ```c pack.checksum``` is calculated as the sum of the hex values of ```c pack.ID```, ```c pack.size```, ```c pack.data[..]```

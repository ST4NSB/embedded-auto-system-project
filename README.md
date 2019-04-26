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


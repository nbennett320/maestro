#include "io.h"

// write a byte to aspecified port
void outb(u16 port, u8 value)
{
	asm("outb %1, %0" : : "dN" (port), "a" (value));
}

// reads a byte from a specified port
u8 inb(u16 port)
{
	u8 val;
	asm("inb %1, %0" : "=a" (val) : "dN" (port));
	return val;
}

// reads 2 bytes from a specified port
u16 inw(u16 port)
{
	u16 val;
	asm("inw %1, %0" : "=a" (val) : "dN" (port));
	return val;
}
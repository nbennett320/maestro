/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Sam Kravitz
 *
 * FILE: idt.h
 * DATE: August 1st, 2021
 * DESCRIPTION: Initialize the IDT and store it in idtr
 */
#include "idt.h"
#include "klog.h"
#include "string.h"

struct idt_entry idt[NUM_IDT_ENTRIES];

static void set_idt(int, u32, u16, u8);
static void lidt();

void idt_init()
{
	memset(idt, 0, sizeof(idt));
    for (int i = 0; i < 32; ++i)
        set_idt(i, (u32) isrtab[i], 0x8, 0x8E);

    lidt();
}

// lidt - stores idt structure in idtr
static void lidt()
{
    struct idtr
    {
        u16 limit;
        u32 base;
    } __attribute__((packed)) idtr;

    idtr.limit = sizeof(idt) - 1;
    idtr.base = (u32) &idt;

    __asm volatile ("lidt %0" : : "m" (idtr));
}

// set_idt - initializes a gate in the idt
static void set_idt(int num, u32 base, u16 select, u8 flags)
{
	idt[num].offlow   = (base >> 0)  & 0xFFFF;
    idt[num].offhigh  = (base >> 16) & 0xFFFF;
	idt[num].selector = select;
	idt[num].type     = (flags >> 0) & 0xF;
	idt[num].sseg     = (flags >> 4) & 0x1;
	idt[num].dpl      = (flags >> 5) & 0x3;
	idt[num].present  = (flags >> 7) & 0x1;
    idt[num].zero     = 0;
} 

void handler()
{
    klog("Interrupt handled!\n");
}
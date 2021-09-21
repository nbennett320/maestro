/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Sam Kravitz
 *
 * FILE: kmain.c
 * DATE: July 26, 2021
 * DESCRIPTION: Where it all begins
 */
#include <init.h>
#include <intr.h>
#include <kout.h>
#include <proc.h>
#include <kmalloc.h>

// #include <msh.h>

#include "string.h"

#include "msl.h"

extern struct proc *curr;
extern struct proc nullproc;

void kmain()
{
	kout("Welcome to maestro!\n");
	init();

	curr = &nullproc;

	// enable interrupts
	asm("sti");

	int r = test();

	// run();

	// become the null process
	while (1)
		asm("hlt");
}

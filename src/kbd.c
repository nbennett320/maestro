/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Sam Kravitz
 *
 * FILE: kbd.c
 * DATE: August 2nd, 2021
 * DESCRIPTION: Driver for PS/2 keyboard
 */
#include <kbd.h>

#include <intr.h>
#include <io.h>
#include <kout.h>

#include "stdlib.h"

static u32 state = 0;

void kbdhandler()
{
	u8 scancode = inb(KBD_IN);

	char c = '\0';
	if (scancode < NUM_KEYS)
		c = kbdus[scancode];

	switch (scancode)
	{
		// left shift pressed
		case LSHIFT_IDX:
			state |= LSHIFT;
			break;
		
		// left shift released
		case LSHIFT_IDX + 0x80:
			state &= ~LSHIFT;
			break;
		
		// right shift pressed
		case RSHIFT_IDX:
			state |= RSHIFT;
			break;
		
		// right shift released
		case RSHIFT_IDX + 0x80:
			state &= ~RSHIFT;
			break;
	}

	if (is_alpha(c) && PRESSED(LSHIFT | RSHIFT))
		c = to_upper(c);

	kprintf("%c", c);
}

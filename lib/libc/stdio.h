/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Sam Kravitz
 *
 * FILE: libc/stdio.h
 * DATE: August 30, 2021
 * DESCRIPTION: standard input/output utilities 
 */
#ifndef STDIO_H
#define STDIO_H

#include <maestro.h>

#define STDIO_H_GETCHAR_BUFFSIZE 1024

u32 EOF;

// ugh, I hate typedef...
// yeah.. me too..
typedef struct
{
	char name[32];
	size_t len;
	u32 eof;
	u32 position;
	int fd;
} FILE;

/**
 *  
 */
getchar(void);

#endif // STDIO_H

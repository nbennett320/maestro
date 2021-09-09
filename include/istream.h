/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: istream.h
 * DATE: Sept 9, 2021
 * DESCRIPTION: input streams
 */

#ifndef ISTREAM_H
#define ISTREAM_H

#include <maestro.h>

#define CHAR_ISTREAM_SIZE 1024

extern char *istream;

void istreaminit(void);
void istream_write(char, u32 size);
char *istream_read(void);
char istream_read_curr(void);
void istream_handle_bksp(void);
void print_stream();

#endif // ISTREAM_H

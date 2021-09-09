/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: libc/stdio.c
 * DATE: Sept 9, 2021
 * DESCRIPTION: standard input/output utilities 
 */

#include "./stdio.h"

// char getchar() {
//   char buffer[STDIO_H_GETCHAR_BUFFSIZE];
//   char *i_am = buffer;
//   s16 index = 0;

//   if(index == 0) {
//     index = read(0, buffer, 1);
//     i_am = buffer;
//   }

//   if(--index >= 0) {
//     return *i_am++;
//   }

//   return EOF;
// }

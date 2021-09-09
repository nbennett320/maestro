/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: msh.h
 * DATE: Sept. 03, 2021
 * DESCRIPTION: header file for MSH (Maestro's SHell)
 */

#include "./msh.h"
#include <stdio.h>
#include <kout.h>
#include <kmalloc.h>

// void run() {
//   char *line;
//   char **argv;
//   s16 running;

//   kprintf("> ");
//   line = read_line();
//   argv = parse_line();
//   running = exec(argv);

//   while(running) {
//     kprintf("> ");
//     line = read_line();
//     argv = parse_line();
//     running = exec(argv);
//     kfree(line);
//     kfree(argv);
//   }
// }

// char *read_line() {
//   u16 size = MSH_INPUT_BUFFER_SIZE;
//   s16 index = 0;
//   char *buffer = kmalloc(sizeof(char) * size);
//   char ch;

//   // check for malloc error
//   if(!buffer) {
//     kprintf("kmalloc error");
//     exit(1);
//   }

//   for(;;) {
//     ch = getchar();
//   }
// }

/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: msh.h
 * DATE: Sept. 03, 2021
 * DESCRIPTION: header file for MSH (Maestro's SHell)
 */

#ifndef MSH_H
#define MSH_H

#define MSH_INPUT_BUFFER_SIZE 1024

// run the shell
void run(void);

char *read_line(void);

#endif // MSH_H
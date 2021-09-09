/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: istream.c
 * DATE: Sept 9, 2021
 * DESCRIPTION: input streams
 */

#include <istream.h>
#include <kmalloc.h>
#include <kout.h>
#include <string.h>
#include <lexae.h>

// initialize stream to null
extern char *istream = NULL;
s16 stream_index = 0;

void istreaminit() {
  istream = kmalloc(sizeof(char) * CHAR_ISTREAM_SIZE);
}

void istream_write(char ch_stream, u32 size) {
	// kprintf("write: %c, index: %d\n", ch_stream, stream_index);
  stream_index++;
  istream[stream_index] = ch_stream;
  kprintf("word is: ");
  print_stream();
  char **tokens = tokenize(istream, ' ');
}

char *istream_read() {
  return *istream;
}

char istream_read_curr() {
  return istream[stream_index];
}

// handle backspace
void istream_handle_bksp() {
  if(stream_index > 0) {
    istream[stream_index] = NULL;
    stream_index--;
  }
  kprintf("word is: ");
  print_stream();
}

// print stream (for debugging)
void print_stream() {
  for(int i = 0; i < stream_index; i++) {
    kprintf("%c", istream[i+1]);
  }
  kprintf("\n");
}


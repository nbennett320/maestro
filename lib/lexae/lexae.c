/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: lexae.c
 * DATE: Sept 9, 2021
 * DESCRIPTION: lexer
 */

#include <lexae.h>
#include <kmalloc.h>
#include <kout.h>
#include <string.h>

char **tokenize(char *str, char delim) {
  char **token_arr = kmalloc(sizeof(char) * TOKEN_BUFFER_SIZE);
  s16 n_tokens = 0;

  if(!token_arr) {
    kprintf("error kmallocing");
    return NULL;
  }

  int from = 0, to = strlen(str);
  for(int i = 0; str[i] != NULL; i++) {
    for(int j = from; j < to; j++) {
      if((str[j] != NULL) && (str[j] == delim)) {
        kprintf("found a delimiter %c at %d\n", delim, from);
        // handle set token
        s16 len = to - from;
        char *token = kmalloc(sizeof(char) * len);
        for(int k = 0; k < len; k++) {
          u16 n = from + k;

          if(n > to) {
            kprintf("n in token too big, breaking\n");
            break;
          }

          if(str[n] == NULL) {
            kprintf("str[n] was null, breaking\n");
            return NULL;
          }

          token[k] = str[n];
        }
        token_arr[i] = token;
        n_tokens++;
        from = j;
      }
    }
  }

  return token_arr;
}

s16 count_tokens(char *str, char delim) {
  u16 n = 0;
  s16 count = 0;

  while(str[n] != NULL) {
    if(str[n] == delim) count++;  
    n++;
  }

  return count;
}

// list tokens for debugging
void print_tokens(char **token_arr, s16 n_tokens) {
  for(int i = 0; i < n_tokens; i++) {
    char *token = token_arr[i];
    s16 len = strlen(token);
    kprintf("token %d: ",i);
    for(int j = 0; j < len; j++) {
      kprintf("%c", token[i+1]);
    }
    kprintf("\n");
  }
}

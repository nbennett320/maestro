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
  for(int i = from; i < to; i++) {
    if((str[i] != NULL) && (str[i] == delim)) {
      // kprintf("found a delimiter %c at %d\n", delim, i);
      // handle set token
      s16 len = i - from;
      char *token = kmalloc(sizeof(char) * len);
      for(int j = 0; j < len; j++) {
        u16 n = from + j;

        if(n > to) {
          kprintf("n in token too big, breaking\n");
          break;
        }

        if(str[n] == NULL) {
          kprintf("str[n] was null, breaking\n");
          return NULL;
        }

        token[j] = str[n];
      }
      token_arr[n_tokens] = token;
      n_tokens++;
      from = i;
    }
  }

  return token_arr;
}

s16 count_tokens(char *str, char delim) {
  u16 n = 0;
  s16 count = 0;

  if(!str) {
    return NULL;
  }

  count++;
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
    print_token(token);
    kprintf("\n");
  }
}

void print_token(char *token) {
  s16 len = strlen(token);
  for(int i = 0; i < len; i++) {
    kprintf("%c", token[i+1]);
  }
}

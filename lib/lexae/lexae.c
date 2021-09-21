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
  s16 n_tokens = count_tokens(str, delim);
  s16 remaining_tokens = n_tokens - 1;
  char **token_arr = kmalloc(sizeof(char *) * TOKEN_BUFFER_SIZE * n_tokens);

  if(!token_arr) {
    kprintf("error kmallocing");
    return NULL;
  }

  int from = 0, to = strlen(str), len = to - from, tok_i = 0;
  while(remaining_tokens) {
    to = charfind(str, delim, from);
    char *token = kmalloc(sizeof(char) * len);
    token = substr(str, from, to);
    
    if(!token) {
      kprintf("token was null :/\n");
      return NULL;
    }

    from = to;
    token_arr[tok_i] = token;
    remaining_tokens--;
    tok_i++;
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

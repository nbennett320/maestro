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
        kprintf("found a delimiter %c at %d", delim, from);
        // handle set token
        s16 len = to - from;
        char *token = kmalloc(sizeof(char) * len);
        for(int k = 0; k < len; k++) {
          u16 n = from + k;

          if(n > to) {
            kprintf("n in token too big, breaking");
            break;
          }

          if(str[n] == NULL) {
            kprintf("str[n] was null, breaking");
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

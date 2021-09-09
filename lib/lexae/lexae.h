/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Noah Bennett
 *
 * FILE: lexae.h
 * DATE: Sept 9, 2021
 * DESCRIPTION: lexer
 */

#ifndef LEXAE_H
#define LEXAE_H

#include <maestro.h>
#include <istream.h>

#define TOKEN_BUFFER_SIZE 256

/**
 * tokenizer, returns an array of strings/char arrays
 * @param str string to tokenize
 * @param delim char to use as delimiter
 */
char **tokenize(char *, char);
s16 count_tokens(char *, char);
void print_tokens(char **, s16);
void print_token(char *);

#endif // LEXAE_H

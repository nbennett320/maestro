/* maestro
 * License: GPLv2
 * See LICENSE.txt for full license text
 * Author: Sam Kravitz
 *
 * FILE: libc/string.c
 * DATE: July 27, 2021
 * DESCRIPTION: memcmp, memcpy, memset, strcat, strncat, strlen
 */

#include "string.h"

// compares n bytes of s1 with s2
// returns:
//   <0 if s1 < s2
//   >0 if s1 > s2
//   =0 if s1 = s2
int memcmp(const void *s1, const void *s2, size_t n)
{
	const char *a = (const char *) s1;
	const char *b = (const char *) s2;

	while (n--)
	{
		if (*a < *b)
			return -1;
		else if (*a > *b)
			return 1;

		a++;
		b++;
	}

	return 0;
}

// copies n bytes of memory from src to dest
void *memcpy(void *dest, const void *src, size_t n)
{
	char *dp = (char *) dest;
	const char *sp = (const char *) src;

	while (n--)
		*dp++ = *sp++;

	return dest;
}

// copy memory area
void *memmove(void *dest, const void *src, size_t n)
{
	char *dp = (char *) dest;
	const char *sp = (const char *) src;

	if (dest == src)
		return dest;
	
	// copy from end
	if (src < dest)
	{
		while (n--)
			dp[n - 1] = sp[n - 1];
	}

	// copy from beginning (basically just memcpy)
	else
	{
		while (n--)
			*dp++ = *sp++;
	}

	return dest;
}

// sets n bytes of ptr to c
void *memset(void *ptr, int c, size_t n)
{
	char *p = (char *) ptr;

	while (n--)
		*p++ = c;

	return ptr;
}

char *strcat(char *dest, const char *src)
{
	size_t i = 0, len = strlen(dest);
	
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}

	dest[i + len] = '\0';

	return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
	size_t i = 0, len = strlen(dest);
	
	while (src[i] && n--)
	{
		dest[i + len] = src[i];
		i++;
	}

	dest[i + len] = '\0';

	return dest;
}

char *strcpy(char *dest, const char *src)
{
	size_t len = strlen(src);
	memcpy(dest, src, len);
	dest[len] = '\0';
	return dest;
}

// compute the length of a null-terminated string
size_t strlen(const char *str)
{
	size_t len = 0;
	while (*str++)
		len++;

	return len;
}

// O(n) basic find for string, return index of char
int charfind(char *str, char ch, int start) {
	if(!str) return NULL;
	if(strlen(str) < start) return NULL;
	if(start < 0) return NULL;

	for(int i = start; i < strlen(str); i++) {
		if((str[i] != NULL) && (str[i] == ch)) {
			kprintf("ch found at %d\n",i);
			return i;
		}

		if(str[i] == NULL) {
			kprintf("str[%d] null\n",i);
			return NULL;
		}
	}
	kprintf("not found\n");
	return -1;
}

// find substring with from, to
char *substr(char *str, int from, int to) {
	if(!str) {
		kprintf("null string\n");
		return NULL;
	}
	if(from < 0) {
		kprintf("from < 0\n");
		return NULL;
	}
	if(from > to) {
		kprintf("from > to\n");
		return NULL;
	}
	if(to < 0) {
		kprintf("to < 0\n");
		return NULL;
	}
	if((to - from) <= 0) {
		kprintf("to - from < 0\n");
		return NULL;
	}

	char *substr = kmalloc(sizeof(char) * (to - from));
	u16 stri = 0;
	for(int i = from; i < to; i++) {
		if(!str[stri]) {
			kprintf("str stri is null\n");
			return NULL;
		}

		substr[stri] = str[i];
		stri++;
	}
	substr[stri] = NULL;

	return substr;
}

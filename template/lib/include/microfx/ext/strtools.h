#ifndef MICROFX_STRTOOLS_H
#define MICROFX_STRTOOLS_H

/* Some string.h functions */

/* int memcmp(void const *__s1, void const *__s2, size_t __n);

Compares the __n first bytes of __s1 and __s2.
Returns
- 0 if they are equal
- a number <0 if the first unsigned char that is diffrent is smaller in __s1
  than in __s2.
- a number >0 if the first unsigned char that is diffrent is bigger in __s1 than
  in __s2.
*/

int memcmp(void const *__s1, void const *__s2, size_t __n);

/* void *memcpy(void *__dest, void const *__src, size_t __n);

Copy __n first bytes from __src to __dest.
Returns __s1.
*/

void *memcpy(void *__dest, void const *__src, size_t __n);

/* void *memset(void *__s, int __c, size_t __n);

Fills __n first bytes of __s with __c (note that __c is converted to an unsigned
char).
__s is returned.
Overlapping is not allowed.
*/

void *memset(void *__s, int __c, size_t __n);

/* char *strcat(char *__dest, char const *__src);

Copies __src to the end of __dest. The \0 at the end of __dest will be
overwritten, and \0 will be appended at the end of the __dest.
Returns __dest.
*/

char *strcat(char *__dest, char const *__src);

/* int strcmp(char const *__s1, char const *__s2);

Compares __s1 and __s2.
Returns
- 0 if they are equal
- a number <0 if the first char that is diffrent is smaller in __s1 than in
  __s2.
- a number >0 if the first char that is diffrent is bigger in __s1 than in __s2.
*/

int strcmp(char const *__s1, char const *__s2);

/* size_t strlen(char const *__s);

Returns the size of the null-terminated string __s, whitout counting the \0.
*/

size_t strlen(char const *__s);

/* char *strncat(char *__dest, char const *__src, size_t __n);

Copies the first __n chars of __src to the end of __dest. The \0 at the end of
__dest will be overwritten, and \0 will be appended at the end of the __dest. If
__n is bigger than the size of the string, only the chars up to the \0 will be
copied.
Returns __dest.
*/

char *strncat(char *__dest, char const *__src, size_t __n);

/* int strncmp(char const *__s1, char const *__s2, size_t __n);

Compares the __n first char of __s1 and __s2.
Returns
- 0 if they are equal
- a number <0 if the first char that is diffrent is smaller in __s1 than in
  __s2.
- a number >0 if the first char that is diffrent is bigger in __s1 than in __s2.
  If __n is bigger than the size of one of the string, only the chars up to the \0
  will be copied.
*/

int strncmp(char const *__s1, char const *__s2, size_t __n);

/* char *strncpy(char *__dest, char const *__src, size_t __n);

Copy __n first bytes from __src to __dest. No \0 is appended at the end of
__dest. If __src is smaller than __n, __dest will be filled with \0 until __n is
reached.
Returns __s1.
*/

char *strncpy(char *__dest, char const *__src, size_t __n);

/* char *strrchr(char const *__s, int __c);

Returns a pointer to the last occurence of __c in __s. The \0 at the end of __s
is included.
*/

char *strrchr(char const *__s, int __c);

/* char *strchr(char const *__s, int __c);

Returns a pointer to the first occurence of __c in __s. The \0 at the end of __s
is included.
*/

char *strchr(char const *__s, int __c);

/* char *strstr(char const *__s1, char const *__s2);

Returns a pointer to the first occurence of __s2 in __s1, or NULL if there was
no one. The \0 at the end of the strings is not included.
*/

char *strstr(char const *__s1, char const *__s2);

/* void *memmove(void *__dest, void const *__src, size_t __n);

Copies the __n first bytes of __src to __dest, but __src and __dest can overlap.
__dest is returned.
*/

void *memmove(void *__dest, void const *__src, size_t __n);

#endif

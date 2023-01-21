/* Some string.h functions */

/* /!\ TODO : Add doc. /!\ */

int memcmp(void const *__s1, void const *__s2, size_t __n);
void *memcpy(void *__dest, void const *__src, size_t __n);
void *memset(void *__s, int __c, size_t __n);
char *strcat(char *__dest, char const *__src);
int strcmp(char const *__s1, char const *__s2);
size_t strlen(char const *__s);
char *strncat(char *__dest, char const *__src, size_t __n);
int strncmp(char const *__s1, char const *__s2, size_t __n);
char *strncpy(char *__dest, char const *__src, size_t __n);
char *strrchr(char const *__s, int __c);
char *strchr(char const *__s, int __c);
char *strstr(char const *__s1, char const *__s2);
void *memmove(void *__dest, void const *__src, size_t __n);
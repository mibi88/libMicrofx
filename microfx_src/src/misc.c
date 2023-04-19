#include "../include/microfx/microfx.h"

/******* Tools *******/

/* Syscalls */

int _LongToAscHex(int value, char *dest, int digits);

/* Microfx */

void itohex(char *buffer, int value, int len) {
	_LongToAscHex(value, buffer, len);
}

/******* CPU *******/

/* Microfx */

void csleep(void) {
	__asm__("sleep");
}

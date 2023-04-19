#include "../include/microfx/microfx.h"

/******* GUI *******/

/* Syscalls */

int _InputNumber(unsigned char *heading, int maxlen, int mode);
int _InputString(unsigned char *buffer, unsigned char *heading, int maxlen);
void _DisplayFKeyIcon(int FKeyPos, unsigned char *pBitmap);

/* Microfx */

int gnumask(char *message, int maxlen, int type) {
	return _InputNumber((unsigned char *)message, maxlen, type);
}

void gstrask(char *buffer, char *message, int maxlen) {
	_InputString((unsigned char *)buffer, (unsigned char *)message, maxlen);
}

void gfkeyset(int pos, unsigned char *img) {
	_DisplayFKeyIcon(pos, img);
}

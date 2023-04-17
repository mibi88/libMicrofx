#include "../include/microfx/microfx.h"

/******* KEYBOARD *******/

/* Syscalls */

int _Keyboard_KeyDown(void);
int _Keyboard_PRGM_GetKey(unsigned char* buffer);

/* Microfx */

int kisdown(void) {
	return _Keyboard_KeyDown();
}

int kcheck(int key) {
	/* TODO : Compatibility with older calcs. */
	/* Get the column and the row of the key. */
	int row = key%10;
	int column = key/10 - 1;
	/* The bit that I will read in the KIUDATA
	register. */
	int column_pos = column + 8 * (row & 1);
	/* row_data will contain the data of the
	KIUDATA register that we need.
	keyboard_register contains the address of
	KIUDATA0. */
	unsigned short *keyboard_register = (unsigned short*)0xA44B0000;
	unsigned short row_data;
	/* Get KIUDATAx where x is row / 2 because two rows
	are stored in each KIUDATA register. */
	row_data = keyboard_register[row/2];
	/* Get the bit located at column. */
	return (row_data >> column_pos) & 1;
}

int kgetkey(void){
	unsigned char buffer[12];
	_Keyboard_PRGM_GetKey(buffer);
	return (buffer[1] & 0x0F) * 10 + ((buffer[2] & 0xF0 ) >> 4);
}

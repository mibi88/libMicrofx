#include "../include/microfx/microfx.h"

/******* DISPLAY *******/

/* Syscalls */

void _Bdisp_PutDisp_DD(void);
void _Bdisp_DrawRectangle(int x1, int y1, int x2, int y2);
void _Bdisp_AllClr_VRAM(void);
void _Bdisp_SetPoint_VRAM(int x, int y, int color);
void _PrintXY(int x, int y, unsigned char *text, int type);
void _locate(int x, int y);
void _Print(unsigned char *text);

/* Microfx */

void sclear() {
	_Bdisp_AllClr_VRAM();
}

void supdate() {
	_Bdisp_PutDisp_DD();
}

void spixel(int x, int y, int color) {
	_Bdisp_SetPoint_VRAM(x, y, color);
}

void srect(int x1, int y1, int x2, int y2) {
	_Bdisp_DrawRectangle(x1, y1, x2, y2);
}

void stext(int x, int y, char *text) {
	_PrintXY(x, y, (unsigned char*)text, 0);
}

void slocate(int x, int y, char *text) {
	_locate(x, y);
	_Print((unsigned char*)text);
}

/******* KEYBOARD *******/

/* Syscalls */

short _Keyboard_GetPressedTime(void);
int _Keyboard_IsKeyPressed_fast(short *matrixcode);
int _Keyboard_IsKeyPressed(short *matrixcode);
int _Keyboard_KeyDown(void);
int _Keyboard_PRGM_GetKey(unsigned char* buffer);

/* Microfx */

int kisdown(void) {
	return _Keyboard_KeyDown();
}

int kcheck(int key, int type) {
	short skey = (short)key;
	switch(type){
		case KFAST:
			return _Keyboard_IsKeyPressed_fast(&skey);
			break;
		default:
			return _Keyboard_IsKeyPressed(&skey);
			break;
	}
}

int kgetkey(void){
	unsigned char buffer[12];
	_Keyboard_PRGM_GetKey(buffer);
	return (buffer[1] & 0x0F) * 10 + ((buffer[2] & 0xF0 ) >> 4);
}

/******* Time *******/

/* Syscalls */

void _Sleep(int delay_ms);
int _RTC_GetTicks(void);
int _RTC_Elapsed_ms(int start_value, int duration_in_ms);

/* Microfx */

void tsleep_ms(int ms) {
	_Sleep(ms);
}


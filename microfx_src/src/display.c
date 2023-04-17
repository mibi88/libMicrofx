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
void _Bdisp_DrawLineVRAM(int x1, int y1, int x2, int y2);
void _Bdisp_ClearLineVRAM(int x1, int y1, int x2, int y2);
void _PrintMiniSd(int x, int y, unsigned char *text, int color);
void _DisplayMessageBox(int height, unsigned char *message);

/* Microfx */

void sclear() {
	_Bdisp_AllClr_VRAM();
}

void supdate() {
	_Bdisp_PutDisp_DD();
}

void spixel(int x, int y, int color) {
	if(x>=0 && x<SWIDTH && y>=0 && y<SHEIGHT){
		_Bdisp_SetPoint_VRAM(x, y, color);
	}
}

void srect(int x1, int y1, int x2, int y2) {
	_Bdisp_DrawRectangle(x1, y1, x2, y2);
}

void sline(int x1, int y1, int x2, int y2, int color) {
	if(color){
		_Bdisp_DrawLineVRAM(x1, y1, x2, y2);
	}else{
		_Bdisp_ClearLineVRAM(x1, y1, x2, y2);
	}
}

void stext(int x, int y, char *text, int color) {
	_PrintXY(x, y, (unsigned char*)text, !color);
}

void slocate(int x, int y, char *text) {
	_locate(x, y);
	_Print((unsigned char*)text);
}

void saddlocate(char *text) {
	_Print((unsigned char*)text);
}

void sgoto(int x, int y) {
	_locate(x, y);
}

void stextmini(int x, int y, char *text) {
	_PrintMiniSd(x, y, (unsigned char*)text, 0);
}

void gmessagebox(int height, char *message) {
	_DisplayMessageBox(height, (unsigned char*)message);
}

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

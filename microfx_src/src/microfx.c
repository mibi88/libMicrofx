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

/******* Tools *******/

/* Syscalls */

int _LongToAscHex(int value, char *dest, int digits);

/* Microfx */

void itohex(char *buffer, int value, int len) {
	_LongToAscHex(value, buffer, len);
}

/******* Time *******/

/* Syscalls */

void _Sleep(int delay_ms);
int _RTC_GetTicks(void);
int _RTC_Elapsed_ms(int start_value, int duration_in_ms);
void _RTC_Reset(unsigned int mode);

int _Timer_Install(int InternalTimerID, void (*handler)(void), int elapse);
int _Timer_Deinstall(int InternalTimerID);
int _Timer_Start(int InternalTimerID);
int _Timer_Stop(int InternalTimerID);

/* Microfx */

void tsleep_ms(int ms) {
	_Sleep(ms);
}

int tgetticks(void) {
	return _RTC_GetTicks();
}

int tiselapsed(int start, int ms) {
	return _RTC_Elapsed_ms(start, ms);
}

void treset(void) {
	_RTC_Reset(1);
}

int tinittimer(int ms, void (*callback)(void)) {
	return _Timer_Install(0, callback, ms);
}

void tfreetimer(int id) {
	_Timer_Deinstall(id);
}

void tstarttimer(int id) {
	_Timer_Start(id);
}

void tstoptimer(int id) {
	_Timer_Stop(id);
}

/******* CPU *******/

/* Microfx */

void csleep(void) {
	__asm__("sleep");
}

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

/******* Memory *******/

const unsigned short int fname_start[7] = {'\\', '\\', 'f','l','s','0','\\'};

/* Syscalls */

int _Bfile_DeleteEntry(const unsigned short int *filename);
int _Bfile_Create(const unsigned short int *filename, int type, int *size);
int _Bfile_Write(int fd, const void *data, int size);
int _Bfile_Open(const unsigned short int *filename, int mode);
int _Bfile_Read(int fd, void *data, int size, int whence);
int _Bfile_Close(int fd);

/* Microfx */

extern int fugue;

int mfugue(void) {
	return fugue;
}

unsigned short int fname[PATHSIZELIMIT];

void _fixname(const char *filename) {
	int len, i;
	len = 0;
	while(filename[len] != '\0' && len < PATHSIZELIMIT){
		len++;
	}
	for(i=0;i<PATHSIZELIMIT;i++){
		fname[i] = '\0';
	}
	for(i=0;i<7;i++){
		fname[i] = fname_start[i];
	}
	for(i=0;i<len;i++){
		if(filename[i+1] != '/'){
			fname[i+7] = filename[i+1];
		}else{
			fname[i+7] = '\\';
		}
	}
}

int mremove(const char *filename) {
	_fixname(filename);
	_Bfile_DeleteEntry(fname);
	return 0;
}

int mcreate(const char *filename, int type, int size) {
	int out;
	_fixname(filename);
	out = _Bfile_Create(fname, type, &size);
	return out;
}

int mopen(const char *filename, int mode) {
	int out;
	_fixname(filename);
	out = _Bfile_Open(fname, mode);
	return out;
}

int mwrite(int fd, const void *data, int size) {
	int out;
	if(!fugue){
		if(size%2) return -1;
	}
	out = _Bfile_Write(fd, data, size);
	if(out < 0) return out-1;
	return 0;
}

int mread(int fd, void *data, int size, int whence) {
	int out;
	out = _Bfile_Read(fd, data, size, whence);
	return out;
}

int mclose(int fd) {
	return _Bfile_Close(fd);
}

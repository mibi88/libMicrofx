#include "../include/microfx/microfx.h"

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

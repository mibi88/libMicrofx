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
int _BFile_Size(int fd);

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

MFile mopen(const char *filename, int mode) {
    MFile file;
	_fixname(filename);
	file.out = _Bfile_Open(fname, mode);
    if(file.out > 0){
        file.fd = file.out;
        file.error = 0;
        file.fpos = 0;
    }else{
        file.error = 1;
    }
    return file;
}

void mwrite(MFile *file, const void *data, int size) {
	if(!fugue && size%2){
        file->error = 1;
        file->out = 1;
		return;
	}
	file->out = _Bfile_Write(file->fd, data, size);
	if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mread(MFile *file, void *data, int size, int whence) {
    if(whence == MRCONTINUE) whence = file->fpos;
	file->out = _Bfile_Read(file->fd, data, size, whence);
    file->fpos += size;
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mclose(MFile *file) {
	file->out = _Bfile_Close(file->fd);
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mseek(MFile *file, int pos) {
    file->fpos = pos;
    file->error = 0;
    file->out = 0;
}

void msize(MFile *file) {
    file->out = _BFile_Size(file->fd);
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

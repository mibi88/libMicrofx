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
int _Bfile_Size(int fd);

/* Microfx */

extern int fugue;

int mfugue(void) {
	return fugue;
}

unsigned short int fname[PATHSIZELIMIT];

void _fixname(const char *filename) {
	int len, i;
	len = 0;
	/* Getting the lenght of the filename */
	while(filename[len] != '\0' && len < PATHSIZELIMIT){
		len++;
	}
	/* Clearing fname, the file name for Bfile. */
	for(i=0;i<PATHSIZELIMIT;i++){
		fname[i] = '\0';
	}
	/* Copying the start of a Bfile file name to fname */
	for(i=0;i<7;i++){
		fname[i] = fname_start[i];
	}
	/* Copying the file name to fname, slashs are also replaced by backslashs */
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
	return _Bfile_DeleteEntry(fname);
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
		file.fwpos = 0;
    }else{
        file.error = 1;
    }
    return file;
}

void mwrite(MFile *file, const void *data, int size) {
	/* Some checks to make the operation more secure. */
	if(!fugue && size%2){
        file->error = MODDSIZEWRITE;
        file->out = 1;
		return;
	}
	msize(file);
	if(file->fwpos + size > file->out && !file->error){
		file->out = MTOOBIGSIZE;
		file->error = 1;
		return;
	}
	/* Calling the Bfile syscall and updating the MFile struct. */
	file->out = _Bfile_Write(file->fd, data, size);
	file->fpos += size;
	file->fwpos += size;
	if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mread(MFile *file, void *data, int size, int whence) {
	/* Making an absolute position out of whence. */
    if(whence == MRCONTINUE) whence = file->fpos;
	/* A check to make the operation more secure. */
	msize(file);
	if(whence + size > file->out && !file->error){
		file->out = MTOOBIGSIZE;
		file->error = 1;
		return;
	}
	/* Calling the Bfile syscall and updating the MFile struct. */
	file->out = _Bfile_Read(file->fd, data, size, whence);
    file->fpos += size;
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mclose(MFile *file) {
	/* Calling the Bfile syscall and updating the MFile struct. */
	file->out = _Bfile_Close(file->fd);
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

void mseek(MFile *file, int pos) {
	/* Setting the new position whitout making checks because more informations
	are required to make checks, so they are made directly when doing operations
	on the file.
	error and out are set to 0 because no error can occur when doing this. */
    file->fpos = pos;
    file->error = 0;
    file->out = 0;
}

void msize(MFile *file) {
	/* Calling the Bfile syscall and updating the MFile struct. */
    file->out = _Bfile_Size(file->fd);
    if(file->out < 0){
        file->error = 1;
    }else{
        file->error = 0;
    }
}

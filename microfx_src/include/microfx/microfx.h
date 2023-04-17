#ifndef MICROFX_H
#define MICROFX_H

#include "keycodes.h"

#define size_t unsigned int

#define NULL 0

/******* DISPLAY *******/

#define SWIDTH 128
#define SHEIGHT 64

enum {SWHITE = 0, SBLACK};

/* void sclear(void);

Clears the VRAM in white.
*/

void sclear(void);

/* void supdate(void);

Put the VRAM on the screen.
*/

void supdate(void);

/* void srect(int x1, int y1, int x2, int y2);

Draws a white rectangle with a black border of one pixel from (x1, y1) to
(x2, y2) in the VRAM.
*/

void srect(int x1, int y1, int x2, int y2);

/* void sline(int x1, int y1, int x2, int y2, int color);

Draws a line with a width of one pixel from (x1, y1) to (x2, y2) in the VRAM of
color color.
The available colors are SWHITE or SBLACK.
*/

void sline(int x1, int y1, int x2, int y2, int color);

/* void spixel(int x, int y, int color);

Set the pixel at (x, y) in the color color in the VRAM.
The available colors are SWHITE or SBLACK.
*/

void spixel(int x, int y, int color);

/* void stext(int x, int y, char *text, int color);

Puts the text text at (x, y) on the screen using casio default font with color
color.
*/

void stext(int x, int y, char *text, int color);

/* void slocate(int x, int y, char *text);

Works like the Locate function of CASIO Basic.
*/

void slocate(int x, int y, char *text);

/* void saddlocate(char *text);

Continues the text displayed with slocate, can be used multiple times after a
locate.
*/

void saddlocate(char *text);

/* void sgoto(int x, int y);

Moves the position where you can add text with saddlocate.
*/

void sgoto(int x, int y);

/* void stextmini(int x, int y, char *text);

Works like stext, but here the font is PrintMini and you cannot set the color.
*/

void stextmini(int x, int y, char *text);

/******* KEYBOARD *******/

/* int kisdown(void);

Returns a positive int if a key is down.
Returns 0 if there is no key down.
*/
int kisdown(void);

/* int kcheck(int key);

Checks if the key key is down or not : returns a positive int if the key is
down, or 0 if the key key is not down.
*/
int kcheck(int key);

/* int kgetkey(void);

Works like the Getkey function of CASIO Basic.
Returns the pressed key.
*/
int kgetkey(void);

/******* TOOLS *******/

/* void itoa(int n, char *buffer);

Put a string of the int n in buffer.
*/

void itoa(int n, char *buffer);

/* void *malloc(size_t __size);

returns a pointer of size __size.
*/

void *malloc(size_t __size);

/* void *calloc(size_t __nmemb, size_t __size);

returns a pointer of size __nmemb * __size.
*/

void *calloc(size_t __nmemb, size_t __size);

/* void *realloc(void *__ptr, size_t __size);

returns __ptr but changes the size of this pointer to __size.
*/

void *realloc(void *__ptr, size_t __size);

/* void free(void *__ptr);

Free __ptr.
*/

void free(void *__ptr);

/* void itohex(char *buffer, int value, int len);

Puts the hex representation of value into buffer. The hex number will have the
size len.
*/

void itohex(char *buffer, int value, int len);

/******* TIME *******/

/* void tsleep_ms(int ms);

Wait ms miliseconds.
*/
void tsleep_ms(int ms);

/* void tgetticks(void);

Get 1/128 seconds ticks since midnight.
*/

int tgetticks(void);

/* int tiselapsed(int start, int ms);

Check if ms where elapsed since start (ticks that you can get with tgetticks).
Returns 1 if ms is elapsed and 0 if it is not.
*/

int tiselapsed(int start, int ms);

/* void treset(void);

Resets RTC.
*/

void treset(void);

/* int tinittimer(int ms, void (*callback)(void));

Initializes a timer that call callback each ms miliseconds.
The timers have a precision of 25 ms.

Returns the id of the timer.
*/

int tinittimer(int ms, void (*callback)(void));

/* void tfreetimer(int id);

Free the timer id.
*/

void tfreetimer(int id);

/* void tstarttimer(int id);

Start the timer id.
*/

void tstarttimer(int id);

/* void tstoptimer(int id);

Stop the timer id.
*/

void tstoptimer(int id);

/******* CPU *******/

/* void csleep(void);

Uses asm sleep instruction.
Can be used to reduce battery usage of some loops.
*/

void csleep(void);

/******* GUI *******/

enum {GDEC = 0, GHEX};

/* int gnumask(char *message, int maxlen, int type);

Asks for a num that is returned. message contains the message that will be
displayed when asking for the number. maxlen is the maximal length of the input
and type can be GDEC or GHEX. Set type to GDEC if you want to ask for a decimal
number or GHEX if you want that the user inputs a hexadecimal number.
*/

int gnumask(char *message, int maxlen, int type);

/* void gstrask(char *buffer, char *message, int maxlen);

Asks for a str that will be in buffer. message contains the message that will be
displayed when asking for the string and maxlen is the maximal length of the
input.
*/

void gstrask(char *buffer, char *message, int maxlen);

/* void simage(int sx, int sy, int w, int h, unsigned char *img, int mode);

Draws an fkey from a Sprite Coder string that is in img, at fkey position pos.
*/

void gfkeyset(int pos, unsigned char *img);

/* void gmessagebox(int height, char *message);

Draws a message box of height height with that contains message.
*/

void gmessagebox(int height, char *message);

/******* Memory *******/

/* File types */

enum {
    MFILE    = 1,
    MFOLDER  = 5
};

/* Open modes */

enum {
    MREAD  = 0x01,
    MWRITE = 0x02,
    MREADW = (MREAD | MWRITE),
    MSHARE = 0x80,
    MRWS   = (MREADW | MSHARE)
};

/* Defines */

#define MRCONTINUE -1 /* Start reading from the current position. */

#define PATHSIZELIMIT 256 /* Max. path size */

/* Prototypes */

/* IMPORTANT NOTE : The CASIOWIN/Fugue compatibility is made automatically. */

/* int mfugue(void);

Returns a postive int if the calculator has a fugue filesystem, or 0 if his fs
is CASIOWIN.
*/

int mfugue(void);

/* int mremove(const char *filename);

Removes the file filename. filename is a const char path for UNIX.
*/

int mremove(const char *filename);

/* int mcreate(const char *filename, int type, int size);

Creates the file or folder filename with size size. filename is a const char
path for UNIX.
Set type to MFILE if you want to create a file. Please consider that your add-in
may run on a CASIOWIN calculator, so please enter the real size of your file,
and not 0.
But if you want to create a folder, set type to MFOLDER and then you can also
set the size to 0 and I also recommend that because fxlib does that.
Returns a negative int if there was an error.
*/

int mcreate(const char *filename, int type, int size);

/* int mopen(const char *filename, int mode);

Opens the file filename with mode mode.
Available modes are :
- MREAD : Opens the file only for reading.
- MWRITE : Opens the file only for writing.
- MREADW : Opens the file for reading and writing.
- MSHARE : (I don't know what it is XD) Opens the file in shared mode.
- MRWS : Opens the file for reading, writing and in shared mode.
As always the filename is for UNIX and is fixed for the calc.
Returns an error code or the file descriptor of this file.
*/

int mopen(const char *filename, int mode);

/* int mwrite(int fd, const void *data, int size);

Writes size bytes of data to the file of file descriptor fd that you can get
with mopen.
Return a negative value if there was an error.
*/

int mwrite(int fd, const void *data, int size);

/* int mread(int fd, void *data, int size, int whence);

Read size bytes of the file of fd and put them into data. Set whence to a
positive value to set where mread should start reading, or to MRCONTINUE to
continue reading from the actual position.
Return a negative value if there was an error.
*/

int mread(int fd, void *data, int size, int whence);

/* int mclose(int fd);

Close the file descriptor fd.
*/

int mclose(int fd);

#endif

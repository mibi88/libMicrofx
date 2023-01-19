#ifndef MICROFX_H
#define MICROFX_H

#include "keycodes.h"

#define size_t unsigned int

/******* DISPLAY *******/

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

Draws a white rectangle with a black border of one pixel from (x1, y1) to (x2, y2)
in the VRAM.
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

/* void stext(int x, int y, char *text);

Puts the text text at (x, y) on the screen using casio
default font.
*/

void stext(int x, int y, char *text);

/* void slocate(int x, int y, char *text);

Works like the Locate function of CASIO Basic.
*/

void slocate(int x, int y, char *text);

/******* KEYBOARD *******/

/* int kisdown(void);

Returns a positive int if a key is down.
Returns 0 if there is no key down.
*/
int kisdown(void);

/* int kcheck(int key);

Checks if the key key is down or not : returns a positive
int if the key is down, or 0 if the key key is not down.
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

Check if ms where elapsed since start (ticks that you can
get with tgetticks).
Returns 1 if ms is elapsed and 0 if it is not.
*/

int tiselapsed(int start, int ms);

/******* CPU *******/

/* void csleep(void);

Uses asm sleep instruction.
Can be used to reduce battery usage of some loops.
*/

void csleep(void);

/******* GUI *******/

enum {GDEC = 0, GHEX};

/* int gnumask(char *message, int maxlen, int type);

Asks for a num that is returned. message contains the
message that will be displayed when asking for the number.
maxlen is the maximal length of the input and type can be
GDEC or GHEX. Set type to GDEC if you want to ask for a
decimal number or GHEX if you want that the user inputs a
hexadecimal number.
*/

int gnumask(char *message, int maxlen, int type);

/* void gstrask(char *buffer, char *message, int maxlen);

Asks for a str that will be in buffer. message contains
the message that will be displayed when asking for the
string and maxlen is the maximal length of the input.
*/

void gstrask(char *buffer, char *message, int maxlen);

#endif

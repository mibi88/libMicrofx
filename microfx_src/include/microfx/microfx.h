#ifndef MICROFX_H
#define MICROFX_H

#include "keycodes.h"

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

/* int kcheck(int key, int type);

/!\ Not working /!\

Checks if the key key is down or not : returns a positive
int if the key is down, or 0 if he's not down.
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

/******* TIME *******/

/* void tsleep_ms(int ms);

Wait ms miliseconds.
*/
void tsleep_ms(int ms);

#endif


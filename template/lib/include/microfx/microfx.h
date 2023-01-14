#ifndef MICROFX_H
#define MICROFX_H

#include "keycodes.h"

/******* DISPLAY *******/

enum {SWHITE = 0, SBLACK};

/* void sclear(void);

Clears the screen in white.
*/

void sclear(void);

/*

*/

void supdate(void);

/*

*/

void srect(int x1, int y1, int x2, int y2);

/*

*/

void spixel(int x, int y, int color);

/*

*/

void stext(int x, int y, char *text);

/*

*/

void slocate(int x, int y, char *text);

/******* KEYBOARD *******/

enum {KFAST = 0, KLONG};

int kisdown(void);
int kcheck(int key, int type);
int kgetkey(void);

/******* TOOLS *******/

/*

*/

void itoa(int n, char *buffer);

/******* TIME *******/

void tsleep_ms(int ms);

#endif


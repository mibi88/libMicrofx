#include "../../include/microfx/ext/img.h"
#include "../../include/microfx/microfx.h"

void simage(int sx, int sy, int w, int h, unsigned char *img, int mode) {
	/* Draws an image from a sprite coder string */
	int x, y, rpos, gpos, bpos, color;
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			rpos = y*(w+(w%2))+x;
			gpos = rpos/8;
			bpos = rpos%8;
			color = (img[gpos] << bpos) & 0x80;
			switch(mode){
				case STRANSP:
					if(color) spixel(sx+x, sy+y, SWHITE);
					break;
				case SNOWHITE:
					if(color) spixel(sx+x, sy+y, SBLACK);
					break;
				case SNOBLACK:
					if(!color) spixel(sx+x, sy+y, SWHITE);
					break;
				default: /* SNORMAL or SINVERTED */
					spixel(sx+x, sy+y, mode ? !color : color);
					break;
			}
		}
	}
}

#ifndef IMG_H
#define IMG_H

enum {SNORMAL = 0, SINVERTED, STRANSP, SNOWHITE, SNOBLACK};

/* void simage(int sx, int sy, int w, int h, unsigned char *img, int mode);

Draws an image from a Sprite Coder string that is in img,
where the top left corner is at (sx, sy).
w is the width and h the height of the image.
mode can be :
SNORMAL : Draws the image normally.
SINVERTED : Draws the image with inverted colors.
STRANSP : Black is white and white is not drawn. Useful for
transparency in sprites.
*/

void simage(int sx, int sy, int w, int h, unsigned char *img, int mode);

#endif

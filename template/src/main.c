#include <microfx/microfx.h>

int main(void) {
	while(kisdown());
	stext(1, 1, "A Microfx Add-in !", SBLACK);
	/* Waits that the user presses EXIT. */
	int key = 0;
	while(key != KCEXIT){
		key = kgetkey();
	}
	return 1;
}

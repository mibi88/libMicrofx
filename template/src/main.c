#include <microfx/microfx.h>

int main(void) {
	while(kisdown());
	stext(1, 1, "A Microfx Add-in !");
	while(!kisdown());
	return 1;
}

/* Pointers that contain the start and the end address of some sections of the
add-in. */

extern char start_bss, end_bss;
extern char start_data, end_data;
extern char romdata_start;

/* The main function. */
extern int main(void);

/* The variable used when manipulating files, to check if the filesystem is
Fugue or CASIOWIN. */

int fugue;

/* .pretext is where the add-in starts to be executed. */
__attribute__((section(".pretext")))

int start(void) {
	int i;
	char *bss_startptr, *data_startptr, *romdataptr;
	char *os_version = (void *)0x80010020;
	/* Clearing the bss. */
	bss_startptr = &start_bss;
	for(i=0;i<&end_bss - &start_bss;i++){
		bss_startptr[i] = 0;
	}
	/* Load the ROM data into the RAM. */
	data_startptr = &start_data;
	romdataptr = &romdata_start;
	for(i=0;i<&end_data - &start_data;i++){
		data_startptr[i] = romdataptr[i];
	}
	/* Checking if the calculator has a fugue filesystem, because it is
	important to know that when using Bfile. */
	if(os_version[1] == '3'){
		fugue = 1;
	}else{
		fugue = 0;
	}
	/* Calling main. The return value of main is directly returned because no
	modifications need to be made. */
	return main();
}

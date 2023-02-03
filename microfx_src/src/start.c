extern char start_bss, end_bss;
extern char start_data, end_data;
extern char romdata_start;
extern int main(void);

__attribute__((section(".pretext")))

int start(void) {
	int i;
	char *bss_startptr, *data_startptr, *romdataptr;
	bss_startptr = &start_bss;
	for(i=0;i<&end_bss - &start_bss;i++){
		bss_startptr[i] = 0;
	}
	data_startptr = &start_data;
	romdataptr = &romdata_start;
	for(i=0;i<&end_data - &start_data;i++){
		data_startptr[i] = romdataptr[i];
	}
	return main();
}


extern char start_bss, end_bss;
extern char start_data, end_data;
extern char romdata_start;
extern int main(void);

int fugue;

__attribute__((section(".pretext")))

int start(void) {
	int i;
	char *bss_startptr, *data_startptr, *romdataptr;
	char *os_version = (void *)0x80010020;
	bss_startptr = &start_bss;
	for(i=0;i<&end_bss - &start_bss;i++){
		bss_startptr[i] = 0;
	}
	data_startptr = &start_data;
	romdataptr = &romdata_start;
	for(i=0;i<&end_data - &start_data;i++){
		data_startptr[i] = romdataptr[i];
	}
	if(os_version[1] == '3'){
		fugue = 1;
	}else{
		fugue = 0;
	}
	return main();
}

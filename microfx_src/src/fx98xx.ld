ENTRY(_start)

MEMORY
{
	rom (rx)  : ORIGIN = 0x00300200, LENGTH = 512K
	ram (rw) : ORIGIN = 0x08100200, LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.pretext)
		*(.text)
	} > rom
	.rodata : {
		*(.rodata)
		*(.rodata.str1.4)
		_romdata_start = . ;
	} > rom
	.bss : {
		_start_bss = . ;
		_bssdatasize = . ;
		LONG(0);
		*(.bss)
		*(COMMON)
		_end_bss = . ;
	} > ram
	.data : AT(_romdata_start) {
		_start_data = . ;
		*(.data)
		_end_data = . ;
	} > ram
}

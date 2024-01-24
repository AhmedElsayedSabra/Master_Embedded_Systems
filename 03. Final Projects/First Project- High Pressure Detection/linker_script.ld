/* 
Linker Script.ld linker scripting_cortexm3
Eng- Ahmed Elsayed Sabra
*/ 
MEMORY
{
	flash(RX) : ORIGIN = 0X08000000 , LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
}
SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	}> flash
	.data :
	{
		_S_DATA = . ;
		*(.data*)
		_E_DATA = . ;
	}> sram AT> flash
	.bss :
	{
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4) ;
		_E_BSS = . ;
		. = ALIGN(4) ;
		. = . + 0x1000 ;
		_Stack_top =  . ;
	}> sram	
}
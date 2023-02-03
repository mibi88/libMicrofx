.text

.global __Bdisp_PutDisp_DD
.global __Bdisp_DrawRectangle
.global __Bdisp_AllClr_VRAM
.global __Bdisp_SetPoint_VRAM
.global __Bdisp_GetPoint_VRAM
.global __PrintXY
.global __locate
.global __Print
.global __Bdisp_DrawLineVRAM
.global __Bdisp_ClearLineVRAM
.global __PrintMiniSd
.global __DisplayMessageBox
/* Keyboard */
.global __Keyboard_KeyDown
.global __Keyboard_PRGM_GetKey
/* Time */
.global __Sleep
.global __RTC_GetTicks
.global __RTC_Elapsed_ms
.global __RTC_Reset
.global __Timer_Install
.global __Timer_Deinstall
.global __Timer_Start
.global __Timer_Stop
/* Files */
/* Tools */
.global _itoa
.global _malloc
.global _calloc
.global _realloc
.global _free
.global __LongToAscHex
/* Tools - str/mem */
.global _memcmp
.global _memcpy
.global _memset
.global _strcat
.global _strcmp
.global _strlen
.global _strncat
.global _strncmp
.global _strncpy
.global _strrchr
.global _strchr
.global _strstr
.global _memmove
/* GUI */
.global __InputNumber
.global __InputString
.global __DisplayFKeyIcon

#define syscall(syscall_number) \
	mov.l   1f, r0 ;\
	mov.l   do_syscall, r2 ;\
	jmp     @r2 ;\
	nop ;\
.align 4 ;\
1:	.long	syscall_number

/* Display */
__Bdisp_PutDisp_DD:
	syscall(0x028)
__Bdisp_DrawRectangle:
	syscall(0x0763)
__Bdisp_AllClr_VRAM:
	syscall(0x143)
__Bdisp_SetPoint_VRAM:
	syscall(0x146)
__Bdisp_GetPoint_VRAM:
	syscall(0x149)
__PrintXY:
	syscall(0x150)
__locate:
	syscall(0x807)
__Print:
	syscall(0x808)
__Bdisp_DrawLineVRAM:
	syscall(0x030)
__Bdisp_ClearLineVRAM:
	syscall(0x031)
__PrintMiniSd:
	syscall(0xC4F)
__DisplayMessageBox:
	syscall(0x0901)
/* Keyboard */
__Keyboard_KeyDown:
	syscall(0x24D)
__Keyboard_PRGM_GetKey:
	syscall(0x6C4)
/* Time */
__Sleep:
	syscall(0x0420)
__RTC_GetTicks:
	syscall(0x03B)
__RTC_Elapsed_ms:
	syscall(0x03C)
__RTC_Reset:
	syscall(0x039)
__Timer_Install:
	syscall(0x0118)
__Timer_Deinstall:
	syscall(0x0119)
__Timer_Start:
	syscall(0x011A)
__Timer_Stop:
	syscall(0x011B)
/* Files */
/* Nothing here ... */
/* Tools */
_itoa:
	syscall(0x541)
_malloc:
	syscall(0xACD)
_calloc:
	syscall(0xE6B)
_realloc:
	syscall(0xE6D)
_free:
	syscall(0xACC)
__LongToAscHex:
	syscall(0x467)
_memcmp:
	syscall(0xACE)
_memcpy:
	syscall(0xACF)
_memset:
	syscall(0xAD0)
_strcat:
	syscall(0xAD4)
_strcmp:
	syscall(0xAD5)
_strlen:
	syscall(0xAD6)
_strncat:
	syscall(0xAD7)
_strncmp:
	syscall(0xAD8)
_strncpy:
	syscall(0xAD9)
_strrchr:
	syscall(0xADA)
_strchr:
	syscall(0xE6E)
_strstr:
	syscall(0xE6F)
_memmove:
	syscall(0xE6C)
/* GUI */
__InputNumber:
	syscall(0x0CC4)
__InputString:
	syscall(0x0CC5)
__DisplayFKeyIcon:
	syscall(0x04D1)
/* Menu */
/* Nothing here ... */

do_syscall: .long 0x80010070

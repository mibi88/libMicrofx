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
/* Keyboard */
.global __Keyboard_GetPressedTime
.global __Keyboard_IsKeyPressed
.global __Keyboard_IsKeyPressed_fast
.global __Keyboard_KeyDown
.global __Keyboard_PRGM_GetKey
/* Time */
.global __Sleep
.global __RTC_GetTicks
.global __RTC_Elapsed_ms
/* Files */
/* Tools */
.global _itoa
.global _malloc
.global _calloc
.global _realloc
.global _free
/* GUI */
.global __InputNumber
.global __InputString

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
/* Keyboard */
__Keyboard_GetPressedTime:
	syscall(0x249)
__Keyboard_IsKeyPressed:
	syscall(0x24C)
__Keyboard_IsKeyPressed_fast:
	syscall(0x24B)
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
/* GUI */
__InputNumber:
	syscall(0x0CC4)
__InputString:
	syscall(0x0CC5)
/* Menu */
/* Nothing here ... */

do_syscall: .long 0x80010070

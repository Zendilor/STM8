;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _IRQ_TIMER2
	.globl _IRQ_UART1_RX
	.globl _main
	.globl _MASTER_Send
	.globl _TIMER_Config
	.globl _UART_Config
	.globl _CLK_Config
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ; reset
	int 0x000000 ; trap
	int 0x000000 ; int0
	int 0x000000 ; int1
	int 0x000000 ; int2
	int 0x000000 ; int3
	int 0x000000 ; int4
	int 0x000000 ; int5
	int 0x000000 ; int6
	int 0x000000 ; int7
	int 0x000000 ; int8
	int 0x000000 ; int9
	int 0x000000 ; int10
	int 0x000000 ; int11
	int 0x000000 ; int12
	int _IRQ_TIMER2 ; int13
	int 0x000000 ; int14
	int 0x000000 ; int15
	int 0x000000 ; int16
	int 0x000000 ; int17
	int _IRQ_UART1_RX ; int18
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	src/main.c: 8: int main (void){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/main.c: 9: CLK_Config();
	call	_CLK_Config
;	src/main.c: 10: UART_Config();
	call	_UART_Config
;	src/main.c: 11: TIMER_Config();
	call	_TIMER_Config
;	src/main.c: 12: enableInterrupts();
	rim
;	src/main.c: 14: while (1){
00102$:
	jra	00102$
;	src/main.c: 17: }
	ret
;	src/main.c: 19: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
;	-----------------------------------------
;	 function IRQ_UART1_RX
;	-----------------------------------------
_IRQ_UART1_RX:
;	src/main.c: 21: }
	iret
;	src/main.c: 23: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
;	-----------------------------------------
;	 function IRQ_TIMER2
;	-----------------------------------------
_IRQ_TIMER2:
	clr	a
	div	x, a
;	src/main.c: 24: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag TIMER2.
	bres	21252, #0
;	src/main.c: 25: MASTER_Send();
	call	_MASTER_Send
;	src/main.c: 26: }
	iret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

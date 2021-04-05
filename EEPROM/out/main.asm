;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _IRQ_ADC
	.globl _IRQ_TIMER2
	.globl _IRQ_UART1_RX
	.globl _main
	.globl _CLK_Config
	.globl _UART_Send
	.globl _UART_Config
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
	int 0x000000 ; int19
	int 0x000000 ; int20
	int 0x000000 ; int21
	int _IRQ_ADC ; int22
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
;	src/main.c: 5: int main (void){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/main.c: 6: CLK_Config();
	call	_CLK_Config
;	src/main.c: 7: UART_Config();
	call	_UART_Config
;	src/main.c: 13: UART_Send(0x31);
	push	#0x31
	call	_UART_Send
	pop	a
;	src/main.c: 15: while (1){
00102$:
	jra	00102$
;	src/main.c: 18: }
	ret
;	src/main.c: 20: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
;	-----------------------------------------
;	 function IRQ_UART1_RX
;	-----------------------------------------
_IRQ_UART1_RX:
	clr	a
	div	x, a
;	src/main.c: 21: UART_Send(UART1->DR);
	ld	a, 0x5231
	push	a
	call	_UART_Send
	pop	a
;	src/main.c: 22: UART_Send(0x31);
	push	#0x31
	call	_UART_Send
	pop	a
;	src/main.c: 23: }
	iret
;	src/main.c: 26: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
;	-----------------------------------------
;	 function IRQ_TIMER2
;	-----------------------------------------
_IRQ_TIMER2:
;	src/main.c: 27: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
	bres	21252, #0
;	src/main.c: 29: }
	iret
;	src/main.c: 31: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
;	-----------------------------------------
;	 function IRQ_ADC
;	-----------------------------------------
_IRQ_ADC:
;	src/main.c: 32: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1
	bres	21504, #7
;	src/main.c: 33: }
	iret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

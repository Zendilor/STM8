;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module UART
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _baud_rate
	.globl _frequency
	.globl _UART_Config
	.globl _UART_Send
	.globl _UART_Send_16bit
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_frequency::
	.ds 4
_baud_rate::
	.ds 4
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
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	src/UART.c: 10: void UART_Config (void){
;	-----------------------------------------
;	 function UART_Config
;	-----------------------------------------
_UART_Config:
	sub	sp, #4
;	src/UART.c: 11: UART1->BRR1 = ((frequency / baud_rate) & 0x0FF0) >> 4;   // Set bir low bite.
	push	_baud_rate+3
	push	_baud_rate+2
	push	_baud_rate+1
	push	_baud_rate+0
	push	_frequency+3
	push	_frequency+2
	push	_frequency+1
	push	_frequency+0
	call	__divulong
	addw	sp, #8
	ld	a, xl
	and	a, #0xf0
	rlwa	x
	and	a, #0x0f
	ld	xh, a
	ld	a, #0x10
	div	x, a
	ld	a, xl
	ld	0x5232, a
;	src/UART.c: 12: UART1->BRR2 = (((frequency / baud_rate) & 0xF000) >> 2) | ((frequency / baud_rate) & 0x000F);
	push	_baud_rate+3
	push	_baud_rate+2
	push	_baud_rate+1
	push	_baud_rate+0
	push	_frequency+3
	push	_frequency+2
	push	_frequency+1
	push	_frequency+0
	call	__divulong
	addw	sp, #8
	rlwa	x
	ld	(0x03, sp), a
	rrwa	x
	ld	a, xl
	rlwa	x
	ld	a, (0x03, sp)
	rrwa	x
	push	a
	clr	a
	rlwa	x
	and	a, #0xf0
	ld	xh, a
	pop	a
	srlw	x
	srlw	x
	and	a, #0x0f
	pushw	x
	or	a, (2, sp)
	popw	x
	ld	0x5233, a
;	src/UART.c: 13: UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
	bset	21045, #3
;	src/UART.c: 14: UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
	bset	21045, #2
;	src/UART.c: 15: }
	addw	sp, #4
	ret
;	src/UART.c: 17: void UART_Send (uint8_t data){
;	-----------------------------------------
;	 function UART_Send
;	-----------------------------------------
_UART_Send:
;	src/UART.c: 18: while(!(UART1->SR & UART1_SR_TXE));
00101$:
	ld	a, 0x5230
	jrpl	00101$
;	src/UART.c: 19: UART1->DR = data;
	ldw	x, #0x5231
	ld	a, (0x03, sp)
	ld	(x), a
;	src/UART.c: 20: }
	ret
;	src/UART.c: 22: void UART_Send_16bit (int data){
;	-----------------------------------------
;	 function UART_Send_16bit
;	-----------------------------------------
_UART_Send_16bit:
;	src/UART.c: 23: UART_Send(data >> 8);
	ldw	x, (0x03, sp)
	clr	a
	tnzw	x
	jrpl	00103$
	dec	a
00103$:
	rrwa	x
	ld	a, xl
	push	a
	call	_UART_Send
	pop	a
;	src/UART.c: 24: UART_Send(data);
	ld	a, (0x04, sp)
	push	a
	call	_UART_Send
	pop	a
;	src/UART.c: 25: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__frequency:
	.byte #0x00, #0xf4, #0x24, #0x00	; 16000000
__xinit__baud_rate:
	.byte #0x00, #0x00, #0x25, #0x80	; 9600
	.area CABS (ABS)

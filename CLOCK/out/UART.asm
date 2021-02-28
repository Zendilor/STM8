;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module UART
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
;	src/UART.c: 6: void UART_Config (void){
;	-----------------------------------------
;	 function UART_Config
;	-----------------------------------------
_UART_Config:
;	src/UART.c: 7: UART1->BRR1 = 0x68;
	mov	0x5232+0, #0x68
;	src/UART.c: 8: UART1->BRR2 = 0x02;
	mov	0x5233+0, #0x02
;	src/UART.c: 10: UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
	bset	21045, #3
;	src/UART.c: 11: UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
	bset	21045, #2
;	src/UART.c: 12: UART1->CR2 |= UART1_CR2_RIEN; // Enable interrupt receive.
	bset	21045, #5
;	src/UART.c: 13: }
	ret
;	src/UART.c: 15: void UART_Send (uint8_t data){
;	-----------------------------------------
;	 function UART_Send
;	-----------------------------------------
_UART_Send:
;	src/UART.c: 16: while(!(UART1->SR & UART1_SR_TXE));
00101$:
	ld	a, 0x5230
	jrpl	00101$
;	src/UART.c: 17: UART1->DR = data;
	ldw	x, #0x5231
	ld	a, (0x03, sp)
	ld	(x), a
;	src/UART.c: 18: }
	ret
;	src/UART.c: 20: void UART_Send_16bit (int data){
;	-----------------------------------------
;	 function UART_Send_16bit
;	-----------------------------------------
_UART_Send_16bit:
;	src/UART.c: 21: UART_Send(data >> 8);
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
;	src/UART.c: 22: UART_Send(data);
	ld	a, (0x04, sp)
	push	a
	call	_UART_Send
	pop	a
;	src/UART.c: 23: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

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
	.globl _ADC_Config
	.globl _Get_Result
	.globl _TIMER_Config
	.globl _UART_Send_16bit
	.globl _UART_Send
	.globl _UART_Config
	.globl _GPIO_Config
	.globl _CLK_Config
	.globl _Convert_value
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
;	src/main.c: 10: int main (void){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/main.c: 12: CLK_Config();
	call	_CLK_Config
;	src/main.c: 13: GPIO_Config();
	call	_GPIO_Config
;	src/main.c: 14: UART_Config();
	call	_UART_Config
;	src/main.c: 15: ADC_Config();
	call	_ADC_Config
;	src/main.c: 16: TIMER_Config();
	call	_TIMER_Config
;	src/main.c: 18: while (1){
00102$:
	jra	00102$
;	src/main.c: 21: }
	ret
;	src/main.c: 23: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
;	-----------------------------------------
;	 function IRQ_UART1_RX
;	-----------------------------------------
_IRQ_UART1_RX:
	clr	a
	div	x, a
;	src/main.c: 24: UART_Send(UART1->DR);
	ld	a, 0x5231
	push	a
	call	_UART_Send
	pop	a
;	src/main.c: 25: }
	iret
;	src/main.c: 27: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
;	-----------------------------------------
;	 function IRQ_TIMER2
;	-----------------------------------------
_IRQ_TIMER2:
	clr	a
	div	x, a
;	src/main.c: 28: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
	bres	21252, #0
;	src/main.c: 29: UART_Send(0x39);
	push	#0x39
	call	_UART_Send
	pop	a
;	src/main.c: 30: }
	iret
;	src/main.c: 32: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
;	-----------------------------------------
;	 function IRQ_ADC
;	-----------------------------------------
_IRQ_ADC:
	clr	a
	div	x, a
;	src/main.c: 33: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
	bres	21504, #7
;	src/main.c: 34: Convert_value();
	call	_Convert_value
;	src/main.c: 35: ADC1->CR1 |= ADC1_CR1_ADON;
	bset	21505, #0
;	src/main.c: 36: }
	iret
;	src/main.c: 38: void Convert_value (void){
;	-----------------------------------------
;	 function Convert_value
;	-----------------------------------------
_Convert_value:
	sub	sp, #2
;	src/main.c: 39: unsigned int data = Get_Result();
	call	_Get_Result
;	src/main.c: 40: UART_Send_16bit(data);
	pushw	x
	pushw	x
	call	_UART_Send_16bit
	addw	sp, #2
	popw	x
;	src/main.c: 41: data = data * 64.0615835;
	pushw	x
	call	___uint2fs
	addw	sp, #2
	pushw	x
	pushw	y
	push	#0x88
	push	#0x1f
	push	#0x80
	push	#0x42
	call	___fsmul
	addw	sp, #8
	pushw	x
	pushw	y
	call	___fs2uint
	addw	sp, #4
;	src/main.c: 42: TIM2->ARRL = data;
	ld	a, xl
	ld	0x5310, a
;	src/main.c: 43: TIM2->ARRH = data >> 8;
	ld	a, xh
	clr	(0x01, sp)
	ld	0x530f, a
;	src/main.c: 44: data = (data * 60) / 100;
	pushw	x
	sllw	x
	sllw	x
	sllw	x
	sllw	x
	subw	x, (1, sp)
	sllw	x
	sllw	x
	addw	sp, #2
	ldw	y, #0x0064
	divw	x, y
;	src/main.c: 45: TIM2->CCR1L = data;
	ld	a, xl
	ld	0x5312, a
;	src/main.c: 46: TIM2->CCR1H = data >> 8;
	ld	a, xh
	ld	0x5311, a
;	src/main.c: 47: }
	addw	sp, #2
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

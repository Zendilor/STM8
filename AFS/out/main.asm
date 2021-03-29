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
	.globl _IRQ_TIMER1
	.globl _IRQ_UART1_RX
	.globl _main
	.globl _Indication
	.globl _ADC_Config
	.globl _Get_Result
	.globl _TIMER_Config
	.globl _UART_Send
	.globl _GPIO_Config
	.globl _CLK_Config
	.globl _segs
	.globl _data_ADC
	.globl _coefiz
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_coefiz::
	.ds 4
_data_ADC::
	.ds 2
_segs::
	.ds 1
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
	int _IRQ_TIMER1 ; int11
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
;	src/main.c: 18: int main (void){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/main.c: 19: enableInterrupts();
	rim
;	src/main.c: 20: CLK_Config();
	call	_CLK_Config
;	src/main.c: 21: GPIO_Config();
	call	_GPIO_Config
;	src/main.c: 22: TIMER_Config();
	call	_TIMER_Config
;	src/main.c: 23: ADC_Config();
	call	_ADC_Config
;	src/main.c: 25: while (1){
00102$:
	jp	00102$
00104$:
;	src/main.c: 28: }
	ret
;	src/main.c: 30: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
;	-----------------------------------------
;	 function IRQ_UART1_RX
;	-----------------------------------------
_IRQ_UART1_RX:
	clr	a
	div	x, a
;	src/main.c: 31: UART_Send(UART1->DR);
	ld	a, 0x5231
	push	a
	call	_UART_Send
	pop	a
;	src/main.c: 32: UART_Send(0x31);
	push	#0x31
	call	_UART_Send
	pop	a
00101$:
;	src/main.c: 33: }
	iret
;	src/main.c: 35: INTERRUPT_HANDLER(IRQ_TIMER1, 11){
;	-----------------------------------------
;	 function IRQ_TIMER1
;	-----------------------------------------
_IRQ_TIMER1:
;	src/main.c: 36: TIM1->SR1 &= ~TIM1_SR1_UIF;   // Clear interrupt flag.
	ld	a, 0x5255
	and	a, #0xfe
	ld	0x5255, a
;	src/main.c: 37: ADC1->CR1 |= ADC1_CR1_ADON;
	ld	a, 0x5401
	or	a, #0x01
	ld	0x5401, a
00101$:
;	src/main.c: 38: }
	iret
;	src/main.c: 40: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
;	-----------------------------------------
;	 function IRQ_TIMER2
;	-----------------------------------------
_IRQ_TIMER2:
	clr	a
	div	x, a
;	src/main.c: 41: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
	ld	a, 0x5304
	and	a, #0xfe
	ld	0x5304, a
;	src/main.c: 42: Indication(segs);
	push	_segs+0
	call	_Indication
	pop	a
;	src/main.c: 43: segs++;
	inc	_segs+0
;	src/main.c: 44: if (segs > 2){
	ld	a, _segs+0
	cp	a, #0x02
	jrugt	00110$
	jp	00103$
00110$:
;	src/main.c: 45: segs = 0;
	clr	_segs+0
00103$:
;	src/main.c: 47: }
	iret
;	src/main.c: 49: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
;	-----------------------------------------
;	 function IRQ_ADC
;	-----------------------------------------
_IRQ_ADC:
	clr	a
	div	x, a
	sub	sp, #2
;	src/main.c: 50: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
	ld	a, 0x5400
	and	a, #0x7f
	ld	0x5400, a
;	src/main.c: 51: data_ADC = (Get_Result() * coefiz) * 1000;
	call	_Get_Result
	pushw	x
	call	___uint2fs
	addw	sp, #2
	push	_coefiz+3
	push	_coefiz+2
	push	_coefiz+1
	push	_coefiz+0
	pushw	x
	pushw	y
	call	___fsmul
	addw	sp, #8
	pushw	x
	pushw	y
	clrw	x
	pushw	x
	push	#0x7a
	push	#0x44
	call	___fsmul
	addw	sp, #8
	pushw	x
	pushw	y
	call	___fs2uint
	addw	sp, #4
	ldw	_data_ADC+0, x
;	src/main.c: 52: seg_num [0] = data_ADC / 1000;
	ldw	x, _data_ADC+0
	ldw	y, #0x03e8
	divw	x, y
	ld	a, xl
	ld	_seg_num+0, a
;	src/main.c: 53: seg_num [1] = (data_ADC % 1000) / 100;
	ldw	x, #(_seg_num + 0)+1
	ldw	(0x01, sp), x
	ldw	x, _data_ADC+0
	ldw	y, #0x03e8
	divw	x, y
	ldw	x, y
	ldw	y, #0x0064
	divw	x, y
	ld	a, xl
	ldw	x, (0x01, sp)
	ld	(x), a
;	src/main.c: 54: seg_num [2] = (data_ADC % 100) / 10;
	ldw	x, #(_seg_num + 0)+2
	ldw	(0x01, sp), x
	ldw	x, _data_ADC+0
	ldw	y, #0x0064
	divw	x, y
	ldw	x, y
	ldw	y, #0x000a
	divw	x, y
	ld	a, xl
	ldw	x, (0x01, sp)
	ld	(x), a
00101$:
;	src/main.c: 55: }
	addw	sp, #2
	iret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__coefiz:
	.byte #0x3b, #0x53, #0x33, #0x33	;  3.222656e-03
__xinit__data_ADC:
	.dw #0x0000
__xinit__segs:
	.db #0x00	; 0
	.area CABS (ABS)

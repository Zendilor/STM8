;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module TIMER
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIMER1_Config
	.globl _TIMER_Config
	.globl _Duty
	.globl _Divider
	.globl _TIMER2_Config
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_Divider::
	.ds 2
_Duty::
	.ds 1
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
;	src/TIMER.c: 10: void TIMER_Config (void){
;	-----------------------------------------
;	 function TIMER_Config
;	-----------------------------------------
_TIMER_Config:
;	src/TIMER.c: 11: TIMER2_Config();
;	src/TIMER.c: 13: }
	jp	_TIMER2_Config
;	src/TIMER.c: 15: void TIMER1_Config (void){
;	-----------------------------------------
;	 function TIMER1_Config
;	-----------------------------------------
_TIMER1_Config:
;	src/TIMER.c: 16: TIM1->CR1 |= TIM1_CR1_ARPE; // Enable preload.
	bset	21072, #7
;	src/TIMER.c: 18: TIM1->CR1 |= TIM1_CR1_CEN;   // Enable TIM1.
	bset	21072, #0
;	src/TIMER.c: 19: }
	ret
;	src/TIMER.c: 21: void TIMER2_Config (void){
;	-----------------------------------------
;	 function TIMER2_Config
;	-----------------------------------------
_TIMER2_Config:
;	src/TIMER.c: 22: TIM2->CCR1H = ((Divider * Duty) / 100) >> 8;
	clrw	x
	ld	a, _Duty+0
	ld	xl, a
	pushw	x
	push	_Divider+1
	push	_Divider+0
	call	__mulint
	addw	sp, #4
	ldw	y, #0x0064
	divw	x, y
	ld	a, xh
	ld	0x5311, a
;	src/TIMER.c: 23: TIM2->CCR1L = (Divider * Duty) / 100;
	clrw	x
	ld	a, _Duty+0
	ld	xl, a
	pushw	x
	push	_Divider+1
	push	_Divider+0
	call	__mulint
	addw	sp, #4
	ldw	y, #0x0064
	divw	x, y
	ld	a, xl
	ld	0x5312, a
;	src/TIMER.c: 24: TIM2->ARRH = Divider >> 8;
	ld	a, _Divider+0
	clrw	x
	ld	0x530f, a
;	src/TIMER.c: 25: TIM2->ARRL = Divider;
	ld	a, _Divider+1
	ld	0x5310, a
;	src/TIMER.c: 26: TIM2->CCMR1 |= 0x60;        // Set PWM 1 mode.
	ld	a, 0x5307
	or	a, #0x60
	ld	0x5307, a
;	src/TIMER.c: 27: TIM2->CCMR1 |= 0x08;        // Output compare preload enable.
	bset	21255, #3
;	src/TIMER.c: 28: TIM2->CCER1 |= TIM2_CCER1_CC1E;
	bset	21258, #0
;	src/TIMER.c: 30: TIM2->PSCR = 1;          // Prescaler 1.
	mov	0x530e+0, #0x01
;	src/TIMER.c: 31: TIM2->CR1 |= TIM2_CR1_CEN;   // Enable counter.
	bset	21248, #0
;	src/TIMER.c: 32: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__Divider:
	.dw #0xffff
__xinit__Duty:
	.db #0x0a	; 10
	.area CABS (ABS)

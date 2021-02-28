;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module TIMER
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIMER_Config
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
;	src/TIMER.c: 7: void TIMER_Config (void){
;	-----------------------------------------
;	 function TIMER_Config
;	-----------------------------------------
_TIMER_Config:
;	src/TIMER.c: 8: TIMER2_Config();
;	src/TIMER.c: 9: }
	jp	_TIMER2_Config
;	src/TIMER.c: 11: void TIMER2_Config (void){
;	-----------------------------------------
;	 function TIMER2_Config
;	-----------------------------------------
_TIMER2_Config:
;	src/TIMER.c: 12: TIM2->ARRH = Divider >> 8;    // High byte counter.
	ld	a, _Divider+0
	ld	0x530f, a
;	src/TIMER.c: 13: TIM2->ARRL = Divider;         // Low byte counter.
	ld	a, _Divider+1
	ld	0x5310, a
;	src/TIMER.c: 14: TIM2->IER |= TIM2_IER_UIE;    // Enable interrupt update.
	bset	21251, #0
;	src/TIMER.c: 15: TIM2->PSCR = 10;              // Set prescaler for TIMER2.
	mov	0x530e+0, #0x0a
;	src/TIMER.c: 16: TIM2->CR1 |= TIM2_CR1_ARPE;   // Auto-reload preload enable.
	bset	21248, #7
;	src/TIMER.c: 17: TIM2->CR1 |= TIM2_CR1_CEN;    // Enable counter.
	bset	21248, #0
;	src/TIMER.c: 18: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__Divider:
	.dw #0x3d09
	.area CABS (ABS)

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
	.globl _TIM1_REL
	.globl _TIM1_DIV
	.globl _Duty
	.globl _Divider
	.globl _TIMER1_Config
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
_TIM1_DIV::
	.ds 2
_TIM1_REL::
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
;	src/TIMER.c: 14: void TIMER_Config (void){
;	-----------------------------------------
;	 function TIMER_Config
;	-----------------------------------------
_TIMER_Config:
;	src/TIMER.c: 15: TIMER1_Config();
	call	_TIMER1_Config
;	src/TIMER.c: 16: TIMER2_Config();
	jp	_TIMER2_Config
00101$:
;	src/TIMER.c: 18: }
	ret
;	src/TIMER.c: 20: void TIMER1_Config (void){
;	-----------------------------------------
;	 function TIMER1_Config
;	-----------------------------------------
_TIMER1_Config:
;	src/TIMER.c: 21: TIM1->CR1 |= TIM1_CR1_ARPE;   // Enable preload.
	ld	a, 0x5250
	or	a, #0x80
	ld	0x5250, a
;	src/TIMER.c: 22: TIM1->PSCRH = TIM1_DIV >> 8;  // Set divider H byte.
	ld	a, _TIM1_DIV+0
	clrw	x
	ld	0x5260, a
;	src/TIMER.c: 23: TIM1->PSCRL = TIM1_DIV;       // Set divider L byte.
	ld	a, _TIM1_DIV+1
	ld	0x5261, a
;	src/TIMER.c: 24: TIM1->ARRH = TIM1_REL > 8;    // Set autoreload H value.
	ldw	x, _TIM1_REL+0
	cpw	x, #0x0008
	jrugt	00103$
	clr	a
	jp	00104$
00103$:
	ld	a, #0x01
00104$:
	ld	0x5262, a
;	src/TIMER.c: 25: TIM1->ARRL = TIM1_REL;        // Set autoreload l value.
	ld	a, _TIM1_REL+1
	ld	0x5263, a
;	src/TIMER.c: 26: TIM1->IER |= TIM1_IER_UIE;    // Enable interrupt.
	ld	a, 0x5254
	or	a, #0x01
	ld	0x5254, a
;	src/TIMER.c: 27: TIM1->CR1 |= TIM1_CR1_CEN;    // Enable TIM1.
	ld	a, 0x5250
	or	a, #0x01
	ld	0x5250, a
00101$:
;	src/TIMER.c: 28: }
	ret
;	src/TIMER.c: 30: void TIMER2_Config (void){
;	-----------------------------------------
;	 function TIMER2_Config
;	-----------------------------------------
_TIMER2_Config:
;	src/TIMER.c: 31: TIM2->ARRH = Divider >> 8;
	ld	a, _Divider+0
	clrw	x
	ld	0x530f, a
;	src/TIMER.c: 32: TIM2->ARRL = Divider;
	ld	a, _Divider+1
	ld	0x5310, a
;	src/TIMER.c: 33: TIM2->IER |= TIM2_IER_UIE;  // Enable interrupt update.
	ld	a, 0x5303
	or	a, #0x01
	ld	0x5303, a
;	src/TIMER.c: 34: TIM2->PSCR = 8;             // Prescaler 1.
	mov	0x530e+0, #0x08
;	src/TIMER.c: 35: TIM2->CR1 |= TIM2_CR1_CEN;  // Enable counter.
	ld	a, 0x5300
	or	a, #0x01
	ld	0x5300, a
00101$:
;	src/TIMER.c: 36: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__Divider:
	.dw #0x0177
__xinit__Duty:
	.db #0x0a	; 10
__xinit__TIM1_DIV:
	.dw #0x2710
__xinit__TIM1_REL:
	.dw #0x0640
	.area CABS (ABS)

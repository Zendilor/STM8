;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module CLK
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CLK_Config
	.globl _CLK_Deinit
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
;	src/CLK.c: 5: void CLK_Config (void){
;	-----------------------------------------
;	 function CLK_Config
;	-----------------------------------------
_CLK_Config:
;	src/CLK.c: 6: CLK_Deinit();
	call	_CLK_Deinit
;	src/CLK.c: 7: CLK->PCKENR1 |= CLK_PCKENR1_UART2;  // Enable clock for UART1 (see datasheet).
	bset	20679, #3
;	src/CLK.c: 8: CLK->PCKENR1 |= CLK_PCKENR1_TIM2;   // Enable clock for TIMER2.
	bset	20679, #5
;	src/CLK.c: 9: CLK->PCKENR2 |= CLK_PCKENR2_ADC;    // Enable clock for ADC.
	bset	20682, #3
;	src/CLK.c: 10: }
	ret
;	src/CLK.c: 12: void CLK_Deinit (void){
;	-----------------------------------------
;	 function CLK_Deinit
;	-----------------------------------------
_CLK_Deinit:
;	src/CLK.c: 13: CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable all clocking.
	ld	a, 0x50c7
	mov	0x50c7+0, #0x00
;	src/CLK.c: 14: CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable all clocking.
	ld	a, 0x50ca
	mov	0x50ca+0, #0x00
;	src/CLK.c: 15: CLK->CKDIVR &= ~CLK_CKDIVR_RESET_VALUE;   // Disable all divider.
	ld	a, 0x50c6
	and	a, #0xe7
	ld	0x50c6, a
;	src/CLK.c: 16: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

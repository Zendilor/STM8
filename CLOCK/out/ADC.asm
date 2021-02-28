;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module ADC
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Get_Result
	.globl _ADC_Config
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
;	src/ADC.c: 4: void ADC_Config (void){
;	-----------------------------------------
;	 function ADC_Config
;	-----------------------------------------
_ADC_Config:
;	src/ADC.c: 5: ADC1->CR1 |= 0x70;            // Set ADC division 18.
	ld	a, 0x5401
	or	a, #0x70
	ld	0x5401, a
;	src/ADC.c: 6: ADC1->CSR |= 0x02;            // Set CH 2.
	bset	21504, #1
;	src/ADC.c: 7: ADC1->CSR |= ADC1_CSR_EOCIE;  // Enable interrupt.
	bset	21504, #5
;	src/ADC.c: 8: ADC1->CR2 |= ADC1_CR2_ALIGN;  // Align data to righ.
	bset	21506, #3
;	src/ADC.c: 9: ADC1->CR1 |= ADC1_CR1_ADON;   // Enable ADC.
	bset	21505, #0
;	src/ADC.c: 10: ADC1->CR1 |= ADC1_CR1_ADON;   // Start scan.
	bset	21505, #0
;	src/ADC.c: 11: }
	ret
;	src/ADC.c: 13: int Get_Result (void){
;	-----------------------------------------
;	 function Get_Result
;	-----------------------------------------
_Get_Result:
	sub	sp, #4
;	src/ADC.c: 14: int data = ADC1->DRL;
	ld	a, 0x5405
	clrw	x
	ld	xl, a
	ldw	(0x01, sp), x
;	src/ADC.c: 15: data |= ADC1->DRH << 8;
	ld	a, 0x5404
	clr	(0x04, sp)
	or	a, (0x01, sp)
	ld	xh, a
	ld	a, (0x02, sp)
	or	a, (0x04, sp)
	ld	xl, a
;	src/ADC.c: 16: return data;
;	src/ADC.c: 17: }
	addw	sp, #4
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

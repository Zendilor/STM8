;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module GPIO
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _GPIO_Config
	.globl _GPIOB_Config
	.globl _GPIOD_Config
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
;	src/GPIO.c: 6: void GPIO_Config (void){
;	-----------------------------------------
;	 function GPIO_Config
;	-----------------------------------------
_GPIO_Config:
;	src/GPIO.c: 8: GPIOD_Config();
;	src/GPIO.c: 9: }
	jp	_GPIOD_Config
;	src/GPIO.c: 11: void GPIOB_Config (void){
;	-----------------------------------------
;	 function GPIOB_Config
;	-----------------------------------------
_GPIOB_Config:
;	src/GPIO.c: 12: GPIOB->DDR |= 0x20; // Set PB5 as out.
	bset	20487, #5
;	src/GPIO.c: 13: GPIOB->CR1 |= 0x20; // Set PB5 as push-pull.
	bset	20488, #5
;	src/GPIO.c: 14: GPIOB->ODR &= ~0x20; // Set hlvl to PB5.
	bres	20485, #5
;	src/GPIO.c: 15: }
	ret
;	src/GPIO.c: 17: void GPIOD_Config (void){
;	-----------------------------------------
;	 function GPIOD_Config
;	-----------------------------------------
_GPIOD_Config:
;	src/GPIO.c: 18: GPIOD->DDR &= ~0x40;  // Set PD6 as input.
	bres	20497, #6
;	src/GPIO.c: 19: GPIOD->CR1 &= ~0x40;  // Set PD6 floating input.
	bres	20498, #6
;	src/GPIO.c: 21: GPIOD->DDR |= 0x10;
	bset	20497, #4
;	src/GPIO.c: 22: GPIOD->CR1 |= 0x10;
	bset	20498, #4
;	src/GPIO.c: 23: GPIOD->ODR |= 0x10;
	bset	20495, #4
;	src/GPIO.c: 24: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

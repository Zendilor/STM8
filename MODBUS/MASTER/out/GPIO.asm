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
;	src/GPIO.c: 7: GPIOD_Config();
;	src/GPIO.c: 8: }
	jp	_GPIOD_Config
;	src/GPIO.c: 10: void GPIOD_Config (void){
;	-----------------------------------------
;	 function GPIOD_Config
;	-----------------------------------------
_GPIOD_Config:
;	src/GPIO.c: 11: GPIOD->DDR |= 0x20;   // Set PD5(UART_TX) as out.
	bset	20497, #5
;	src/GPIO.c: 12: GPIOD->DDR &= 0x40;   // Set PD6(UART_RX) as input.
	ld	a, 0x5011
	and	a, #0x40
	ld	0x5011, a
;	src/GPIO.c: 15: GPIOD->CR1 |= 0x20;   // Set PD5(UART_TX) push-pull out.
	bset	20498, #5
;	src/GPIO.c: 16: GPIOD->CR1 &= 0x40;   // Set PD6(UART_RX) floating input.
	ld	a, 0x5012
	and	a, #0x40
	ld	0x5012, a
;	src/GPIO.c: 19: GPIOD->CR2 &= 0x20;   // Set speed for PD5(UART_TX) 2 MHz.
	ld	a, 0x5013
	and	a, #0x20
	ld	0x5013, a
;	src/GPIO.c: 20: GPIOD->CR2 &= 0x40;   // External interrupt disable.
	ld	a, 0x5013
	and	a, #0x40
	ld	0x5013, a
;	src/GPIO.c: 21: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

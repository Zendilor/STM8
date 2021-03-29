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
	.globl _GPIOC_Config
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
;	src/GPIO.c: 8: void GPIO_Config (void){
;	-----------------------------------------
;	 function GPIO_Config
;	-----------------------------------------
_GPIO_Config:
;	src/GPIO.c: 9: GPIOB_Config();
	call	_GPIOB_Config
;	src/GPIO.c: 10: GPIOC_Config();
	call	_GPIOC_Config
;	src/GPIO.c: 11: GPIOD_Config();
	jp	_GPIOD_Config
00101$:
;	src/GPIO.c: 12: }
	ret
;	src/GPIO.c: 14: void GPIOB_Config (void){
;	-----------------------------------------
;	 function GPIOB_Config
;	-----------------------------------------
_GPIOB_Config:
;	src/GPIO.c: 16: GPIOB->DDR |= 0x10;   // Set PB4 as out.
	ld	a, 0x5007
	or	a, #0x10
	ld	0x5007, a
;	src/GPIO.c: 17: GPIOB->DDR |= 0x20;   // Set PB5 as out.
	ld	a, 0x5007
	or	a, #0x20
	ld	0x5007, a
;	src/GPIO.c: 20: GPIOB->CR1 &= ~0x10;  // Set PB4 as open drain.
	ld	a, 0x5008
	and	a, #0xef
	ld	0x5008, a
;	src/GPIO.c: 21: GPIOB->CR1 &= ~0x20;  // Set PB5 as open drain.
	ld	a, 0x5008
	and	a, #0xdf
	ld	0x5008, a
;	src/GPIO.c: 24: GPIOB->CR2 &= ~0x10;  // Set speed for PB4 2 MHz.
	ld	a, 0x5009
	and	a, #0xef
	ld	0x5009, a
;	src/GPIO.c: 25: GPIOB->CR2 &= ~0x20;  // Set speed for PB5 2 MHz.
	ld	a, 0x5009
	and	a, #0xdf
	ld	0x5009, a
;	src/GPIO.c: 28: GPIOB->ODR |= 0x10;   // Set hlvl on PB4.
	ld	a, 0x5005
	or	a, #0x10
	ld	0x5005, a
;	src/GPIO.c: 29: GPIOB->ODR |= 0x20;   // Set hlvl on PB5.
	ld	a, 0x5005
	or	a, #0x20
	ld	0x5005, a
00101$:
;	src/GPIO.c: 30: }
	ret
;	src/GPIO.c: 32: void GPIOC_Config (void){
;	-----------------------------------------
;	 function GPIOC_Config
;	-----------------------------------------
_GPIOC_Config:
;	src/GPIO.c: 34: GPIOC->DDR |= 0x08;   // Set PC3 as out.
	ld	a, 0x500c
	or	a, #0x08
	ld	0x500c, a
;	src/GPIO.c: 35: GPIOC->DDR |= 0x10;   // Set PC4 as out.
	ld	a, 0x500c
	or	a, #0x10
	ld	0x500c, a
;	src/GPIO.c: 36: GPIOC->DDR |= 0x20;   // Set PC5 as out.
	ld	a, 0x500c
	or	a, #0x20
	ld	0x500c, a
;	src/GPIO.c: 37: GPIOC->DDR |= 0x40;   // Set PC6 as out.
	ld	a, 0x500c
	or	a, #0x40
	ld	0x500c, a
;	src/GPIO.c: 38: GPIOC->DDR |= 0x80;   // Set PC7 as out.
	ld	a, 0x500c
	or	a, #0x80
	ld	0x500c, a
;	src/GPIO.c: 41: GPIOC->CR1 |= 0x08;   // Set PC3 as push pull.
	ld	a, 0x500d
	or	a, #0x08
	ld	0x500d, a
;	src/GPIO.c: 42: GPIOC->CR1 |= 0x10;   // Set PC4 as push pull.
	ld	a, 0x500d
	or	a, #0x10
	ld	0x500d, a
;	src/GPIO.c: 43: GPIOC->CR1 |= 0x20;   // Set PC5 as push pull.
	ld	a, 0x500d
	or	a, #0x20
	ld	0x500d, a
;	src/GPIO.c: 44: GPIOC->CR1 |= 0x40;   // Set PC6 as push pull.
	ld	a, 0x500d
	or	a, #0x40
	ld	0x500d, a
;	src/GPIO.c: 45: GPIOC->CR1 |= 0x80;   // Set PC7 as push pull.
	ld	a, 0x500d
	or	a, #0x80
	ld	0x500d, a
;	src/GPIO.c: 48: GPIOC->CR2 &= ~0x08;  // Set speed for PC3 2 MHz.
	ld	a, 0x500e
	and	a, #0xf7
	ld	0x500e, a
;	src/GPIO.c: 49: GPIOC->CR2 &= ~0x10;  // Set speed for PC4 2 MHz.
	ld	a, 0x500e
	and	a, #0xef
	ld	0x500e, a
;	src/GPIO.c: 50: GPIOC->CR2 &= ~0x20;  // Set speed for PC5 2 MHz.
	ld	a, 0x500e
	and	a, #0xdf
	ld	0x500e, a
;	src/GPIO.c: 51: GPIOC->CR2 &= ~0x40;  // Set speed for PC6 2 MHz.
	ld	a, 0x500e
	and	a, #0xbf
	ld	0x500e, a
;	src/GPIO.c: 52: GPIOC->CR2 &= ~0x80;  // Set speed for PC7 2 MHz.
	ld	a, 0x500e
	and	a, #0x7f
	ld	0x500e, a
;	src/GPIO.c: 55: GPIOC->ODR |= 0x08;   // Set hlvl on PC3.
	ld	a, 0x500a
	or	a, #0x08
	ld	0x500a, a
;	src/GPIO.c: 56: GPIOC->ODR &= ~0x10;  // Set llvl on PC4.
	ld	a, 0x500a
	and	a, #0xef
	ld	0x500a, a
;	src/GPIO.c: 57: GPIOC->ODR &= ~0x20;  // Set llvl on PC5.
	ld	a, 0x500a
	and	a, #0xdf
	ld	0x500a, a
;	src/GPIO.c: 58: GPIOC->ODR &= ~0x40;  // Set llvl on PC6.
	ld	a, 0x500a
	and	a, #0xbf
	ld	0x500a, a
;	src/GPIO.c: 59: GPIOC->ODR &= ~0x80;  // Set llvl on PC7.
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
00101$:
;	src/GPIO.c: 61: }
	ret
;	src/GPIO.c: 63: void GPIOD_Config (void){
;	-----------------------------------------
;	 function GPIOD_Config
;	-----------------------------------------
_GPIOD_Config:
;	src/GPIO.c: 65: GPIOD->DDR |= 0x04;   // Set PD2 as out.
	ld	a, 0x5011
	or	a, #0x04
	ld	0x5011, a
;	src/GPIO.c: 66: GPIOD->DDR |= 0x08;   // Set PD3 as out.
	ld	a, 0x5011
	or	a, #0x08
	ld	0x5011, a
;	src/GPIO.c: 67: GPIOD->DDR |= 0x10;   // Set PD4 as out.
	ld	a, 0x5011
	or	a, #0x10
	ld	0x5011, a
;	src/GPIO.c: 68: GPIOD->DDR |= 0x20;   // Set PD5 as out.
	ld	a, 0x5011
	or	a, #0x20
	ld	0x5011, a
;	src/GPIO.c: 69: GPIOD->DDR &= ~0x40;   // Set PD6 as input.
	ld	a, 0x5011
	and	a, #0xbf
	ld	0x5011, a
;	src/GPIO.c: 72: GPIOD->CR1 |= 0x04;   // Set PD2 as push pull.
	ld	a, 0x5012
	or	a, #0x04
	ld	0x5012, a
;	src/GPIO.c: 73: GPIOD->CR1 |= 0x08;   // Set PD3 as push pull.
	ld	a, 0x5012
	or	a, #0x08
	ld	0x5012, a
;	src/GPIO.c: 74: GPIOD->CR1 |= 0x10;   // Set PD4 as push pull.
	ld	a, 0x5012
	or	a, #0x10
	ld	0x5012, a
;	src/GPIO.c: 75: GPIOD->CR1 |= 0x20;   // Set PD5 as push pull.
	ld	a, 0x5012
	or	a, #0x20
	ld	0x5012, a
;	src/GPIO.c: 76: GPIOD->CR1 &= ~0x40;   // Set PD6 as floating input.
	ld	a, 0x5012
	and	a, #0xbf
	ld	0x5012, a
;	src/GPIO.c: 79: GPIOD->CR2 &= ~0x04;   // Set speed for PD2 2 MHz.
	ld	a, 0x5013
	and	a, #0xfb
	ld	0x5013, a
;	src/GPIO.c: 80: GPIOD->CR2 &= ~0x08;   // Set speed for PD3 2 MHz.
	ld	a, 0x5013
	and	a, #0xf7
	ld	0x5013, a
;	src/GPIO.c: 81: GPIOD->CR2 &= ~0x10;   // Set speed for PD4 2 MHz.
	ld	a, 0x5013
	and	a, #0xef
	ld	0x5013, a
;	src/GPIO.c: 82: GPIOD->CR2 &= ~0x20;   // Set speed for PD5 2 MHz.
	ld	a, 0x5013
	and	a, #0xdf
	ld	0x5013, a
;	src/GPIO.c: 83: GPIOD->CR2 &= ~0x40;   // External interrupt disable for PD6.
	ld	a, 0x5013
	and	a, #0xbf
	ld	0x5013, a
;	src/GPIO.c: 86: GPIOD->ODR &= ~0x04;   // Set llvl on PD2.
	ld	a, 0x500f
	and	a, #0xfb
	ld	0x500f, a
;	src/GPIO.c: 87: GPIOD->ODR &= ~0x08;   // Set llvl on PD3.
	ld	a, 0x500f
	and	a, #0xf7
	ld	0x500f, a
;	src/GPIO.c: 88: GPIOD->ODR &= ~0x10;   // Set llvl on PD4.
	ld	a, 0x500f
	and	a, #0xef
	ld	0x500f, a
;	src/GPIO.c: 89: GPIOD->ODR &= ~0x20;   // Set llvl on PD5.
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
00101$:
;	src/GPIO.c: 90: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

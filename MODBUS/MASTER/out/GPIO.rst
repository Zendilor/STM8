                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module GPIO
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _GPIO_Config
                                     12 	.globl _GPIOD_Config
                                     13 ;--------------------------------------------------------
                                     14 ; ram data
                                     15 ;--------------------------------------------------------
                                     16 	.area DATA
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area INITIALIZED
                                     21 ;--------------------------------------------------------
                                     22 ; absolute external ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area DABS (ABS)
                                     25 
                                     26 ; default segment ordering for linker
                                     27 	.area HOME
                                     28 	.area GSINIT
                                     29 	.area GSFINAL
                                     30 	.area CONST
                                     31 	.area INITIALIZER
                                     32 	.area CODE
                                     33 
                                     34 ;--------------------------------------------------------
                                     35 ; global & static initialisations
                                     36 ;--------------------------------------------------------
                                     37 	.area HOME
                                     38 	.area GSINIT
                                     39 	.area GSFINAL
                                     40 	.area GSINIT
                                     41 ;--------------------------------------------------------
                                     42 ; Home
                                     43 ;--------------------------------------------------------
                                     44 	.area HOME
                                     45 	.area HOME
                                     46 ;--------------------------------------------------------
                                     47 ; code
                                     48 ;--------------------------------------------------------
                                     49 	.area CODE
                                     50 ;	src/GPIO.c: 6: void GPIO_Config (void){
                                     51 ;	-----------------------------------------
                                     52 ;	 function GPIO_Config
                                     53 ;	-----------------------------------------
      0080A1                         54 _GPIO_Config:
                                     55 ;	src/GPIO.c: 7: GPIOD_Config();
                                     56 ;	src/GPIO.c: 8: }
      0080A1 CC 80 A4         [ 2]   57 	jp	_GPIOD_Config
                                     58 ;	src/GPIO.c: 10: void GPIOD_Config (void){
                                     59 ;	-----------------------------------------
                                     60 ;	 function GPIOD_Config
                                     61 ;	-----------------------------------------
      0080A4                         62 _GPIOD_Config:
                                     63 ;	src/GPIO.c: 11: GPIOD->DDR |= 0x20;   // Set PD5(UART_TX) as out.
      0080A4 72 1A 50 11      [ 1]   64 	bset	20497, #5
                                     65 ;	src/GPIO.c: 12: GPIOD->DDR &= 0x40;   // Set PD6(UART_RX) as input.
      0080A8 C6 50 11         [ 1]   66 	ld	a, 0x5011
      0080AB A4 40            [ 1]   67 	and	a, #0x40
      0080AD C7 50 11         [ 1]   68 	ld	0x5011, a
                                     69 ;	src/GPIO.c: 15: GPIOD->CR1 |= 0x20;   // Set PD5(UART_TX) push-pull out.
      0080B0 72 1A 50 12      [ 1]   70 	bset	20498, #5
                                     71 ;	src/GPIO.c: 16: GPIOD->CR1 &= 0x40;   // Set PD6(UART_RX) floating input.
      0080B4 C6 50 12         [ 1]   72 	ld	a, 0x5012
      0080B7 A4 40            [ 1]   73 	and	a, #0x40
      0080B9 C7 50 12         [ 1]   74 	ld	0x5012, a
                                     75 ;	src/GPIO.c: 19: GPIOD->CR2 &= 0x20;   // Set speed for PD5(UART_TX) 2 MHz.
      0080BC C6 50 13         [ 1]   76 	ld	a, 0x5013
      0080BF A4 20            [ 1]   77 	and	a, #0x20
      0080C1 C7 50 13         [ 1]   78 	ld	0x5013, a
                                     79 ;	src/GPIO.c: 20: GPIOD->CR2 &= 0x40;   // External interrupt disable.
      0080C4 C6 50 13         [ 1]   80 	ld	a, 0x5013
      0080C7 A4 40            [ 1]   81 	and	a, #0x40
      0080C9 C7 50 13         [ 1]   82 	ld	0x5013, a
                                     83 ;	src/GPIO.c: 21: }
      0080CC 81               [ 4]   84 	ret
                                     85 	.area CODE
                                     86 	.area CONST
                                     87 	.area INITIALIZER
                                     88 	.area CABS (ABS)

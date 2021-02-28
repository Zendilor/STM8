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
                                     12 	.globl _GPIOB_Config
                                     13 	.globl _GPIOD_Config
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
                                     22 ;--------------------------------------------------------
                                     23 ; absolute external ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DABS (ABS)
                                     26 
                                     27 ; default segment ordering for linker
                                     28 	.area HOME
                                     29 	.area GSINIT
                                     30 	.area GSFINAL
                                     31 	.area CONST
                                     32 	.area INITIALIZER
                                     33 	.area CODE
                                     34 
                                     35 ;--------------------------------------------------------
                                     36 ; global & static initialisations
                                     37 ;--------------------------------------------------------
                                     38 	.area HOME
                                     39 	.area GSINIT
                                     40 	.area GSFINAL
                                     41 	.area GSINIT
                                     42 ;--------------------------------------------------------
                                     43 ; Home
                                     44 ;--------------------------------------------------------
                                     45 	.area HOME
                                     46 	.area HOME
                                     47 ;--------------------------------------------------------
                                     48 ; code
                                     49 ;--------------------------------------------------------
                                     50 	.area CODE
                                     51 ;	src/GPIO.c: 6: void GPIO_Config (void){
                                     52 ;	-----------------------------------------
                                     53 ;	 function GPIO_Config
                                     54 ;	-----------------------------------------
      0080E4                         55 _GPIO_Config:
                                     56 ;	src/GPIO.c: 8: GPIOD_Config();
                                     57 ;	src/GPIO.c: 9: }
      0080E4 CC 80 F4         [ 2]   58 	jp	_GPIOD_Config
                                     59 ;	src/GPIO.c: 11: void GPIOB_Config (void){
                                     60 ;	-----------------------------------------
                                     61 ;	 function GPIOB_Config
                                     62 ;	-----------------------------------------
      0080E7                         63 _GPIOB_Config:
                                     64 ;	src/GPIO.c: 12: GPIOB->DDR |= 0x20; // Set PB5 as out.
      0080E7 72 1A 50 07      [ 1]   65 	bset	20487, #5
                                     66 ;	src/GPIO.c: 13: GPIOB->CR1 |= 0x20; // Set PB5 as push-pull.
      0080EB 72 1A 50 08      [ 1]   67 	bset	20488, #5
                                     68 ;	src/GPIO.c: 14: GPIOB->ODR &= ~0x20; // Set hlvl to PB5.
      0080EF 72 1B 50 05      [ 1]   69 	bres	20485, #5
                                     70 ;	src/GPIO.c: 15: }
      0080F3 81               [ 4]   71 	ret
                                     72 ;	src/GPIO.c: 17: void GPIOD_Config (void){
                                     73 ;	-----------------------------------------
                                     74 ;	 function GPIOD_Config
                                     75 ;	-----------------------------------------
      0080F4                         76 _GPIOD_Config:
                                     77 ;	src/GPIO.c: 18: GPIOD->DDR &= ~0x40;  // Set PD6 as input.
      0080F4 72 1D 50 11      [ 1]   78 	bres	20497, #6
                                     79 ;	src/GPIO.c: 19: GPIOD->CR1 &= ~0x40;  // Set PD6 floating input.
      0080F8 72 1D 50 12      [ 1]   80 	bres	20498, #6
                                     81 ;	src/GPIO.c: 21: GPIOD->DDR |= 0x10;
      0080FC 72 18 50 11      [ 1]   82 	bset	20497, #4
                                     83 ;	src/GPIO.c: 22: GPIOD->CR1 |= 0x10;
      008100 72 18 50 12      [ 1]   84 	bset	20498, #4
                                     85 ;	src/GPIO.c: 23: GPIOD->ODR |= 0x10;
      008104 72 18 50 0F      [ 1]   86 	bset	20495, #4
                                     87 ;	src/GPIO.c: 24: }
      008108 81               [ 4]   88 	ret
                                     89 	.area CODE
                                     90 	.area CONST
                                     91 	.area INITIALIZER
                                     92 	.area CABS (ABS)

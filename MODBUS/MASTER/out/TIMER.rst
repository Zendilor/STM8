                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module TIMER
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _TIMER_Config
                                     12 	.globl _Divider
                                     13 	.globl _TIMER2_Config
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
      000007                         22 _Divider::
      000007                         23 	.ds 2
                                     24 ;--------------------------------------------------------
                                     25 ; absolute external ram data
                                     26 ;--------------------------------------------------------
                                     27 	.area DABS (ABS)
                                     28 
                                     29 ; default segment ordering for linker
                                     30 	.area HOME
                                     31 	.area GSINIT
                                     32 	.area GSFINAL
                                     33 	.area CONST
                                     34 	.area INITIALIZER
                                     35 	.area CODE
                                     36 
                                     37 ;--------------------------------------------------------
                                     38 ; global & static initialisations
                                     39 ;--------------------------------------------------------
                                     40 	.area HOME
                                     41 	.area GSINIT
                                     42 	.area GSFINAL
                                     43 	.area GSINIT
                                     44 ;--------------------------------------------------------
                                     45 ; Home
                                     46 ;--------------------------------------------------------
                                     47 	.area HOME
                                     48 	.area HOME
                                     49 ;--------------------------------------------------------
                                     50 ; code
                                     51 ;--------------------------------------------------------
                                     52 	.area CODE
                                     53 ;	src/TIMER.c: 7: void TIMER_Config (void){
                                     54 ;	-----------------------------------------
                                     55 ;	 function TIMER_Config
                                     56 ;	-----------------------------------------
      0081AA                         57 _TIMER_Config:
                                     58 ;	src/TIMER.c: 8: TIMER2_Config();
                                     59 ;	src/TIMER.c: 9: }
      0081AA CC 81 AD         [ 2]   60 	jp	_TIMER2_Config
                                     61 ;	src/TIMER.c: 11: void TIMER2_Config (void){
                                     62 ;	-----------------------------------------
                                     63 ;	 function TIMER2_Config
                                     64 ;	-----------------------------------------
      0081AD                         65 _TIMER2_Config:
                                     66 ;	src/TIMER.c: 12: TIM2->ARRH = Divider >> 8;    // High byte counter.
      0081AD C6 00 07         [ 1]   67 	ld	a, _Divider+0
      0081B0 C7 53 0F         [ 1]   68 	ld	0x530f, a
                                     69 ;	src/TIMER.c: 13: TIM2->ARRL = Divider;         // Low byte counter.
      0081B3 C6 00 08         [ 1]   70 	ld	a, _Divider+1
      0081B6 C7 53 10         [ 1]   71 	ld	0x5310, a
                                     72 ;	src/TIMER.c: 14: TIM2->IER |= TIM2_IER_UIE;    // Enable interrupt update.
      0081B9 72 10 53 03      [ 1]   73 	bset	21251, #0
                                     74 ;	src/TIMER.c: 15: TIM2->PSCR = 10;              // Set prescaler for TIMER2.
      0081BD 35 0A 53 0E      [ 1]   75 	mov	0x530e+0, #0x0a
                                     76 ;	src/TIMER.c: 16: TIM2->CR1 |= TIM2_CR1_ARPE;   // Auto-reload preload enable.
      0081C1 72 1E 53 00      [ 1]   77 	bset	21248, #7
                                     78 ;	src/TIMER.c: 17: TIM2->CR1 |= TIM2_CR1_CEN;    // Enable counter.
      0081C5 72 10 53 00      [ 1]   79 	bset	21248, #0
                                     80 ;	src/TIMER.c: 18: }
      0081C9 81               [ 4]   81 	ret
                                     82 	.area CODE
                                     83 	.area CONST
                                     84 	.area INITIALIZER
      008074                         85 __xinit__Divider:
      008074 3D 09                   86 	.dw #0x3d09
                                     87 	.area CABS (ABS)

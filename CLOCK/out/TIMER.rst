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
                                     11 	.globl _TIMER1_Config
                                     12 	.globl _TIMER_Config
                                     13 	.globl _Duty
                                     14 	.globl _Divider
                                     15 	.globl _TIMER2_Config
                                     16 ;--------------------------------------------------------
                                     17 ; ram data
                                     18 ;--------------------------------------------------------
                                     19 	.area DATA
                                     20 ;--------------------------------------------------------
                                     21 ; ram data
                                     22 ;--------------------------------------------------------
                                     23 	.area INITIALIZED
      000001                         24 _Divider::
      000001                         25 	.ds 2
      000003                         26 _Duty::
      000003                         27 	.ds 1
                                     28 ;--------------------------------------------------------
                                     29 ; absolute external ram data
                                     30 ;--------------------------------------------------------
                                     31 	.area DABS (ABS)
                                     32 
                                     33 ; default segment ordering for linker
                                     34 	.area HOME
                                     35 	.area GSINIT
                                     36 	.area GSFINAL
                                     37 	.area CONST
                                     38 	.area INITIALIZER
                                     39 	.area CODE
                                     40 
                                     41 ;--------------------------------------------------------
                                     42 ; global & static initialisations
                                     43 ;--------------------------------------------------------
                                     44 	.area HOME
                                     45 	.area GSINIT
                                     46 	.area GSFINAL
                                     47 	.area GSINIT
                                     48 ;--------------------------------------------------------
                                     49 ; Home
                                     50 ;--------------------------------------------------------
                                     51 	.area HOME
                                     52 	.area HOME
                                     53 ;--------------------------------------------------------
                                     54 ; code
                                     55 ;--------------------------------------------------------
                                     56 	.area CODE
                                     57 ;	src/TIMER.c: 10: void TIMER_Config (void){
                                     58 ;	-----------------------------------------
                                     59 ;	 function TIMER_Config
                                     60 ;	-----------------------------------------
      008192                         61 _TIMER_Config:
                                     62 ;	src/TIMER.c: 11: TIMER2_Config();
                                     63 ;	src/TIMER.c: 13: }
      008192 CC 81 9E         [ 2]   64 	jp	_TIMER2_Config
                                     65 ;	src/TIMER.c: 15: void TIMER1_Config (void){
                                     66 ;	-----------------------------------------
                                     67 ;	 function TIMER1_Config
                                     68 ;	-----------------------------------------
      008195                         69 _TIMER1_Config:
                                     70 ;	src/TIMER.c: 16: TIM1->CR1 |= TIM1_CR1_ARPE; // Enable preload.
      008195 72 1E 52 50      [ 1]   71 	bset	21072, #7
                                     72 ;	src/TIMER.c: 18: TIM1->CR1 |= TIM1_CR1_CEN;   // Enable TIM1.
      008199 72 10 52 50      [ 1]   73 	bset	21072, #0
                                     74 ;	src/TIMER.c: 19: }
      00819D 81               [ 4]   75 	ret
                                     76 ;	src/TIMER.c: 21: void TIMER2_Config (void){
                                     77 ;	-----------------------------------------
                                     78 ;	 function TIMER2_Config
                                     79 ;	-----------------------------------------
      00819E                         80 _TIMER2_Config:
                                     81 ;	src/TIMER.c: 22: TIM2->CCR1H = ((Divider * Duty) / 100) >> 8;
      00819E 5F               [ 1]   82 	clrw	x
      00819F C6 00 03         [ 1]   83 	ld	a, _Duty+0
      0081A2 97               [ 1]   84 	ld	xl, a
      0081A3 89               [ 2]   85 	pushw	x
      0081A4 3B 00 02         [ 1]   86 	push	_Divider+1
      0081A7 3B 00 01         [ 1]   87 	push	_Divider+0
      0081AA CD 84 11         [ 4]   88 	call	__mulint
      0081AD 5B 04            [ 2]   89 	addw	sp, #4
      0081AF 90 AE 00 64      [ 2]   90 	ldw	y, #0x0064
      0081B3 65               [ 2]   91 	divw	x, y
      0081B4 9E               [ 1]   92 	ld	a, xh
      0081B5 C7 53 11         [ 1]   93 	ld	0x5311, a
                                     94 ;	src/TIMER.c: 23: TIM2->CCR1L = (Divider * Duty) / 100;
      0081B8 5F               [ 1]   95 	clrw	x
      0081B9 C6 00 03         [ 1]   96 	ld	a, _Duty+0
      0081BC 97               [ 1]   97 	ld	xl, a
      0081BD 89               [ 2]   98 	pushw	x
      0081BE 3B 00 02         [ 1]   99 	push	_Divider+1
      0081C1 3B 00 01         [ 1]  100 	push	_Divider+0
      0081C4 CD 84 11         [ 4]  101 	call	__mulint
      0081C7 5B 04            [ 2]  102 	addw	sp, #4
      0081C9 90 AE 00 64      [ 2]  103 	ldw	y, #0x0064
      0081CD 65               [ 2]  104 	divw	x, y
      0081CE 9F               [ 1]  105 	ld	a, xl
      0081CF C7 53 12         [ 1]  106 	ld	0x5312, a
                                    107 ;	src/TIMER.c: 24: TIM2->ARRH = Divider >> 8;
      0081D2 C6 00 01         [ 1]  108 	ld	a, _Divider+0
      0081D5 5F               [ 1]  109 	clrw	x
      0081D6 C7 53 0F         [ 1]  110 	ld	0x530f, a
                                    111 ;	src/TIMER.c: 25: TIM2->ARRL = Divider;
      0081D9 C6 00 02         [ 1]  112 	ld	a, _Divider+1
      0081DC C7 53 10         [ 1]  113 	ld	0x5310, a
                                    114 ;	src/TIMER.c: 26: TIM2->CCMR1 |= 0x60;        // Set PWM 1 mode.
      0081DF C6 53 07         [ 1]  115 	ld	a, 0x5307
      0081E2 AA 60            [ 1]  116 	or	a, #0x60
      0081E4 C7 53 07         [ 1]  117 	ld	0x5307, a
                                    118 ;	src/TIMER.c: 27: TIM2->CCMR1 |= 0x08;        // Output compare preload enable.
      0081E7 72 16 53 07      [ 1]  119 	bset	21255, #3
                                    120 ;	src/TIMER.c: 28: TIM2->CCER1 |= TIM2_CCER1_CC1E;
      0081EB 72 10 53 0A      [ 1]  121 	bset	21258, #0
                                    122 ;	src/TIMER.c: 30: TIM2->PSCR = 1;          // Prescaler 1.
      0081EF 35 01 53 0E      [ 1]  123 	mov	0x530e+0, #0x01
                                    124 ;	src/TIMER.c: 31: TIM2->CR1 |= TIM2_CR1_CEN;   // Enable counter.
      0081F3 72 10 53 00      [ 1]  125 	bset	21248, #0
                                    126 ;	src/TIMER.c: 32: }
      0081F7 81               [ 4]  127 	ret
                                    128 	.area CODE
                                    129 	.area CONST
                                    130 	.area INITIALIZER
      008084                        131 __xinit__Divider:
      008084 FF FF                  132 	.dw #0xffff
      008086                        133 __xinit__Duty:
      008086 0A                     134 	.db #0x0a	; 10
                                    135 	.area CABS (ABS)

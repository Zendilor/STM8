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
                                     12 	.globl _TIM1_REL
                                     13 	.globl _TIM1_DIV
                                     14 	.globl _Duty
                                     15 	.globl _Divider
                                     16 	.globl _TIMER1_Config
                                     17 	.globl _TIMER2_Config
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area DATA
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area INITIALIZED
      00000B                         26 _Divider::
      00000B                         27 	.ds 2
      00000D                         28 _Duty::
      00000D                         29 	.ds 1
      00000E                         30 _TIM1_DIV::
      00000E                         31 	.ds 2
      000010                         32 _TIM1_REL::
      000010                         33 	.ds 2
                                     34 ;--------------------------------------------------------
                                     35 ; absolute external ram data
                                     36 ;--------------------------------------------------------
                                     37 	.area DABS (ABS)
                                     38 
                                     39 ; default segment ordering for linker
                                     40 	.area HOME
                                     41 	.area GSINIT
                                     42 	.area GSFINAL
                                     43 	.area CONST
                                     44 	.area INITIALIZER
                                     45 	.area CODE
                                     46 
                                     47 ;--------------------------------------------------------
                                     48 ; global & static initialisations
                                     49 ;--------------------------------------------------------
                                     50 	.area HOME
                                     51 	.area GSINIT
                                     52 	.area GSFINAL
                                     53 	.area GSINIT
                                     54 ;--------------------------------------------------------
                                     55 ; Home
                                     56 ;--------------------------------------------------------
                                     57 	.area HOME
                                     58 	.area HOME
                                     59 ;--------------------------------------------------------
                                     60 ; code
                                     61 ;--------------------------------------------------------
                                     62 	.area CODE
                                     63 ;	src/TIMER.c: 14: void TIMER_Config (void){
                                     64 ;	-----------------------------------------
                                     65 ;	 function TIMER_Config
                                     66 ;	-----------------------------------------
      0086B9                         67 _TIMER_Config:
                                     68 ;	src/TIMER.c: 15: TIMER1_Config();
      0086B9 CD 86 C0         [ 4]   69 	call	_TIMER1_Config
                                     70 ;	src/TIMER.c: 16: TIMER2_Config();
      0086BC CC 86 FD         [ 2]   71 	jp	_TIMER2_Config
      0086BF                         72 00101$:
                                     73 ;	src/TIMER.c: 18: }
      0086BF 81               [ 4]   74 	ret
                                     75 ;	src/TIMER.c: 20: void TIMER1_Config (void){
                                     76 ;	-----------------------------------------
                                     77 ;	 function TIMER1_Config
                                     78 ;	-----------------------------------------
      0086C0                         79 _TIMER1_Config:
                                     80 ;	src/TIMER.c: 21: TIM1->CR1 |= TIM1_CR1_ARPE;   // Enable preload.
      0086C0 C6 52 50         [ 1]   81 	ld	a, 0x5250
      0086C3 AA 80            [ 1]   82 	or	a, #0x80
      0086C5 C7 52 50         [ 1]   83 	ld	0x5250, a
                                     84 ;	src/TIMER.c: 22: TIM1->PSCRH = TIM1_DIV >> 8;  // Set divider H byte.
      0086C8 C6 00 0E         [ 1]   85 	ld	a, _TIM1_DIV+0
      0086CB 5F               [ 1]   86 	clrw	x
      0086CC C7 52 60         [ 1]   87 	ld	0x5260, a
                                     88 ;	src/TIMER.c: 23: TIM1->PSCRL = TIM1_DIV;       // Set divider L byte.
      0086CF C6 00 0F         [ 1]   89 	ld	a, _TIM1_DIV+1
      0086D2 C7 52 61         [ 1]   90 	ld	0x5261, a
                                     91 ;	src/TIMER.c: 24: TIM1->ARRH = TIM1_REL > 8;    // Set autoreload H value.
      0086D5 CE 00 10         [ 2]   92 	ldw	x, _TIM1_REL+0
      0086D8 A3 00 08         [ 2]   93 	cpw	x, #0x0008
      0086DB 22 04            [ 1]   94 	jrugt	00103$
      0086DD 4F               [ 1]   95 	clr	a
      0086DE CC 86 E3         [ 2]   96 	jp	00104$
      0086E1                         97 00103$:
      0086E1 A6 01            [ 1]   98 	ld	a, #0x01
      0086E3                         99 00104$:
      0086E3 C7 52 62         [ 1]  100 	ld	0x5262, a
                                    101 ;	src/TIMER.c: 25: TIM1->ARRL = TIM1_REL;        // Set autoreload l value.
      0086E6 C6 00 11         [ 1]  102 	ld	a, _TIM1_REL+1
      0086E9 C7 52 63         [ 1]  103 	ld	0x5263, a
                                    104 ;	src/TIMER.c: 26: TIM1->IER |= TIM1_IER_UIE;    // Enable interrupt.
      0086EC C6 52 54         [ 1]  105 	ld	a, 0x5254
      0086EF AA 01            [ 1]  106 	or	a, #0x01
      0086F1 C7 52 54         [ 1]  107 	ld	0x5254, a
                                    108 ;	src/TIMER.c: 27: TIM1->CR1 |= TIM1_CR1_CEN;    // Enable TIM1.
      0086F4 C6 52 50         [ 1]  109 	ld	a, 0x5250
      0086F7 AA 01            [ 1]  110 	or	a, #0x01
      0086F9 C7 52 50         [ 1]  111 	ld	0x5250, a
      0086FC                        112 00101$:
                                    113 ;	src/TIMER.c: 28: }
      0086FC 81               [ 4]  114 	ret
                                    115 ;	src/TIMER.c: 30: void TIMER2_Config (void){
                                    116 ;	-----------------------------------------
                                    117 ;	 function TIMER2_Config
                                    118 ;	-----------------------------------------
      0086FD                        119 _TIMER2_Config:
                                    120 ;	src/TIMER.c: 31: TIM2->ARRH = Divider >> 8;
      0086FD C6 00 0B         [ 1]  121 	ld	a, _Divider+0
      008700 5F               [ 1]  122 	clrw	x
      008701 C7 53 0F         [ 1]  123 	ld	0x530f, a
                                    124 ;	src/TIMER.c: 32: TIM2->ARRL = Divider;
      008704 C6 00 0C         [ 1]  125 	ld	a, _Divider+1
      008707 C7 53 10         [ 1]  126 	ld	0x5310, a
                                    127 ;	src/TIMER.c: 33: TIM2->IER |= TIM2_IER_UIE;  // Enable interrupt update.
      00870A C6 53 03         [ 1]  128 	ld	a, 0x5303
      00870D AA 01            [ 1]  129 	or	a, #0x01
      00870F C7 53 03         [ 1]  130 	ld	0x5303, a
                                    131 ;	src/TIMER.c: 34: TIM2->PSCR = 8;             // Prescaler 1.
      008712 35 08 53 0E      [ 1]  132 	mov	0x530e+0, #0x08
                                    133 ;	src/TIMER.c: 35: TIM2->CR1 |= TIM2_CR1_CEN;  // Enable counter.
      008716 C6 53 00         [ 1]  134 	ld	a, 0x5300
      008719 AA 01            [ 1]  135 	or	a, #0x01
      00871B C7 53 00         [ 1]  136 	ld	0x5300, a
      00871E                        137 00101$:
                                    138 ;	src/TIMER.c: 36: }
      00871E 81               [ 4]  139 	ret
                                    140 	.area CODE
                                    141 	.area CONST
                                    142 	.area INITIALIZER
      00808B                        143 __xinit__Divider:
      00808B 01 77                  144 	.dw #0x0177
      00808D                        145 __xinit__Duty:
      00808D 0A                     146 	.db #0x0a	; 10
      00808E                        147 __xinit__TIM1_DIV:
      00808E 27 10                  148 	.dw #0x2710
      008090                        149 __xinit__TIM1_REL:
      008090 06 40                  150 	.dw #0x0640
                                    151 	.area CABS (ABS)

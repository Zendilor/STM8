                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module CLK
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CLK_Config
                                     12 	.globl _CLK_Deinit
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
                                     50 ;	src/CLK.c: 5: void CLK_Config (void){
                                     51 ;	-----------------------------------------
                                     52 ;	 function CLK_Config
                                     53 ;	-----------------------------------------
      0080BD                         54 _CLK_Config:
                                     55 ;	src/CLK.c: 6: CLK_Deinit();
      0080BD CD 80 CD         [ 4]   56 	call	_CLK_Deinit
                                     57 ;	src/CLK.c: 7: CLK->PCKENR1 |= CLK_PCKENR1_UART2;  // Enable clock for UART1 (see datasheet).
      0080C0 72 16 50 C7      [ 1]   58 	bset	20679, #3
                                     59 ;	src/CLK.c: 8: CLK->PCKENR1 |= CLK_PCKENR1_TIM2;   // Enable clock for TIMER2.
      0080C4 72 1A 50 C7      [ 1]   60 	bset	20679, #5
                                     61 ;	src/CLK.c: 9: CLK->PCKENR2 |= CLK_PCKENR2_ADC;    // Enable clock for ADC.
      0080C8 72 16 50 CA      [ 1]   62 	bset	20682, #3
                                     63 ;	src/CLK.c: 10: }
      0080CC 81               [ 4]   64 	ret
                                     65 ;	src/CLK.c: 12: void CLK_Deinit (void){
                                     66 ;	-----------------------------------------
                                     67 ;	 function CLK_Deinit
                                     68 ;	-----------------------------------------
      0080CD                         69 _CLK_Deinit:
                                     70 ;	src/CLK.c: 13: CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable all clocking.
      0080CD C6 50 C7         [ 1]   71 	ld	a, 0x50c7
      0080D0 35 00 50 C7      [ 1]   72 	mov	0x50c7+0, #0x00
                                     73 ;	src/CLK.c: 14: CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable all clocking.
      0080D4 C6 50 CA         [ 1]   74 	ld	a, 0x50ca
      0080D7 35 00 50 CA      [ 1]   75 	mov	0x50ca+0, #0x00
                                     76 ;	src/CLK.c: 15: CLK->CKDIVR &= ~CLK_CKDIVR_RESET_VALUE;   // Disable all divider.
      0080DB C6 50 C6         [ 1]   77 	ld	a, 0x50c6
      0080DE A4 E7            [ 1]   78 	and	a, #0xe7
      0080E0 C7 50 C6         [ 1]   79 	ld	0x50c6, a
                                     80 ;	src/CLK.c: 16: }
      0080E3 81               [ 4]   81 	ret
                                     82 	.area CODE
                                     83 	.area CONST
                                     84 	.area INITIALIZER
                                     85 	.area CABS (ABS)

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
      00808C                         54 _CLK_Config:
                                     55 ;	src/CLK.c: 6: CLK_Deinit();
      00808C CD 80 94         [ 4]   56 	call	_CLK_Deinit
                                     57 ;	src/CLK.c: 7: CLK->PCKENR1 |= CLK_PCKENR1_UART2;  // Enable clock for UART1 (see datasheet).
      00808F 72 16 50 C7      [ 1]   58 	bset	20679, #3
                                     59 ;	src/CLK.c: 8: }
      008093 81               [ 4]   60 	ret
                                     61 ;	src/CLK.c: 10: void CLK_Deinit (void){
                                     62 ;	-----------------------------------------
                                     63 ;	 function CLK_Deinit
                                     64 ;	-----------------------------------------
      008094                         65 _CLK_Deinit:
                                     66 ;	src/CLK.c: 11: CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable all clocking.
      008094 C6 50 C7         [ 1]   67 	ld	a, 0x50c7
      008097 35 00 50 C7      [ 1]   68 	mov	0x50c7+0, #0x00
                                     69 ;	src/CLK.c: 12: CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable all clocking.
      00809B C6 50 CA         [ 1]   70 	ld	a, 0x50ca
      00809E 35 00 50 CA      [ 1]   71 	mov	0x50ca+0, #0x00
                                     72 ;	src/CLK.c: 13: CLK->CKDIVR &= ~CLK_CKDIVR_RESET_VALUE;   // Disable all divider.
      0080A2 C6 50 C6         [ 1]   73 	ld	a, 0x50c6
      0080A5 A4 E7            [ 1]   74 	and	a, #0xe7
      0080A7 C7 50 C6         [ 1]   75 	ld	0x50c6, a
                                     76 ;	src/CLK.c: 14: }
      0080AA 81               [ 4]   77 	ret
                                     78 	.area CODE
                                     79 	.area CONST
                                     80 	.area INITIALIZER
                                     81 	.area CABS (ABS)

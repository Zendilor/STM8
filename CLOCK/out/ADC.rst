                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module ADC
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Get_Result
                                     12 	.globl _ADC_Config
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
                                     50 ;	src/ADC.c: 4: void ADC_Config (void){
                                     51 ;	-----------------------------------------
                                     52 ;	 function ADC_Config
                                     53 ;	-----------------------------------------
      008087                         54 _ADC_Config:
                                     55 ;	src/ADC.c: 5: ADC1->CR1 |= 0x70;            // Set ADC division 18.
      008087 C6 54 01         [ 1]   56 	ld	a, 0x5401
      00808A AA 70            [ 1]   57 	or	a, #0x70
      00808C C7 54 01         [ 1]   58 	ld	0x5401, a
                                     59 ;	src/ADC.c: 6: ADC1->CSR |= 0x02;            // Set CH 2.
      00808F 72 12 54 00      [ 1]   60 	bset	21504, #1
                                     61 ;	src/ADC.c: 7: ADC1->CSR |= ADC1_CSR_EOCIE;  // Enable interrupt.
      008093 72 1A 54 00      [ 1]   62 	bset	21504, #5
                                     63 ;	src/ADC.c: 8: ADC1->CR2 |= ADC1_CR2_ALIGN;  // Align data to righ.
      008097 72 16 54 02      [ 1]   64 	bset	21506, #3
                                     65 ;	src/ADC.c: 9: ADC1->CR1 |= ADC1_CR1_ADON;   // Enable ADC.
      00809B 72 10 54 01      [ 1]   66 	bset	21505, #0
                                     67 ;	src/ADC.c: 10: ADC1->CR1 |= ADC1_CR1_ADON;   // Start scan.
      00809F 72 10 54 01      [ 1]   68 	bset	21505, #0
                                     69 ;	src/ADC.c: 11: }
      0080A3 81               [ 4]   70 	ret
                                     71 ;	src/ADC.c: 13: int Get_Result (void){
                                     72 ;	-----------------------------------------
                                     73 ;	 function Get_Result
                                     74 ;	-----------------------------------------
      0080A4                         75 _Get_Result:
      0080A4 52 04            [ 2]   76 	sub	sp, #4
                                     77 ;	src/ADC.c: 14: int data = ADC1->DRL;
      0080A6 C6 54 05         [ 1]   78 	ld	a, 0x5405
      0080A9 5F               [ 1]   79 	clrw	x
      0080AA 97               [ 1]   80 	ld	xl, a
      0080AB 1F 01            [ 2]   81 	ldw	(0x01, sp), x
                                     82 ;	src/ADC.c: 15: data |= ADC1->DRH << 8;
      0080AD C6 54 04         [ 1]   83 	ld	a, 0x5404
      0080B0 0F 04            [ 1]   84 	clr	(0x04, sp)
      0080B2 1A 01            [ 1]   85 	or	a, (0x01, sp)
      0080B4 95               [ 1]   86 	ld	xh, a
      0080B5 7B 02            [ 1]   87 	ld	a, (0x02, sp)
      0080B7 1A 04            [ 1]   88 	or	a, (0x04, sp)
      0080B9 97               [ 1]   89 	ld	xl, a
                                     90 ;	src/ADC.c: 16: return data;
                                     91 ;	src/ADC.c: 17: }
      0080BA 5B 04            [ 2]   92 	addw	sp, #4
      0080BC 81               [ 4]   93 	ret
                                     94 	.area CODE
                                     95 	.area CONST
                                     96 	.area INITIALIZER
                                     97 	.area CABS (ABS)

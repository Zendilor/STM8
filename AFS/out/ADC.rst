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
      00809A                         54 _ADC_Config:
                                     55 ;	src/ADC.c: 5: ADC1->CR1 |= 0x70;            // Set ADC division 18.
      00809A C6 54 01         [ 1]   56 	ld	a, 0x5401
      00809D AA 70            [ 1]   57 	or	a, #0x70
      00809F C7 54 01         [ 1]   58 	ld	0x5401, a
                                     59 ;	src/ADC.c: 6: ADC1->CSR |= 0x06;            // Set CH 6.
      0080A2 C6 54 00         [ 1]   60 	ld	a, 0x5400
      0080A5 AA 06            [ 1]   61 	or	a, #0x06
      0080A7 C7 54 00         [ 1]   62 	ld	0x5400, a
                                     63 ;	src/ADC.c: 7: ADC1->CSR |= ADC1_CSR_EOCIE;  // Enable interrupt.
      0080AA C6 54 00         [ 1]   64 	ld	a, 0x5400
      0080AD AA 20            [ 1]   65 	or	a, #0x20
      0080AF C7 54 00         [ 1]   66 	ld	0x5400, a
                                     67 ;	src/ADC.c: 8: ADC1->CR2 |= ADC1_CR2_ALIGN;  // Align data to righ.
      0080B2 C6 54 02         [ 1]   68 	ld	a, 0x5402
      0080B5 AA 08            [ 1]   69 	or	a, #0x08
      0080B7 C7 54 02         [ 1]   70 	ld	0x5402, a
                                     71 ;	src/ADC.c: 9: ADC1->CR1 |= ADC1_CR1_ADON;   // Enable ADC.
      0080BA C6 54 01         [ 1]   72 	ld	a, 0x5401
      0080BD AA 01            [ 1]   73 	or	a, #0x01
      0080BF C7 54 01         [ 1]   74 	ld	0x5401, a
                                     75 ;	src/ADC.c: 10: ADC1->CR1 |= ADC1_CR1_ADON;   // Start scan.
      0080C2 C6 54 01         [ 1]   76 	ld	a, 0x5401
      0080C5 AA 01            [ 1]   77 	or	a, #0x01
      0080C7 C7 54 01         [ 1]   78 	ld	0x5401, a
      0080CA                         79 00101$:
                                     80 ;	src/ADC.c: 11: }
      0080CA 81               [ 4]   81 	ret
                                     82 ;	src/ADC.c: 13: uint16_t Get_Result (void){
                                     83 ;	-----------------------------------------
                                     84 ;	 function Get_Result
                                     85 ;	-----------------------------------------
      0080CB                         86 _Get_Result:
      0080CB 52 04            [ 2]   87 	sub	sp, #4
                                     88 ;	src/ADC.c: 14: int data = ADC1->DRL;
      0080CD C6 54 05         [ 1]   89 	ld	a, 0x5405
      0080D0 5F               [ 1]   90 	clrw	x
      0080D1 97               [ 1]   91 	ld	xl, a
      0080D2 1F 01            [ 2]   92 	ldw	(0x01, sp), x
                                     93 ;	src/ADC.c: 15: data |= ADC1->DRH << 8;
      0080D4 C6 54 04         [ 1]   94 	ld	a, 0x5404
      0080D7 5F               [ 1]   95 	clrw	x
      0080D8 0F 04            [ 1]   96 	clr	(0x04, sp)
      0080DA 1A 01            [ 1]   97 	or	a, (0x01, sp)
      0080DC 95               [ 1]   98 	ld	xh, a
      0080DD 7B 02            [ 1]   99 	ld	a, (0x02, sp)
      0080DF 1A 04            [ 1]  100 	or	a, (0x04, sp)
      0080E1 97               [ 1]  101 	ld	xl, a
                                    102 ;	src/ADC.c: 16: return data;
      0080E2                        103 00101$:
                                    104 ;	src/ADC.c: 17: }
      0080E2 5B 04            [ 2]  105 	addw	sp, #4
      0080E4 81               [ 4]  106 	ret
                                    107 	.area CODE
                                    108 	.area CONST
                                    109 	.area INITIALIZER
                                    110 	.area CABS (ABS)

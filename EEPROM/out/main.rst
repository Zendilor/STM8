                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _IRQ_ADC
                                     12 	.globl _IRQ_TIMER2
                                     13 	.globl _IRQ_UART1_RX
                                     14 	.globl _main
                                     15 	.globl _CLK_Config
                                     16 	.globl _UART_Send
                                     17 	.globl _UART_Config
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area DATA
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area INITIALIZED
                                     26 ;--------------------------------------------------------
                                     27 ; Stack segment in internal ram 
                                     28 ;--------------------------------------------------------
                                     29 	.area	SSEG
      FFFFFF                         30 __start__stack:
      FFFFFF                         31 	.ds	1
                                     32 
                                     33 ;--------------------------------------------------------
                                     34 ; absolute external ram data
                                     35 ;--------------------------------------------------------
                                     36 	.area DABS (ABS)
                                     37 
                                     38 ; default segment ordering for linker
                                     39 	.area HOME
                                     40 	.area GSINIT
                                     41 	.area GSFINAL
                                     42 	.area CONST
                                     43 	.area INITIALIZER
                                     44 	.area CODE
                                     45 
                                     46 ;--------------------------------------------------------
                                     47 ; interrupt vector 
                                     48 ;--------------------------------------------------------
                                     49 	.area HOME
      008000                         50 __interrupt_vect:
      008000 82 00 80 67             51 	int s_GSINIT ; reset
      008004 82 00 00 00             52 	int 0x000000 ; trap
      008008 82 00 00 00             53 	int 0x000000 ; int0
      00800C 82 00 00 00             54 	int 0x000000 ; int1
      008010 82 00 00 00             55 	int 0x000000 ; int2
      008014 82 00 00 00             56 	int 0x000000 ; int3
      008018 82 00 00 00             57 	int 0x000000 ; int4
      00801C 82 00 00 00             58 	int 0x000000 ; int5
      008020 82 00 00 00             59 	int 0x000000 ; int6
      008024 82 00 00 00             60 	int 0x000000 ; int7
      008028 82 00 00 00             61 	int 0x000000 ; int8
      00802C 82 00 00 00             62 	int 0x000000 ; int9
      008030 82 00 00 00             63 	int 0x000000 ; int10
      008034 82 00 00 00             64 	int 0x000000 ; int11
      008038 82 00 00 00             65 	int 0x000000 ; int12
      00803C 82 00 80 CC             66 	int _IRQ_TIMER2 ; int13
      008040 82 00 00 00             67 	int 0x000000 ; int14
      008044 82 00 00 00             68 	int 0x000000 ; int15
      008048 82 00 00 00             69 	int 0x000000 ; int16
      00804C 82 00 00 00             70 	int 0x000000 ; int17
      008050 82 00 80 BB             71 	int _IRQ_UART1_RX ; int18
      008054 82 00 00 00             72 	int 0x000000 ; int19
      008058 82 00 00 00             73 	int 0x000000 ; int20
      00805C 82 00 00 00             74 	int 0x000000 ; int21
      008060 82 00 80 D1             75 	int _IRQ_ADC ; int22
                                     76 ;--------------------------------------------------------
                                     77 ; global & static initialisations
                                     78 ;--------------------------------------------------------
                                     79 	.area HOME
                                     80 	.area GSINIT
                                     81 	.area GSFINAL
                                     82 	.area GSINIT
      008067                         83 __sdcc_gs_init_startup:
      008067                         84 __sdcc_init_data:
                                     85 ; stm8_genXINIT() start
      008067 AE 00 00         [ 2]   86 	ldw x, #l_DATA
      00806A 27 07            [ 1]   87 	jreq	00002$
      00806C                         88 00001$:
      00806C 72 4F 00 00      [ 1]   89 	clr (s_DATA - 1, x)
      008070 5A               [ 2]   90 	decw x
      008071 26 F9            [ 1]   91 	jrne	00001$
      008073                         92 00002$:
      008073 AE 00 08         [ 2]   93 	ldw	x, #l_INITIALIZER
      008076 27 09            [ 1]   94 	jreq	00004$
      008078                         95 00003$:
      008078 D6 80 83         [ 1]   96 	ld	a, (s_INITIALIZER - 1, x)
      00807B D7 00 00         [ 1]   97 	ld	(s_INITIALIZED - 1, x), a
      00807E 5A               [ 2]   98 	decw	x
      00807F 26 F7            [ 1]   99 	jrne	00003$
      008081                        100 00004$:
                                    101 ; stm8_genXINIT() end
                                    102 	.area GSFINAL
      008081 CC 80 64         [ 2]  103 	jp	__sdcc_program_startup
                                    104 ;--------------------------------------------------------
                                    105 ; Home
                                    106 ;--------------------------------------------------------
                                    107 	.area HOME
                                    108 	.area HOME
      008064                        109 __sdcc_program_startup:
      008064 CC 80 AC         [ 2]  110 	jp	_main
                                    111 ;	return from main will return to caller
                                    112 ;--------------------------------------------------------
                                    113 ; code
                                    114 ;--------------------------------------------------------
                                    115 	.area CODE
                                    116 ;	src/main.c: 5: int main (void){
                                    117 ;	-----------------------------------------
                                    118 ;	 function main
                                    119 ;	-----------------------------------------
      0080AC                        120 _main:
                                    121 ;	src/main.c: 6: CLK_Config();
      0080AC CD 80 8C         [ 4]  122 	call	_CLK_Config
                                    123 ;	src/main.c: 7: UART_Config();
      0080AF CD 80 D6         [ 4]  124 	call	_UART_Config
                                    125 ;	src/main.c: 13: UART_Send(0x31);
      0080B2 4B 31            [ 1]  126 	push	#0x31
      0080B4 CD 81 46         [ 4]  127 	call	_UART_Send
      0080B7 84               [ 1]  128 	pop	a
                                    129 ;	src/main.c: 15: while (1){
      0080B8                        130 00102$:
      0080B8 20 FE            [ 2]  131 	jra	00102$
                                    132 ;	src/main.c: 18: }
      0080BA 81               [ 4]  133 	ret
                                    134 ;	src/main.c: 20: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
                                    135 ;	-----------------------------------------
                                    136 ;	 function IRQ_UART1_RX
                                    137 ;	-----------------------------------------
      0080BB                        138 _IRQ_UART1_RX:
      0080BB 4F               [ 1]  139 	clr	a
      0080BC 62               [ 2]  140 	div	x, a
                                    141 ;	src/main.c: 21: UART_Send(UART1->DR);
      0080BD C6 52 31         [ 1]  142 	ld	a, 0x5231
      0080C0 88               [ 1]  143 	push	a
      0080C1 CD 81 46         [ 4]  144 	call	_UART_Send
      0080C4 84               [ 1]  145 	pop	a
                                    146 ;	src/main.c: 22: UART_Send(0x31);
      0080C5 4B 31            [ 1]  147 	push	#0x31
      0080C7 CD 81 46         [ 4]  148 	call	_UART_Send
      0080CA 84               [ 1]  149 	pop	a
                                    150 ;	src/main.c: 23: }
      0080CB 80               [11]  151 	iret
                                    152 ;	src/main.c: 26: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
                                    153 ;	-----------------------------------------
                                    154 ;	 function IRQ_TIMER2
                                    155 ;	-----------------------------------------
      0080CC                        156 _IRQ_TIMER2:
                                    157 ;	src/main.c: 27: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
      0080CC 72 11 53 04      [ 1]  158 	bres	21252, #0
                                    159 ;	src/main.c: 29: }
      0080D0 80               [11]  160 	iret
                                    161 ;	src/main.c: 31: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
                                    162 ;	-----------------------------------------
                                    163 ;	 function IRQ_ADC
                                    164 ;	-----------------------------------------
      0080D1                        165 _IRQ_ADC:
                                    166 ;	src/main.c: 32: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1
      0080D1 72 1F 54 00      [ 1]  167 	bres	21504, #7
                                    168 ;	src/main.c: 33: }
      0080D5 80               [11]  169 	iret
                                    170 	.area CODE
                                    171 	.area CONST
                                    172 	.area INITIALIZER
                                    173 	.area CABS (ABS)

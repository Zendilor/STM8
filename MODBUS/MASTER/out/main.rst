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
                                     11 	.globl _IRQ_TIMER2
                                     12 	.globl _IRQ_UART1_RX
                                     13 	.globl _main
                                     14 	.globl _MASTER_Send
                                     15 	.globl _TIMER_Config
                                     16 	.globl _UART_Config
                                     17 	.globl _CLK_Config
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
      008000 82 00 80 57             51 	int s_GSINIT ; reset
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
      00803C 82 00 80 DB             66 	int _IRQ_TIMER2 ; int13
      008040 82 00 00 00             67 	int 0x000000 ; int14
      008044 82 00 00 00             68 	int 0x000000 ; int15
      008048 82 00 00 00             69 	int 0x000000 ; int16
      00804C 82 00 00 00             70 	int 0x000000 ; int17
      008050 82 00 80 DA             71 	int _IRQ_UART1_RX ; int18
                                     72 ;--------------------------------------------------------
                                     73 ; global & static initialisations
                                     74 ;--------------------------------------------------------
                                     75 	.area HOME
                                     76 	.area GSINIT
                                     77 	.area GSFINAL
                                     78 	.area GSINIT
      008057                         79 __sdcc_gs_init_startup:
      008057                         80 __sdcc_init_data:
                                     81 ; stm8_genXINIT() start
      008057 AE 00 06         [ 2]   82 	ldw x, #l_DATA
      00805A 27 07            [ 1]   83 	jreq	00002$
      00805C                         84 00001$:
      00805C 72 4F 00 00      [ 1]   85 	clr (s_DATA - 1, x)
      008060 5A               [ 2]   86 	decw x
      008061 26 F9            [ 1]   87 	jrne	00001$
      008063                         88 00002$:
      008063 AE 00 0A         [ 2]   89 	ldw	x, #l_INITIALIZER
      008066 27 09            [ 1]   90 	jreq	00004$
      008068                         91 00003$:
      008068 D6 80 73         [ 1]   92 	ld	a, (s_INITIALIZER - 1, x)
      00806B D7 00 06         [ 1]   93 	ld	(s_INITIALIZED - 1, x), a
      00806E 5A               [ 2]   94 	decw	x
      00806F 26 F7            [ 1]   95 	jrne	00003$
      008071                         96 00004$:
                                     97 ; stm8_genXINIT() end
                                     98 	.area GSFINAL
      008071 CC 80 54         [ 2]   99 	jp	__sdcc_program_startup
                                    100 ;--------------------------------------------------------
                                    101 ; Home
                                    102 ;--------------------------------------------------------
                                    103 	.area HOME
                                    104 	.area HOME
      008054                        105 __sdcc_program_startup:
      008054 CC 80 CD         [ 2]  106 	jp	_main
                                    107 ;	return from main will return to caller
                                    108 ;--------------------------------------------------------
                                    109 ; code
                                    110 ;--------------------------------------------------------
                                    111 	.area CODE
                                    112 ;	src/main.c: 8: int main (void){
                                    113 ;	-----------------------------------------
                                    114 ;	 function main
                                    115 ;	-----------------------------------------
      0080CD                        116 _main:
                                    117 ;	src/main.c: 9: CLK_Config();
      0080CD CD 80 7E         [ 4]  118 	call	_CLK_Config
                                    119 ;	src/main.c: 10: UART_Config();
      0080D0 CD 81 CA         [ 4]  120 	call	_UART_Config
                                    121 ;	src/main.c: 11: TIMER_Config();
      0080D3 CD 81 AA         [ 4]  122 	call	_TIMER_Config
                                    123 ;	src/main.c: 12: enableInterrupts();
      0080D6 9A               [ 1]  124 	rim
                                    125 ;	src/main.c: 14: while (1){
      0080D7                        126 00102$:
      0080D7 20 FE            [ 2]  127 	jra	00102$
                                    128 ;	src/main.c: 17: }
      0080D9 81               [ 4]  129 	ret
                                    130 ;	src/main.c: 19: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
                                    131 ;	-----------------------------------------
                                    132 ;	 function IRQ_UART1_RX
                                    133 ;	-----------------------------------------
      0080DA                        134 _IRQ_UART1_RX:
                                    135 ;	src/main.c: 21: }
      0080DA 80               [11]  136 	iret
                                    137 ;	src/main.c: 23: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
                                    138 ;	-----------------------------------------
                                    139 ;	 function IRQ_TIMER2
                                    140 ;	-----------------------------------------
      0080DB                        141 _IRQ_TIMER2:
      0080DB 4F               [ 1]  142 	clr	a
      0080DC 62               [ 2]  143 	div	x, a
                                    144 ;	src/main.c: 24: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag TIMER2.
      0080DD 72 11 53 04      [ 1]  145 	bres	21252, #0
                                    146 ;	src/main.c: 25: MASTER_Send();
      0080E1 CD 80 E5         [ 4]  147 	call	_MASTER_Send
                                    148 ;	src/main.c: 26: }
      0080E4 80               [11]  149 	iret
                                    150 	.area CODE
                                    151 	.area CONST
                                    152 	.area INITIALIZER
                                    153 	.area CABS (ABS)

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
                                     15 	.globl _ADC_Config
                                     16 	.globl _Get_Result
                                     17 	.globl _TIMER_Config
                                     18 	.globl _UART_Send_16bit
                                     19 	.globl _UART_Send
                                     20 	.globl _UART_Config
                                     21 	.globl _GPIO_Config
                                     22 	.globl _CLK_Config
                                     23 	.globl _Convert_value
                                     24 ;--------------------------------------------------------
                                     25 ; ram data
                                     26 ;--------------------------------------------------------
                                     27 	.area DATA
                                     28 ;--------------------------------------------------------
                                     29 ; ram data
                                     30 ;--------------------------------------------------------
                                     31 	.area INITIALIZED
                                     32 ;--------------------------------------------------------
                                     33 ; Stack segment in internal ram 
                                     34 ;--------------------------------------------------------
                                     35 	.area	SSEG
      FFFFFF                         36 __start__stack:
      FFFFFF                         37 	.ds	1
                                     38 
                                     39 ;--------------------------------------------------------
                                     40 ; absolute external ram data
                                     41 ;--------------------------------------------------------
                                     42 	.area DABS (ABS)
                                     43 
                                     44 ; default segment ordering for linker
                                     45 	.area HOME
                                     46 	.area GSINIT
                                     47 	.area GSFINAL
                                     48 	.area CONST
                                     49 	.area INITIALIZER
                                     50 	.area CODE
                                     51 
                                     52 ;--------------------------------------------------------
                                     53 ; interrupt vector 
                                     54 ;--------------------------------------------------------
                                     55 	.area HOME
      008000                         56 __interrupt_vect:
      008000 82 00 80 67             57 	int s_GSINIT ; reset
      008004 82 00 00 00             58 	int 0x000000 ; trap
      008008 82 00 00 00             59 	int 0x000000 ; int0
      00800C 82 00 00 00             60 	int 0x000000 ; int1
      008010 82 00 00 00             61 	int 0x000000 ; int2
      008014 82 00 00 00             62 	int 0x000000 ; int3
      008018 82 00 00 00             63 	int 0x000000 ; int4
      00801C 82 00 00 00             64 	int 0x000000 ; int5
      008020 82 00 00 00             65 	int 0x000000 ; int6
      008024 82 00 00 00             66 	int 0x000000 ; int7
      008028 82 00 00 00             67 	int 0x000000 ; int8
      00802C 82 00 00 00             68 	int 0x000000 ; int9
      008030 82 00 00 00             69 	int 0x000000 ; int10
      008034 82 00 00 00             70 	int 0x000000 ; int11
      008038 82 00 00 00             71 	int 0x000000 ; int12
      00803C 82 00 81 26             72 	int _IRQ_TIMER2 ; int13
      008040 82 00 00 00             73 	int 0x000000 ; int14
      008044 82 00 00 00             74 	int 0x000000 ; int15
      008048 82 00 00 00             75 	int 0x000000 ; int16
      00804C 82 00 00 00             76 	int 0x000000 ; int17
      008050 82 00 81 1B             77 	int _IRQ_UART1_RX ; int18
      008054 82 00 00 00             78 	int 0x000000 ; int19
      008058 82 00 00 00             79 	int 0x000000 ; int20
      00805C 82 00 00 00             80 	int 0x000000 ; int21
      008060 82 00 81 33             81 	int _IRQ_ADC ; int22
                                     82 ;--------------------------------------------------------
                                     83 ; global & static initialisations
                                     84 ;--------------------------------------------------------
                                     85 	.area HOME
                                     86 	.area GSINIT
                                     87 	.area GSFINAL
                                     88 	.area GSINIT
      008067                         89 __sdcc_gs_init_startup:
      008067                         90 __sdcc_init_data:
                                     91 ; stm8_genXINIT() start
      008067 AE 00 00         [ 2]   92 	ldw x, #l_DATA
      00806A 27 07            [ 1]   93 	jreq	00002$
      00806C                         94 00001$:
      00806C 72 4F 00 00      [ 1]   95 	clr (s_DATA - 1, x)
      008070 5A               [ 2]   96 	decw x
      008071 26 F9            [ 1]   97 	jrne	00001$
      008073                         98 00002$:
      008073 AE 00 03         [ 2]   99 	ldw	x, #l_INITIALIZER
      008076 27 09            [ 1]  100 	jreq	00004$
      008078                        101 00003$:
      008078 D6 80 83         [ 1]  102 	ld	a, (s_INITIALIZER - 1, x)
      00807B D7 00 00         [ 1]  103 	ld	(s_INITIALIZED - 1, x), a
      00807E 5A               [ 2]  104 	decw	x
      00807F 26 F7            [ 1]  105 	jrne	00003$
      008081                        106 00004$:
                                    107 ; stm8_genXINIT() end
                                    108 	.area GSFINAL
      008081 CC 80 64         [ 2]  109 	jp	__sdcc_program_startup
                                    110 ;--------------------------------------------------------
                                    111 ; Home
                                    112 ;--------------------------------------------------------
                                    113 	.area HOME
                                    114 	.area HOME
      008064                        115 __sdcc_program_startup:
      008064 CC 81 09         [ 2]  116 	jp	_main
                                    117 ;	return from main will return to caller
                                    118 ;--------------------------------------------------------
                                    119 ; code
                                    120 ;--------------------------------------------------------
                                    121 	.area CODE
                                    122 ;	src/main.c: 10: int main (void){
                                    123 ;	-----------------------------------------
                                    124 ;	 function main
                                    125 ;	-----------------------------------------
      008109                        126 _main:
                                    127 ;	src/main.c: 12: CLK_Config();
      008109 CD 80 BD         [ 4]  128 	call	_CLK_Config
                                    129 ;	src/main.c: 13: GPIO_Config();
      00810C CD 80 E4         [ 4]  130 	call	_GPIO_Config
                                    131 ;	src/main.c: 14: UART_Config();
      00810F CD 81 F8         [ 4]  132 	call	_UART_Config
                                    133 ;	src/main.c: 15: ADC_Config();
      008112 CD 80 87         [ 4]  134 	call	_ADC_Config
                                    135 ;	src/main.c: 16: TIMER_Config();
      008115 CD 81 92         [ 4]  136 	call	_TIMER_Config
                                    137 ;	src/main.c: 18: while (1){
      008118                        138 00102$:
      008118 20 FE            [ 2]  139 	jra	00102$
                                    140 ;	src/main.c: 21: }
      00811A 81               [ 4]  141 	ret
                                    142 ;	src/main.c: 23: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
                                    143 ;	-----------------------------------------
                                    144 ;	 function IRQ_UART1_RX
                                    145 ;	-----------------------------------------
      00811B                        146 _IRQ_UART1_RX:
      00811B 4F               [ 1]  147 	clr	a
      00811C 62               [ 2]  148 	div	x, a
                                    149 ;	src/main.c: 24: UART_Send(UART1->DR);
      00811D C6 52 31         [ 1]  150 	ld	a, 0x5231
      008120 88               [ 1]  151 	push	a
      008121 CD 82 0D         [ 4]  152 	call	_UART_Send
      008124 84               [ 1]  153 	pop	a
                                    154 ;	src/main.c: 25: }
      008125 80               [11]  155 	iret
                                    156 ;	src/main.c: 27: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
                                    157 ;	-----------------------------------------
                                    158 ;	 function IRQ_TIMER2
                                    159 ;	-----------------------------------------
      008126                        160 _IRQ_TIMER2:
      008126 4F               [ 1]  161 	clr	a
      008127 62               [ 2]  162 	div	x, a
                                    163 ;	src/main.c: 28: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
      008128 72 11 53 04      [ 1]  164 	bres	21252, #0
                                    165 ;	src/main.c: 29: UART_Send(0x39);
      00812C 4B 39            [ 1]  166 	push	#0x39
      00812E CD 82 0D         [ 4]  167 	call	_UART_Send
      008131 84               [ 1]  168 	pop	a
                                    169 ;	src/main.c: 30: }
      008132 80               [11]  170 	iret
                                    171 ;	src/main.c: 32: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
                                    172 ;	-----------------------------------------
                                    173 ;	 function IRQ_ADC
                                    174 ;	-----------------------------------------
      008133                        175 _IRQ_ADC:
      008133 4F               [ 1]  176 	clr	a
      008134 62               [ 2]  177 	div	x, a
                                    178 ;	src/main.c: 33: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
      008135 72 1F 54 00      [ 1]  179 	bres	21504, #7
                                    180 ;	src/main.c: 34: Convert_value();
      008139 CD 81 41         [ 4]  181 	call	_Convert_value
                                    182 ;	src/main.c: 35: ADC1->CR1 |= ADC1_CR1_ADON;
      00813C 72 10 54 01      [ 1]  183 	bset	21505, #0
                                    184 ;	src/main.c: 36: }
      008140 80               [11]  185 	iret
                                    186 ;	src/main.c: 38: void Convert_value (void){
                                    187 ;	-----------------------------------------
                                    188 ;	 function Convert_value
                                    189 ;	-----------------------------------------
      008141                        190 _Convert_value:
      008141 52 02            [ 2]  191 	sub	sp, #2
                                    192 ;	src/main.c: 39: unsigned int data = Get_Result();
      008143 CD 80 A4         [ 4]  193 	call	_Get_Result
                                    194 ;	src/main.c: 40: UART_Send_16bit(data);
      008146 89               [ 2]  195 	pushw	x
      008147 89               [ 2]  196 	pushw	x
      008148 CD 82 19         [ 4]  197 	call	_UART_Send_16bit
      00814B 5B 02            [ 2]  198 	addw	sp, #2
      00814D 85               [ 2]  199 	popw	x
                                    200 ;	src/main.c: 41: data = data * 64.0615835;
      00814E 89               [ 2]  201 	pushw	x
      00814F CD 84 2A         [ 4]  202 	call	___uint2fs
      008152 5B 02            [ 2]  203 	addw	sp, #2
      008154 89               [ 2]  204 	pushw	x
      008155 90 89            [ 2]  205 	pushw	y
      008157 4B 88            [ 1]  206 	push	#0x88
      008159 4B 1F            [ 1]  207 	push	#0x1f
      00815B 4B 80            [ 1]  208 	push	#0x80
      00815D 4B 42            [ 1]  209 	push	#0x42
      00815F CD 82 2F         [ 4]  210 	call	___fsmul
      008162 5B 08            [ 2]  211 	addw	sp, #8
      008164 89               [ 2]  212 	pushw	x
      008165 90 89            [ 2]  213 	pushw	y
      008167 CD 84 36         [ 4]  214 	call	___fs2uint
      00816A 5B 04            [ 2]  215 	addw	sp, #4
                                    216 ;	src/main.c: 42: TIM2->ARRL = data;
      00816C 9F               [ 1]  217 	ld	a, xl
      00816D C7 53 10         [ 1]  218 	ld	0x5310, a
                                    219 ;	src/main.c: 43: TIM2->ARRH = data >> 8;
      008170 9E               [ 1]  220 	ld	a, xh
      008171 0F 01            [ 1]  221 	clr	(0x01, sp)
      008173 C7 53 0F         [ 1]  222 	ld	0x530f, a
                                    223 ;	src/main.c: 44: data = (data * 60) / 100;
      008176 89               [ 2]  224 	pushw	x
      008177 58               [ 2]  225 	sllw	x
      008178 58               [ 2]  226 	sllw	x
      008179 58               [ 2]  227 	sllw	x
      00817A 58               [ 2]  228 	sllw	x
      00817B 72 F0 01         [ 2]  229 	subw	x, (1, sp)
      00817E 58               [ 2]  230 	sllw	x
      00817F 58               [ 2]  231 	sllw	x
      008180 5B 02            [ 2]  232 	addw	sp, #2
      008182 90 AE 00 64      [ 2]  233 	ldw	y, #0x0064
      008186 65               [ 2]  234 	divw	x, y
                                    235 ;	src/main.c: 45: TIM2->CCR1L = data;
      008187 9F               [ 1]  236 	ld	a, xl
      008188 C7 53 12         [ 1]  237 	ld	0x5312, a
                                    238 ;	src/main.c: 46: TIM2->CCR1H = data >> 8;
      00818B 9E               [ 1]  239 	ld	a, xh
      00818C C7 53 11         [ 1]  240 	ld	0x5311, a
                                    241 ;	src/main.c: 47: }
      00818F 5B 02            [ 2]  242 	addw	sp, #2
      008191 81               [ 4]  243 	ret
                                    244 	.area CODE
                                    245 	.area CONST
                                    246 	.area INITIALIZER
                                    247 	.area CABS (ABS)

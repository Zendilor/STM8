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
                                     13 	.globl _IRQ_TIMER1
                                     14 	.globl _IRQ_UART1_RX
                                     15 	.globl _main
                                     16 	.globl _Indication
                                     17 	.globl _ADC_Config
                                     18 	.globl _Get_Result
                                     19 	.globl _TIMER_Config
                                     20 	.globl _UART_Send
                                     21 	.globl _GPIO_Config
                                     22 	.globl _CLK_Config
                                     23 	.globl _segs
                                     24 	.globl _data_ADC
                                     25 	.globl _coefiz
                                     26 ;--------------------------------------------------------
                                     27 ; ram data
                                     28 ;--------------------------------------------------------
                                     29 	.area DATA
                                     30 ;--------------------------------------------------------
                                     31 ; ram data
                                     32 ;--------------------------------------------------------
                                     33 	.area INITIALIZED
      000004                         34 _coefiz::
      000004                         35 	.ds 4
      000008                         36 _data_ADC::
      000008                         37 	.ds 2
      00000A                         38 _segs::
      00000A                         39 	.ds 1
                                     40 ;--------------------------------------------------------
                                     41 ; Stack segment in internal ram 
                                     42 ;--------------------------------------------------------
                                     43 	.area	SSEG
      FFFFFF                         44 __start__stack:
      FFFFFF                         45 	.ds	1
                                     46 
                                     47 ;--------------------------------------------------------
                                     48 ; absolute external ram data
                                     49 ;--------------------------------------------------------
                                     50 	.area DABS (ABS)
                                     51 
                                     52 ; default segment ordering for linker
                                     53 	.area HOME
                                     54 	.area GSINIT
                                     55 	.area GSFINAL
                                     56 	.area CONST
                                     57 	.area INITIALIZER
                                     58 	.area CODE
                                     59 
                                     60 ;--------------------------------------------------------
                                     61 ; interrupt vector 
                                     62 ;--------------------------------------------------------
                                     63 	.area HOME
      008000                         64 __interrupt_vect:
      008000 82 00 80 67             65 	int s_GSINIT ; reset
      008004 82 00 00 00             66 	int 0x000000 ; trap
      008008 82 00 00 00             67 	int 0x000000 ; int0
      00800C 82 00 00 00             68 	int 0x000000 ; int1
      008010 82 00 00 00             69 	int 0x000000 ; int2
      008014 82 00 00 00             70 	int 0x000000 ; int3
      008018 82 00 00 00             71 	int 0x000000 ; int4
      00801C 82 00 00 00             72 	int 0x000000 ; int5
      008020 82 00 00 00             73 	int 0x000000 ; int6
      008024 82 00 00 00             74 	int 0x000000 ; int7
      008028 82 00 00 00             75 	int 0x000000 ; int8
      00802C 82 00 00 00             76 	int 0x000000 ; int9
      008030 82 00 00 00             77 	int 0x000000 ; int10
      008034 82 00 86 05             78 	int _IRQ_TIMER1 ; int11
      008038 82 00 00 00             79 	int 0x000000 ; int12
      00803C 82 00 86 16             80 	int _IRQ_TIMER2 ; int13
      008040 82 00 00 00             81 	int 0x000000 ; int14
      008044 82 00 00 00             82 	int 0x000000 ; int15
      008048 82 00 00 00             83 	int 0x000000 ; int16
      00804C 82 00 00 00             84 	int 0x000000 ; int17
      008050 82 00 85 F4             85 	int _IRQ_UART1_RX ; int18
      008054 82 00 00 00             86 	int 0x000000 ; int19
      008058 82 00 00 00             87 	int 0x000000 ; int20
      00805C 82 00 00 00             88 	int 0x000000 ; int21
      008060 82 00 86 3A             89 	int _IRQ_ADC ; int22
                                     90 ;--------------------------------------------------------
                                     91 ; global & static initialisations
                                     92 ;--------------------------------------------------------
                                     93 	.area HOME
                                     94 	.area GSINIT
                                     95 	.area GSFINAL
                                     96 	.area GSINIT
      008067                         97 __sdcc_gs_init_startup:
      008067                         98 __sdcc_init_data:
                                     99 ; stm8_genXINIT() start
      008067 AE 00 03         [ 2]  100 	ldw x, #l_DATA
      00806A 27 07            [ 1]  101 	jreq	00002$
      00806C                        102 00001$:
      00806C 72 4F 00 00      [ 1]  103 	clr (s_DATA - 1, x)
      008070 5A               [ 2]  104 	decw x
      008071 26 F9            [ 1]  105 	jrne	00001$
      008073                        106 00002$:
      008073 AE 00 16         [ 2]  107 	ldw	x, #l_INITIALIZER
      008076 27 09            [ 1]  108 	jreq	00004$
      008078                        109 00003$:
      008078 D6 80 83         [ 1]  110 	ld	a, (s_INITIALIZER - 1, x)
      00807B D7 00 03         [ 1]  111 	ld	(s_INITIALIZED - 1, x), a
      00807E 5A               [ 2]  112 	decw	x
      00807F 26 F7            [ 1]  113 	jrne	00003$
      008081                        114 00004$:
                                    115 ; stm8_genXINIT() end
                                    116 	.area GSFINAL
      008081 CC 80 64         [ 2]  117 	jp	__sdcc_program_startup
                                    118 ;--------------------------------------------------------
                                    119 ; Home
                                    120 ;--------------------------------------------------------
                                    121 	.area HOME
                                    122 	.area HOME
      008064                        123 __sdcc_program_startup:
      008064 CC 85 E3         [ 2]  124 	jp	_main
                                    125 ;	return from main will return to caller
                                    126 ;--------------------------------------------------------
                                    127 ; code
                                    128 ;--------------------------------------------------------
                                    129 	.area CODE
                                    130 ;	src/main.c: 18: int main (void){
                                    131 ;	-----------------------------------------
                                    132 ;	 function main
                                    133 ;	-----------------------------------------
      0085E3                        134 _main:
                                    135 ;	src/main.c: 19: enableInterrupts();
      0085E3 9A               [ 1]  136 	rim
                                    137 ;	src/main.c: 20: CLK_Config();
      0085E4 CD 80 E5         [ 4]  138 	call	_CLK_Config
                                    139 ;	src/main.c: 21: GPIO_Config();
      0085E7 CD 81 18         [ 4]  140 	call	_GPIO_Config
                                    141 ;	src/main.c: 22: TIMER_Config();
      0085EA CD 86 B9         [ 4]  142 	call	_TIMER_Config
                                    143 ;	src/main.c: 23: ADC_Config();
      0085ED CD 80 9A         [ 4]  144 	call	_ADC_Config
                                    145 ;	src/main.c: 25: while (1){
      0085F0                        146 00102$:
      0085F0 CC 85 F0         [ 2]  147 	jp	00102$
      0085F3                        148 00104$:
                                    149 ;	src/main.c: 28: }
      0085F3 81               [ 4]  150 	ret
                                    151 ;	src/main.c: 30: INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
                                    152 ;	-----------------------------------------
                                    153 ;	 function IRQ_UART1_RX
                                    154 ;	-----------------------------------------
      0085F4                        155 _IRQ_UART1_RX:
      0085F4 4F               [ 1]  156 	clr	a
      0085F5 62               [ 2]  157 	div	x, a
                                    158 ;	src/main.c: 31: UART_Send(UART1->DR);
      0085F6 C6 52 31         [ 1]  159 	ld	a, 0x5231
      0085F9 88               [ 1]  160 	push	a
      0085FA CD 87 A2         [ 4]  161 	call	_UART_Send
      0085FD 84               [ 1]  162 	pop	a
                                    163 ;	src/main.c: 32: UART_Send(0x31);
      0085FE 4B 31            [ 1]  164 	push	#0x31
      008600 CD 87 A2         [ 4]  165 	call	_UART_Send
      008603 84               [ 1]  166 	pop	a
      008604                        167 00101$:
                                    168 ;	src/main.c: 33: }
      008604 80               [11]  169 	iret
                                    170 ;	src/main.c: 35: INTERRUPT_HANDLER(IRQ_TIMER1, 11){
                                    171 ;	-----------------------------------------
                                    172 ;	 function IRQ_TIMER1
                                    173 ;	-----------------------------------------
      008605                        174 _IRQ_TIMER1:
                                    175 ;	src/main.c: 36: TIM1->SR1 &= ~TIM1_SR1_UIF;   // Clear interrupt flag.
      008605 C6 52 55         [ 1]  176 	ld	a, 0x5255
      008608 A4 FE            [ 1]  177 	and	a, #0xfe
      00860A C7 52 55         [ 1]  178 	ld	0x5255, a
                                    179 ;	src/main.c: 37: ADC1->CR1 |= ADC1_CR1_ADON;
      00860D C6 54 01         [ 1]  180 	ld	a, 0x5401
      008610 AA 01            [ 1]  181 	or	a, #0x01
      008612 C7 54 01         [ 1]  182 	ld	0x5401, a
      008615                        183 00101$:
                                    184 ;	src/main.c: 38: }
      008615 80               [11]  185 	iret
                                    186 ;	src/main.c: 40: INTERRUPT_HANDLER(IRQ_TIMER2, 13){
                                    187 ;	-----------------------------------------
                                    188 ;	 function IRQ_TIMER2
                                    189 ;	-----------------------------------------
      008616                        190 _IRQ_TIMER2:
      008616 4F               [ 1]  191 	clr	a
      008617 62               [ 2]  192 	div	x, a
                                    193 ;	src/main.c: 41: TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
      008618 C6 53 04         [ 1]  194 	ld	a, 0x5304
      00861B A4 FE            [ 1]  195 	and	a, #0xfe
      00861D C7 53 04         [ 1]  196 	ld	0x5304, a
                                    197 ;	src/main.c: 42: Indication(segs);
      008620 3B 00 0A         [ 1]  198 	push	_segs+0
      008623 CD 82 9D         [ 4]  199 	call	_Indication
      008626 84               [ 1]  200 	pop	a
                                    201 ;	src/main.c: 43: segs++;
      008627 72 5C 00 0A      [ 1]  202 	inc	_segs+0
                                    203 ;	src/main.c: 44: if (segs > 2){
      00862B C6 00 0A         [ 1]  204 	ld	a, _segs+0
      00862E A1 02            [ 1]  205 	cp	a, #0x02
      008630 22 03            [ 1]  206 	jrugt	00110$
      008632 CC 86 39         [ 2]  207 	jp	00103$
      008635                        208 00110$:
                                    209 ;	src/main.c: 45: segs = 0;
      008635 72 5F 00 0A      [ 1]  210 	clr	_segs+0
      008639                        211 00103$:
                                    212 ;	src/main.c: 47: }
      008639 80               [11]  213 	iret
                                    214 ;	src/main.c: 49: INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
                                    215 ;	-----------------------------------------
                                    216 ;	 function IRQ_ADC
                                    217 ;	-----------------------------------------
      00863A                        218 _IRQ_ADC:
      00863A 4F               [ 1]  219 	clr	a
      00863B 62               [ 2]  220 	div	x, a
      00863C 52 02            [ 2]  221 	sub	sp, #2
                                    222 ;	src/main.c: 50: ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
      00863E C6 54 00         [ 1]  223 	ld	a, 0x5400
      008641 A4 7F            [ 1]  224 	and	a, #0x7f
      008643 C7 54 00         [ 1]  225 	ld	0x5400, a
                                    226 ;	src/main.c: 51: data_ADC = (Get_Result() * coefiz) * 1000;
      008646 CD 80 CB         [ 4]  227 	call	_Get_Result
      008649 89               [ 2]  228 	pushw	x
      00864A CD 8A 04         [ 4]  229 	call	___uint2fs
      00864D 5B 02            [ 2]  230 	addw	sp, #2
      00864F 3B 00 07         [ 1]  231 	push	_coefiz+3
      008652 3B 00 06         [ 1]  232 	push	_coefiz+2
      008655 3B 00 05         [ 1]  233 	push	_coefiz+1
      008658 3B 00 04         [ 1]  234 	push	_coefiz+0
      00865B 89               [ 2]  235 	pushw	x
      00865C 90 89            [ 2]  236 	pushw	y
      00865E CD 87 C8         [ 4]  237 	call	___fsmul
      008661 5B 08            [ 2]  238 	addw	sp, #8
      008663 89               [ 2]  239 	pushw	x
      008664 90 89            [ 2]  240 	pushw	y
      008666 5F               [ 1]  241 	clrw	x
      008667 89               [ 2]  242 	pushw	x
      008668 4B 7A            [ 1]  243 	push	#0x7a
      00866A 4B 44            [ 1]  244 	push	#0x44
      00866C CD 87 C8         [ 4]  245 	call	___fsmul
      00866F 5B 08            [ 2]  246 	addw	sp, #8
      008671 89               [ 2]  247 	pushw	x
      008672 90 89            [ 2]  248 	pushw	y
      008674 CD 8A 10         [ 4]  249 	call	___fs2uint
      008677 5B 04            [ 2]  250 	addw	sp, #4
      008679 CF 00 08         [ 2]  251 	ldw	_data_ADC+0, x
                                    252 ;	src/main.c: 52: seg_num [0] = data_ADC / 1000;
      00867C CE 00 08         [ 2]  253 	ldw	x, _data_ADC+0
      00867F 90 AE 03 E8      [ 2]  254 	ldw	y, #0x03e8
      008683 65               [ 2]  255 	divw	x, y
      008684 9F               [ 1]  256 	ld	a, xl
      008685 C7 00 01         [ 1]  257 	ld	_seg_num+0, a
                                    258 ;	src/main.c: 53: seg_num [1] = (data_ADC % 1000) / 100;
      008688 AE 00 02         [ 2]  259 	ldw	x, #(_seg_num + 0)+1
      00868B 1F 01            [ 2]  260 	ldw	(0x01, sp), x
      00868D CE 00 08         [ 2]  261 	ldw	x, _data_ADC+0
      008690 90 AE 03 E8      [ 2]  262 	ldw	y, #0x03e8
      008694 65               [ 2]  263 	divw	x, y
      008695 93               [ 1]  264 	ldw	x, y
      008696 90 AE 00 64      [ 2]  265 	ldw	y, #0x0064
      00869A 65               [ 2]  266 	divw	x, y
      00869B 9F               [ 1]  267 	ld	a, xl
      00869C 1E 01            [ 2]  268 	ldw	x, (0x01, sp)
      00869E F7               [ 1]  269 	ld	(x), a
                                    270 ;	src/main.c: 54: seg_num [2] = (data_ADC % 100) / 10;
      00869F AE 00 03         [ 2]  271 	ldw	x, #(_seg_num + 0)+2
      0086A2 1F 01            [ 2]  272 	ldw	(0x01, sp), x
      0086A4 CE 00 08         [ 2]  273 	ldw	x, _data_ADC+0
      0086A7 90 AE 00 64      [ 2]  274 	ldw	y, #0x0064
      0086AB 65               [ 2]  275 	divw	x, y
      0086AC 93               [ 1]  276 	ldw	x, y
      0086AD 90 AE 00 0A      [ 2]  277 	ldw	y, #0x000a
      0086B1 65               [ 2]  278 	divw	x, y
      0086B2 9F               [ 1]  279 	ld	a, xl
      0086B3 1E 01            [ 2]  280 	ldw	x, (0x01, sp)
      0086B5 F7               [ 1]  281 	ld	(x), a
      0086B6                        282 00101$:
                                    283 ;	src/main.c: 55: }
      0086B6 5B 02            [ 2]  284 	addw	sp, #2
      0086B8 80               [11]  285 	iret
                                    286 	.area CODE
                                    287 	.area CONST
                                    288 	.area INITIALIZER
      008084                        289 __xinit__coefiz:
      008084 3B 53 33 33            290 	.byte #0x3b, #0x53, #0x33, #0x33	;  3.222656e-03
      008088                        291 __xinit__data_ADC:
      008088 00 00                  292 	.dw #0x0000
      00808A                        293 __xinit__segs:
      00808A 00                     294 	.db #0x00	; 0
                                    295 	.area CABS (ABS)

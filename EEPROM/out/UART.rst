                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module UART
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _baud_rate
                                     12 	.globl _frequency
                                     13 	.globl _UART_Config
                                     14 	.globl _UART_Send
                                     15 	.globl _UART_Send_16bit
                                     16 ;--------------------------------------------------------
                                     17 ; ram data
                                     18 ;--------------------------------------------------------
                                     19 	.area DATA
                                     20 ;--------------------------------------------------------
                                     21 ; ram data
                                     22 ;--------------------------------------------------------
                                     23 	.area INITIALIZED
      000001                         24 _frequency::
      000001                         25 	.ds 4
      000005                         26 _baud_rate::
      000005                         27 	.ds 4
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
                                     57 ;	src/UART.c: 10: void UART_Config (void){
                                     58 ;	-----------------------------------------
                                     59 ;	 function UART_Config
                                     60 ;	-----------------------------------------
      0080D6                         61 _UART_Config:
      0080D6 52 04            [ 2]   62 	sub	sp, #4
                                     63 ;	src/UART.c: 11: UART1->BRR1 = ((frequency / baud_rate) & 0x0FF0) >> 4;   // Set bir low bite.
      0080D8 3B 00 08         [ 1]   64 	push	_baud_rate+3
      0080DB 3B 00 07         [ 1]   65 	push	_baud_rate+2
      0080DE 3B 00 06         [ 1]   66 	push	_baud_rate+1
      0080E1 3B 00 05         [ 1]   67 	push	_baud_rate+0
      0080E4 3B 00 04         [ 1]   68 	push	_frequency+3
      0080E7 3B 00 03         [ 1]   69 	push	_frequency+2
      0080EA 3B 00 02         [ 1]   70 	push	_frequency+1
      0080ED 3B 00 01         [ 1]   71 	push	_frequency+0
      0080F0 CD 81 68         [ 4]   72 	call	__divulong
      0080F3 5B 08            [ 2]   73 	addw	sp, #8
      0080F5 9F               [ 1]   74 	ld	a, xl
      0080F6 A4 F0            [ 1]   75 	and	a, #0xf0
      0080F8 02               [ 1]   76 	rlwa	x
      0080F9 A4 0F            [ 1]   77 	and	a, #0x0f
      0080FB 95               [ 1]   78 	ld	xh, a
      0080FC A6 10            [ 1]   79 	ld	a, #0x10
      0080FE 62               [ 2]   80 	div	x, a
      0080FF 9F               [ 1]   81 	ld	a, xl
      008100 C7 52 32         [ 1]   82 	ld	0x5232, a
                                     83 ;	src/UART.c: 12: UART1->BRR2 = (((frequency / baud_rate) & 0xF000) >> 2) | ((frequency / baud_rate) & 0x000F);
      008103 3B 00 08         [ 1]   84 	push	_baud_rate+3
      008106 3B 00 07         [ 1]   85 	push	_baud_rate+2
      008109 3B 00 06         [ 1]   86 	push	_baud_rate+1
      00810C 3B 00 05         [ 1]   87 	push	_baud_rate+0
      00810F 3B 00 04         [ 1]   88 	push	_frequency+3
      008112 3B 00 03         [ 1]   89 	push	_frequency+2
      008115 3B 00 02         [ 1]   90 	push	_frequency+1
      008118 3B 00 01         [ 1]   91 	push	_frequency+0
      00811B CD 81 68         [ 4]   92 	call	__divulong
      00811E 5B 08            [ 2]   93 	addw	sp, #8
      008120 02               [ 1]   94 	rlwa	x
      008121 6B 03            [ 1]   95 	ld	(0x03, sp), a
      008123 01               [ 1]   96 	rrwa	x
      008124 9F               [ 1]   97 	ld	a, xl
      008125 02               [ 1]   98 	rlwa	x
      008126 7B 03            [ 1]   99 	ld	a, (0x03, sp)
      008128 01               [ 1]  100 	rrwa	x
      008129 88               [ 1]  101 	push	a
      00812A 4F               [ 1]  102 	clr	a
      00812B 02               [ 1]  103 	rlwa	x
      00812C A4 F0            [ 1]  104 	and	a, #0xf0
      00812E 95               [ 1]  105 	ld	xh, a
      00812F 84               [ 1]  106 	pop	a
      008130 54               [ 2]  107 	srlw	x
      008131 54               [ 2]  108 	srlw	x
      008132 A4 0F            [ 1]  109 	and	a, #0x0f
      008134 89               [ 2]  110 	pushw	x
      008135 1A 02            [ 1]  111 	or	a, (2, sp)
      008137 85               [ 2]  112 	popw	x
      008138 C7 52 33         [ 1]  113 	ld	0x5233, a
                                    114 ;	src/UART.c: 13: UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
      00813B 72 16 52 35      [ 1]  115 	bset	21045, #3
                                    116 ;	src/UART.c: 14: UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
      00813F 72 14 52 35      [ 1]  117 	bset	21045, #2
                                    118 ;	src/UART.c: 15: }
      008143 5B 04            [ 2]  119 	addw	sp, #4
      008145 81               [ 4]  120 	ret
                                    121 ;	src/UART.c: 17: void UART_Send (uint8_t data){
                                    122 ;	-----------------------------------------
                                    123 ;	 function UART_Send
                                    124 ;	-----------------------------------------
      008146                        125 _UART_Send:
                                    126 ;	src/UART.c: 18: while(!(UART1->SR & UART1_SR_TXE));
      008146                        127 00101$:
      008146 C6 52 30         [ 1]  128 	ld	a, 0x5230
      008149 2A FB            [ 1]  129 	jrpl	00101$
                                    130 ;	src/UART.c: 19: UART1->DR = data;
      00814B AE 52 31         [ 2]  131 	ldw	x, #0x5231
      00814E 7B 03            [ 1]  132 	ld	a, (0x03, sp)
      008150 F7               [ 1]  133 	ld	(x), a
                                    134 ;	src/UART.c: 20: }
      008151 81               [ 4]  135 	ret
                                    136 ;	src/UART.c: 22: void UART_Send_16bit (int data){
                                    137 ;	-----------------------------------------
                                    138 ;	 function UART_Send_16bit
                                    139 ;	-----------------------------------------
      008152                        140 _UART_Send_16bit:
                                    141 ;	src/UART.c: 23: UART_Send(data >> 8);
      008152 1E 03            [ 2]  142 	ldw	x, (0x03, sp)
      008154 4F               [ 1]  143 	clr	a
      008155 5D               [ 2]  144 	tnzw	x
      008156 2A 01            [ 1]  145 	jrpl	00103$
      008158 4A               [ 1]  146 	dec	a
      008159                        147 00103$:
      008159 01               [ 1]  148 	rrwa	x
      00815A 9F               [ 1]  149 	ld	a, xl
      00815B 88               [ 1]  150 	push	a
      00815C CD 81 46         [ 4]  151 	call	_UART_Send
      00815F 84               [ 1]  152 	pop	a
                                    153 ;	src/UART.c: 24: UART_Send(data);
      008160 7B 04            [ 1]  154 	ld	a, (0x04, sp)
      008162 88               [ 1]  155 	push	a
      008163 CD 81 46         [ 4]  156 	call	_UART_Send
      008166 84               [ 1]  157 	pop	a
                                    158 ;	src/UART.c: 25: }
      008167 81               [ 4]  159 	ret
                                    160 	.area CODE
                                    161 	.area CONST
                                    162 	.area INITIALIZER
      008084                        163 __xinit__frequency:
      008084 00 F4 24 00            164 	.byte #0x00, #0xf4, #0x24, #0x00	; 16000000
      008088                        165 __xinit__baud_rate:
      008088 00 00 25 80            166 	.byte #0x00, #0x00, #0x25, #0x80	; 9600
                                    167 	.area CABS (ABS)

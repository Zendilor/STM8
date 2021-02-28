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
                                     11 	.globl _UART_Send_Buff
                                     12 	.globl _UART_Send_16bit
                                     13 	.globl _UART_Send
                                     14 	.globl _UART_Config
                                     15 	.globl _baud_rate
                                     16 	.globl _frequency
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
      000009                         25 _frequency::
      000009                         26 	.ds 4
      00000D                         27 _baud_rate::
      00000D                         28 	.ds 4
                                     29 ;--------------------------------------------------------
                                     30 ; absolute external ram data
                                     31 ;--------------------------------------------------------
                                     32 	.area DABS (ABS)
                                     33 
                                     34 ; default segment ordering for linker
                                     35 	.area HOME
                                     36 	.area GSINIT
                                     37 	.area GSFINAL
                                     38 	.area CONST
                                     39 	.area INITIALIZER
                                     40 	.area CODE
                                     41 
                                     42 ;--------------------------------------------------------
                                     43 ; global & static initialisations
                                     44 ;--------------------------------------------------------
                                     45 	.area HOME
                                     46 	.area GSINIT
                                     47 	.area GSFINAL
                                     48 	.area GSINIT
                                     49 ;--------------------------------------------------------
                                     50 ; Home
                                     51 ;--------------------------------------------------------
                                     52 	.area HOME
                                     53 	.area HOME
                                     54 ;--------------------------------------------------------
                                     55 ; code
                                     56 ;--------------------------------------------------------
                                     57 	.area CODE
                                     58 ;	src/UART.c: 6: void UART_Config (void){
                                     59 ;	-----------------------------------------
                                     60 ;	 function UART_Config
                                     61 ;	-----------------------------------------
      0081CA                         62 _UART_Config:
      0081CA 52 04            [ 2]   63 	sub	sp, #4
                                     64 ;	src/UART.c: 7: UART1->BRR1 = ((frequency / baud_rate) & 0x0FF0) >> 4;   // Set low bit.
      0081CC 3B 00 10         [ 1]   65 	push	_baud_rate+3
      0081CF 3B 00 0F         [ 1]   66 	push	_baud_rate+2
      0081D2 3B 00 0E         [ 1]   67 	push	_baud_rate+1
      0081D5 3B 00 0D         [ 1]   68 	push	_baud_rate+0
      0081D8 3B 00 0C         [ 1]   69 	push	_frequency+3
      0081DB 3B 00 0B         [ 1]   70 	push	_frequency+2
      0081DE 3B 00 0A         [ 1]   71 	push	_frequency+1
      0081E1 3B 00 09         [ 1]   72 	push	_frequency+0
      0081E4 CD 82 7B         [ 4]   73 	call	__divulong
      0081E7 5B 08            [ 2]   74 	addw	sp, #8
      0081E9 9F               [ 1]   75 	ld	a, xl
      0081EA A4 F0            [ 1]   76 	and	a, #0xf0
      0081EC 02               [ 1]   77 	rlwa	x
      0081ED A4 0F            [ 1]   78 	and	a, #0x0f
      0081EF 95               [ 1]   79 	ld	xh, a
      0081F0 A6 10            [ 1]   80 	ld	a, #0x10
      0081F2 62               [ 2]   81 	div	x, a
      0081F3 9F               [ 1]   82 	ld	a, xl
      0081F4 C7 52 32         [ 1]   83 	ld	0x5232, a
                                     84 ;	src/UART.c: 8: UART1->BRR2 = (((frequency / baud_rate) & 0xF000) >> 2) | ((frequency / baud_rate) & 0x000F); // Set high bit.
      0081F7 3B 00 10         [ 1]   85 	push	_baud_rate+3
      0081FA 3B 00 0F         [ 1]   86 	push	_baud_rate+2
      0081FD 3B 00 0E         [ 1]   87 	push	_baud_rate+1
      008200 3B 00 0D         [ 1]   88 	push	_baud_rate+0
      008203 3B 00 0C         [ 1]   89 	push	_frequency+3
      008206 3B 00 0B         [ 1]   90 	push	_frequency+2
      008209 3B 00 0A         [ 1]   91 	push	_frequency+1
      00820C 3B 00 09         [ 1]   92 	push	_frequency+0
      00820F CD 82 7B         [ 4]   93 	call	__divulong
      008212 5B 08            [ 2]   94 	addw	sp, #8
      008214 02               [ 1]   95 	rlwa	x
      008215 6B 03            [ 1]   96 	ld	(0x03, sp), a
      008217 01               [ 1]   97 	rrwa	x
      008218 9F               [ 1]   98 	ld	a, xl
      008219 02               [ 1]   99 	rlwa	x
      00821A 7B 03            [ 1]  100 	ld	a, (0x03, sp)
      00821C 01               [ 1]  101 	rrwa	x
      00821D 88               [ 1]  102 	push	a
      00821E 4F               [ 1]  103 	clr	a
      00821F 02               [ 1]  104 	rlwa	x
      008220 A4 F0            [ 1]  105 	and	a, #0xf0
      008222 95               [ 1]  106 	ld	xh, a
      008223 84               [ 1]  107 	pop	a
      008224 54               [ 2]  108 	srlw	x
      008225 54               [ 2]  109 	srlw	x
      008226 A4 0F            [ 1]  110 	and	a, #0x0f
      008228 89               [ 2]  111 	pushw	x
      008229 1A 02            [ 1]  112 	or	a, (2, sp)
      00822B 85               [ 2]  113 	popw	x
      00822C C7 52 33         [ 1]  114 	ld	0x5233, a
                                    115 ;	src/UART.c: 9: UART1->CR2 |= UART1_CR2_TEN;  // Enable UART transmit.
      00822F 72 16 52 35      [ 1]  116 	bset	21045, #3
                                    117 ;	src/UART.c: 10: UART1->CR2 |= UART1_CR2_REN;  // Enable UART receiver.
      008233 72 14 52 35      [ 1]  118 	bset	21045, #2
                                    119 ;	src/UART.c: 11: UART1->CR2 |= UART1_CR2_RIEN; // Enable UART interrupt receive.
      008237 72 1A 52 35      [ 1]  120 	bset	21045, #5
                                    121 ;	src/UART.c: 12: }
      00823B 5B 04            [ 2]  122 	addw	sp, #4
      00823D 81               [ 4]  123 	ret
                                    124 ;	src/UART.c: 14: void UART_Send (uint8_t data){
                                    125 ;	-----------------------------------------
                                    126 ;	 function UART_Send
                                    127 ;	-----------------------------------------
      00823E                        128 _UART_Send:
                                    129 ;	src/UART.c: 15: while(!(UART1->SR & UART1_SR_TXE));
      00823E                        130 00101$:
      00823E C6 52 30         [ 1]  131 	ld	a, 0x5230
      008241 2A FB            [ 1]  132 	jrpl	00101$
                                    133 ;	src/UART.c: 16: UART1->DR = data;
      008243 AE 52 31         [ 2]  134 	ldw	x, #0x5231
      008246 7B 03            [ 1]  135 	ld	a, (0x03, sp)
      008248 F7               [ 1]  136 	ld	(x), a
                                    137 ;	src/UART.c: 17: }
      008249 81               [ 4]  138 	ret
                                    139 ;	src/UART.c: 19: void UART_Send_16bit (int data){
                                    140 ;	-----------------------------------------
                                    141 ;	 function UART_Send_16bit
                                    142 ;	-----------------------------------------
      00824A                        143 _UART_Send_16bit:
                                    144 ;	src/UART.c: 20: UART_Send(data >> 8);
      00824A 1E 03            [ 2]  145 	ldw	x, (0x03, sp)
      00824C 4F               [ 1]  146 	clr	a
      00824D 5D               [ 2]  147 	tnzw	x
      00824E 2A 01            [ 1]  148 	jrpl	00103$
      008250 4A               [ 1]  149 	dec	a
      008251                        150 00103$:
      008251 01               [ 1]  151 	rrwa	x
      008252 9F               [ 1]  152 	ld	a, xl
      008253 88               [ 1]  153 	push	a
      008254 CD 82 3E         [ 4]  154 	call	_UART_Send
      008257 84               [ 1]  155 	pop	a
                                    156 ;	src/UART.c: 21: UART_Send(data);
      008258 7B 04            [ 1]  157 	ld	a, (0x04, sp)
      00825A 88               [ 1]  158 	push	a
      00825B CD 82 3E         [ 4]  159 	call	_UART_Send
      00825E 84               [ 1]  160 	pop	a
                                    161 ;	src/UART.c: 22: }
      00825F 81               [ 4]  162 	ret
                                    163 ;	src/UART.c: 24: void UART_Send_Buff (char *buff, char count){
                                    164 ;	-----------------------------------------
                                    165 ;	 function UART_Send_Buff
                                    166 ;	-----------------------------------------
      008260                        167 _UART_Send_Buff:
      008260 88               [ 1]  168 	push	a
                                    169 ;	src/UART.c: 25: while(count--){
      008261 1E 04            [ 2]  170 	ldw	x, (0x04, sp)
      008263 7B 06            [ 1]  171 	ld	a, (0x06, sp)
      008265 6B 01            [ 1]  172 	ld	(0x01, sp), a
      008267                        173 00101$:
      008267 7B 01            [ 1]  174 	ld	a, (0x01, sp)
      008269 0A 01            [ 1]  175 	dec	(0x01, sp)
      00826B 4D               [ 1]  176 	tnz	a
      00826C 27 0B            [ 1]  177 	jreq	00104$
                                    178 ;	src/UART.c: 26: UART_Send(*(buff++));
      00826E F6               [ 1]  179 	ld	a, (x)
      00826F 5C               [ 1]  180 	incw	x
      008270 89               [ 2]  181 	pushw	x
      008271 88               [ 1]  182 	push	a
      008272 CD 82 3E         [ 4]  183 	call	_UART_Send
      008275 84               [ 1]  184 	pop	a
      008276 85               [ 2]  185 	popw	x
      008277 20 EE            [ 2]  186 	jra	00101$
      008279                        187 00104$:
                                    188 ;	src/UART.c: 28: }
      008279 84               [ 1]  189 	pop	a
      00827A 81               [ 4]  190 	ret
                                    191 	.area CODE
                                    192 	.area CONST
                                    193 	.area INITIALIZER
      008076                        194 __xinit__frequency:
      008076 00 F4 24 00            195 	.byte #0x00, #0xf4, #0x24, #0x00	; 16000000
      00807A                        196 __xinit__baud_rate:
      00807A 00 00 25 80            197 	.byte #0x00, #0x00, #0x25, #0x80	; 9600
                                    198 	.area CABS (ABS)

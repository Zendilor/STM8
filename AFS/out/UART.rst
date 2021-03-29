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
      000012                         24 _frequency::
      000012                         25 	.ds 4
      000016                         26 _baud_rate::
      000016                         27 	.ds 4
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
      00871F                         61 _UART_Config:
      00871F 52 04            [ 2]   62 	sub	sp, #4
                                     63 ;	src/UART.c: 11: UART1->BRR1 = ((frequency / baud_rate) & 0x0FF0) >> 4;   // Set bir low bite.
      008721 3B 00 19         [ 1]   64 	push	_baud_rate+3
      008724 3B 00 18         [ 1]   65 	push	_baud_rate+2
      008727 3B 00 17         [ 1]   66 	push	_baud_rate+1
      00872A 3B 00 16         [ 1]   67 	push	_baud_rate+0
      00872D 3B 00 15         [ 1]   68 	push	_frequency+3
      008730 3B 00 14         [ 1]   69 	push	_frequency+2
      008733 3B 00 13         [ 1]   70 	push	_frequency+1
      008736 3B 00 12         [ 1]   71 	push	_frequency+0
      008739 CD 89 AA         [ 4]   72 	call	__divulong
      00873C 5B 08            [ 2]   73 	addw	sp, #8
      00873E 9F               [ 1]   74 	ld	a, xl
      00873F A4 F0            [ 1]   75 	and	a, #0xf0
      008741 97               [ 1]   76 	ld	xl, a
      008742 9E               [ 1]   77 	ld	a, xh
      008743 A4 0F            [ 1]   78 	and	a, #0x0f
      008745 95               [ 1]   79 	ld	xh, a
      008746 A6 10            [ 1]   80 	ld	a, #0x10
      008748 62               [ 2]   81 	div	x, a
      008749 9F               [ 1]   82 	ld	a, xl
      00874A C7 52 32         [ 1]   83 	ld	0x5232, a
                                     84 ;	src/UART.c: 12: UART1->BRR2 = (((frequency / baud_rate) & 0xF000) >> 2) | ((frequency / baud_rate) & 0x000F);
      00874D 3B 00 19         [ 1]   85 	push	_baud_rate+3
      008750 3B 00 18         [ 1]   86 	push	_baud_rate+2
      008753 3B 00 17         [ 1]   87 	push	_baud_rate+1
      008756 3B 00 16         [ 1]   88 	push	_baud_rate+0
      008759 3B 00 15         [ 1]   89 	push	_frequency+3
      00875C 3B 00 14         [ 1]   90 	push	_frequency+2
      00875F 3B 00 13         [ 1]   91 	push	_frequency+1
      008762 3B 00 12         [ 1]   92 	push	_frequency+0
      008765 CD 89 AA         [ 4]   93 	call	__divulong
      008768 5B 08            [ 2]   94 	addw	sp, #8
      00876A 02               [ 1]   95 	rlwa	x
      00876B 6B 03            [ 1]   96 	ld	(0x03, sp), a
      00876D 01               [ 1]   97 	rrwa	x
      00876E 9F               [ 1]   98 	ld	a, xl
      00876F 97               [ 1]   99 	ld	xl, a
      008770 02               [ 1]  100 	rlwa	x
      008771 7B 03            [ 1]  101 	ld	a, (0x03, sp)
      008773 01               [ 1]  102 	rrwa	x
      008774 88               [ 1]  103 	push	a
      008775 4F               [ 1]  104 	clr	a
      008776 97               [ 1]  105 	ld	xl, a
      008777 9E               [ 1]  106 	ld	a, xh
      008778 A4 F0            [ 1]  107 	and	a, #0xf0
      00877A 95               [ 1]  108 	ld	xh, a
      00877B 84               [ 1]  109 	pop	a
      00877C 54               [ 2]  110 	srlw	x
      00877D 54               [ 2]  111 	srlw	x
      00877E A4 0F            [ 1]  112 	and	a, #0x0f
      008780 89               [ 2]  113 	pushw	x
      008781 1A 02            [ 1]  114 	or	a, (2, sp)
      008783 85               [ 2]  115 	popw	x
      008784 C7 52 33         [ 1]  116 	ld	0x5233, a
                                    117 ;	src/UART.c: 14: UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
      008787 C6 52 35         [ 1]  118 	ld	a, 0x5235
      00878A AA 08            [ 1]  119 	or	a, #0x08
      00878C C7 52 35         [ 1]  120 	ld	0x5235, a
                                    121 ;	src/UART.c: 15: UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
      00878F C6 52 35         [ 1]  122 	ld	a, 0x5235
      008792 AA 04            [ 1]  123 	or	a, #0x04
      008794 C7 52 35         [ 1]  124 	ld	0x5235, a
                                    125 ;	src/UART.c: 16: UART1->CR2 |= UART1_CR2_RIEN; // Enable interrupt receive.
      008797 C6 52 35         [ 1]  126 	ld	a, 0x5235
      00879A AA 20            [ 1]  127 	or	a, #0x20
      00879C C7 52 35         [ 1]  128 	ld	0x5235, a
      00879F                        129 00101$:
                                    130 ;	src/UART.c: 17: }
      00879F 5B 04            [ 2]  131 	addw	sp, #4
      0087A1 81               [ 4]  132 	ret
                                    133 ;	src/UART.c: 19: void UART_Send (uint8_t data){
                                    134 ;	-----------------------------------------
                                    135 ;	 function UART_Send
                                    136 ;	-----------------------------------------
      0087A2                        137 _UART_Send:
                                    138 ;	src/UART.c: 20: while(!(UART1->SR & UART1_SR_TXE));
      0087A2                        139 00101$:
      0087A2 C6 52 30         [ 1]  140 	ld	a, 0x5230
      0087A5 4D               [ 1]  141 	tnz	a
      0087A6 2B 03            [ 1]  142 	jrmi	00116$
      0087A8 CC 87 A2         [ 2]  143 	jp	00101$
      0087AB                        144 00116$:
                                    145 ;	src/UART.c: 21: UART1->DR = data;
      0087AB AE 52 31         [ 2]  146 	ldw	x, #0x5231
      0087AE 7B 03            [ 1]  147 	ld	a, (0x03, sp)
      0087B0 F7               [ 1]  148 	ld	(x), a
      0087B1                        149 00104$:
                                    150 ;	src/UART.c: 22: }
      0087B1 81               [ 4]  151 	ret
                                    152 ;	src/UART.c: 24: void UART_Send_16bit (int data){
                                    153 ;	-----------------------------------------
                                    154 ;	 function UART_Send_16bit
                                    155 ;	-----------------------------------------
      0087B2                        156 _UART_Send_16bit:
                                    157 ;	src/UART.c: 25: UART_Send(data >> 8);
      0087B2 1E 03            [ 2]  158 	ldw	x, (0x03, sp)
      0087B4 4F               [ 1]  159 	clr	a
      0087B5 5D               [ 2]  160 	tnzw	x
      0087B6 2A 01            [ 1]  161 	jrpl	00103$
      0087B8 4A               [ 1]  162 	dec	a
      0087B9                        163 00103$:
      0087B9 01               [ 1]  164 	rrwa	x
      0087BA 9F               [ 1]  165 	ld	a, xl
      0087BB 88               [ 1]  166 	push	a
      0087BC CD 87 A2         [ 4]  167 	call	_UART_Send
      0087BF 84               [ 1]  168 	pop	a
                                    169 ;	src/UART.c: 26: UART_Send(data);
      0087C0 7B 04            [ 1]  170 	ld	a, (0x04, sp)
      0087C2 88               [ 1]  171 	push	a
      0087C3 CD 87 A2         [ 4]  172 	call	_UART_Send
      0087C6 84               [ 1]  173 	pop	a
      0087C7                        174 00101$:
                                    175 ;	src/UART.c: 27: }
      0087C7 81               [ 4]  176 	ret
                                    177 	.area CODE
                                    178 	.area CONST
                                    179 	.area INITIALIZER
      008092                        180 __xinit__frequency:
      008092 00 F4 24 00            181 	.byte #0x00, #0xf4, #0x24, #0x00	; 16000000
      008096                        182 __xinit__baud_rate:
      008096 00 00 25 80            183 	.byte #0x00, #0x00, #0x25, #0x80	; 9600
                                    184 	.area CABS (ABS)

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
                                     11 	.globl _UART_Config
                                     12 	.globl _UART_Send
                                     13 	.globl _UART_Send_16bit
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
                                     22 ;--------------------------------------------------------
                                     23 ; absolute external ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DABS (ABS)
                                     26 
                                     27 ; default segment ordering for linker
                                     28 	.area HOME
                                     29 	.area GSINIT
                                     30 	.area GSFINAL
                                     31 	.area CONST
                                     32 	.area INITIALIZER
                                     33 	.area CODE
                                     34 
                                     35 ;--------------------------------------------------------
                                     36 ; global & static initialisations
                                     37 ;--------------------------------------------------------
                                     38 	.area HOME
                                     39 	.area GSINIT
                                     40 	.area GSFINAL
                                     41 	.area GSINIT
                                     42 ;--------------------------------------------------------
                                     43 ; Home
                                     44 ;--------------------------------------------------------
                                     45 	.area HOME
                                     46 	.area HOME
                                     47 ;--------------------------------------------------------
                                     48 ; code
                                     49 ;--------------------------------------------------------
                                     50 	.area CODE
                                     51 ;	src/UART.c: 6: void UART_Config (void){
                                     52 ;	-----------------------------------------
                                     53 ;	 function UART_Config
                                     54 ;	-----------------------------------------
      0081F8                         55 _UART_Config:
                                     56 ;	src/UART.c: 7: UART1->BRR1 = 0x68;
      0081F8 35 68 52 32      [ 1]   57 	mov	0x5232+0, #0x68
                                     58 ;	src/UART.c: 8: UART1->BRR2 = 0x02;
      0081FC 35 02 52 33      [ 1]   59 	mov	0x5233+0, #0x02
                                     60 ;	src/UART.c: 10: UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
      008200 72 16 52 35      [ 1]   61 	bset	21045, #3
                                     62 ;	src/UART.c: 11: UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
      008204 72 14 52 35      [ 1]   63 	bset	21045, #2
                                     64 ;	src/UART.c: 12: UART1->CR2 |= UART1_CR2_RIEN; // Enable interrupt receive.
      008208 72 1A 52 35      [ 1]   65 	bset	21045, #5
                                     66 ;	src/UART.c: 13: }
      00820C 81               [ 4]   67 	ret
                                     68 ;	src/UART.c: 15: void UART_Send (uint8_t data){
                                     69 ;	-----------------------------------------
                                     70 ;	 function UART_Send
                                     71 ;	-----------------------------------------
      00820D                         72 _UART_Send:
                                     73 ;	src/UART.c: 16: while(!(UART1->SR & UART1_SR_TXE));
      00820D                         74 00101$:
      00820D C6 52 30         [ 1]   75 	ld	a, 0x5230
      008210 2A FB            [ 1]   76 	jrpl	00101$
                                     77 ;	src/UART.c: 17: UART1->DR = data;
      008212 AE 52 31         [ 2]   78 	ldw	x, #0x5231
      008215 7B 03            [ 1]   79 	ld	a, (0x03, sp)
      008217 F7               [ 1]   80 	ld	(x), a
                                     81 ;	src/UART.c: 18: }
      008218 81               [ 4]   82 	ret
                                     83 ;	src/UART.c: 20: void UART_Send_16bit (int data){
                                     84 ;	-----------------------------------------
                                     85 ;	 function UART_Send_16bit
                                     86 ;	-----------------------------------------
      008219                         87 _UART_Send_16bit:
                                     88 ;	src/UART.c: 21: UART_Send(data >> 8);
      008219 1E 03            [ 2]   89 	ldw	x, (0x03, sp)
      00821B 4F               [ 1]   90 	clr	a
      00821C 5D               [ 2]   91 	tnzw	x
      00821D 2A 01            [ 1]   92 	jrpl	00103$
      00821F 4A               [ 1]   93 	dec	a
      008220                         94 00103$:
      008220 01               [ 1]   95 	rrwa	x
      008221 9F               [ 1]   96 	ld	a, xl
      008222 88               [ 1]   97 	push	a
      008223 CD 82 0D         [ 4]   98 	call	_UART_Send
      008226 84               [ 1]   99 	pop	a
                                    100 ;	src/UART.c: 22: UART_Send(data);
      008227 7B 04            [ 1]  101 	ld	a, (0x04, sp)
      008229 88               [ 1]  102 	push	a
      00822A CD 82 0D         [ 4]  103 	call	_UART_Send
      00822D 84               [ 1]  104 	pop	a
                                    105 ;	src/UART.c: 23: }
      00822E 81               [ 4]  106 	ret
                                    107 	.area CODE
                                    108 	.area CONST
                                    109 	.area INITIALIZER
                                    110 	.area CABS (ABS)

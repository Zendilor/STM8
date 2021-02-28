;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module MODBUS
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _UART_Send_Buff
	.globl _UART_Send
	.globl _data
	.globl _MASTER_Send
	.globl _CRC_Calc
	.globl _Send_CRC
	.globl _Set_Address
	.globl _Set_Command
	.globl _Set_Register
	.globl _Set_Counter
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
_data::
	.ds 6
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	src/MODBUS.c: 11: void MASTER_Send (void){
;	-----------------------------------------
;	 function MASTER_Send
;	-----------------------------------------
_MASTER_Send:
;	src/MODBUS.c: 12: Set_Address(10);
	push	#0x0a
	call	_Set_Address
	pop	a
;	src/MODBUS.c: 13: Set_Command(3);
	push	#0x03
	call	_Set_Command
	pop	a
;	src/MODBUS.c: 14: Set_Register(0x01f3);
	push	#0xf3
	push	#0x01
	call	_Set_Register
	addw	sp, #2
;	src/MODBUS.c: 15: Set_Counter(1);
	push	#0x01
	push	#0x00
	call	_Set_Counter
	addw	sp, #2
;	src/MODBUS.c: 16: UART_Send_Buff(data, sizeof data);
	push	#0x06
	push	#<(_data + 0)
	push	#((_data + 0) >> 8)
	call	_UART_Send_Buff
	addw	sp, #3
;	src/MODBUS.c: 17: Send_CRC(CRC_Calc(data, sizeof data));
	push	#0x06
	push	#<(_data + 0)
	push	#((_data + 0) >> 8)
	call	_CRC_Calc
	addw	sp, #3
	pushw	x
	call	_Send_CRC
	addw	sp, #2
;	src/MODBUS.c: 18: }
	ret
;	src/MODBUS.c: 20: unsigned int CRC_Calc (unsigned char *data, unsigned char data_length){
;	-----------------------------------------
;	 function CRC_Calc
;	-----------------------------------------
_CRC_Calc:
	sub	sp, #7
;	src/MODBUS.c: 22: unsigned int crc_val = 0xFFFF;
	ldw	x, #0xffff
	ldw	(0x01, sp), x
;	src/MODBUS.c: 23: while(data_length--){
	ldw	y, (0x0a, sp)
	ldw	(0x03, sp), y
	ld	a, (0x0c, sp)
	ld	(0x05, sp), a
00105$:
	ld	a, (0x05, sp)
	ld	(0x07, sp), a
	dec	(0x05, sp)
	tnz	(0x07, sp)
	jreq	00107$
;	src/MODBUS.c: 24: crc_val^=*data++;
	ldw	x, (0x03, sp)
	ld	a, (x)
	ldw	x, (0x03, sp)
	incw	x
	ldw	(0x03, sp), x
	clrw	x
	xor	a, (0x02, sp)
	rlwa	x
	xor	a, (0x01, sp)
	ld	xh, a
	ldw	(0x01, sp), x
;	src/MODBUS.c: 25: for(i = 0; i < 8; i++){
	clrw	x
	ldw	(0x06, sp), x
00108$:
;	src/MODBUS.c: 27: crc_val = (crc_val >> 1) ^ 0xA001;
	ldw	x, (0x01, sp)
	srlw	x
;	src/MODBUS.c: 26: if(crc_val & 0x0001){
	ld	a, (0x02, sp)
	srl	a
	jrnc	00102$
;	src/MODBUS.c: 27: crc_val = (crc_val >> 1) ^ 0xA001;
	ld	a, xl
	xor	a, #0x01
	rlwa	x
	xor	a, #0xa0
	ld	xh, a
	ldw	(0x01, sp), x
	jra	00109$
00102$:
;	src/MODBUS.c: 29: crc_val = crc_val >> 1;
	ldw	(0x01, sp), x
00109$:
;	src/MODBUS.c: 25: for(i = 0; i < 8; i++){
	ldw	x, (0x06, sp)
	incw	x
	ldw	(0x06, sp), x
	cpw	x, #0x0008
	jrslt	00108$
	jra	00105$
00107$:
;	src/MODBUS.c: 33: return crc_val;
	ldw	x, (0x01, sp)
;	src/MODBUS.c: 34: }
	addw	sp, #7
	ret
;	src/MODBUS.c: 36: void Send_CRC (uint16_t data){
;	-----------------------------------------
;	 function Send_CRC
;	-----------------------------------------
_Send_CRC:
;	src/MODBUS.c: 37: UART_Send(data);
	ld	a, (0x04, sp)
	push	a
	call	_UART_Send
	pop	a
;	src/MODBUS.c: 38: UART_Send(data >> 8);
	ld	a, (0x03, sp)
	push	a
	call	_UART_Send
	pop	a
;	src/MODBUS.c: 39: }
	ret
;	src/MODBUS.c: 41: void Set_Address (uint8_t value){
;	-----------------------------------------
;	 function Set_Address
;	-----------------------------------------
_Set_Address:
;	src/MODBUS.c: 42: data [0] = value;
	ldw	x, #(_data + 0)
	ld	a, (0x03, sp)
	ld	(x), a
;	src/MODBUS.c: 43: }
	ret
;	src/MODBUS.c: 45: void Set_Command (uint8_t value){
;	-----------------------------------------
;	 function Set_Command
;	-----------------------------------------
_Set_Command:
;	src/MODBUS.c: 46: data [1] = value;
	ldw	x, #(_data + 1)
	ld	a, (0x03, sp)
	ld	(x), a
;	src/MODBUS.c: 47: }
	ret
;	src/MODBUS.c: 49: void Set_Register (uint16_t value){
;	-----------------------------------------
;	 function Set_Register
;	-----------------------------------------
_Set_Register:
;	src/MODBUS.c: 50: data [2] = value >> 8;
	ldw	x, #(_data + 0)+2
	ld	a, (0x03, sp)
	ld	(x), a
;	src/MODBUS.c: 51: data [3] = value;
	ldw	x, #(_data + 0)+3
	ld	a, (0x04, sp)
	ld	(x), a
;	src/MODBUS.c: 52: }
	ret
;	src/MODBUS.c: 54: void Set_Counter (uint16_t value){
;	-----------------------------------------
;	 function Set_Counter
;	-----------------------------------------
_Set_Counter:
;	src/MODBUS.c: 55: data [4] = value >> 8;
	ldw	x, #(_data + 0)+4
	ld	a, (0x03, sp)
	ld	(x), a
;	src/MODBUS.c: 56: data [5] = value;
	ldw	x, #(_data + 0)+5
	ld	a, (0x04, sp)
	ld	(x), a
;	src/MODBUS.c: 57: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

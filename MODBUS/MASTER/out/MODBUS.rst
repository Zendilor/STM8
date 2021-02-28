                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module MODBUS
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _UART_Send_Buff
                                     12 	.globl _UART_Send
                                     13 	.globl _data
                                     14 	.globl _MASTER_Send
                                     15 	.globl _CRC_Calc
                                     16 	.globl _Send_CRC
                                     17 	.globl _Set_Address
                                     18 	.globl _Set_Command
                                     19 	.globl _Set_Register
                                     20 	.globl _Set_Counter
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area DATA
      000001                         25 _data::
      000001                         26 	.ds 6
                                     27 ;--------------------------------------------------------
                                     28 ; ram data
                                     29 ;--------------------------------------------------------
                                     30 	.area INITIALIZED
                                     31 ;--------------------------------------------------------
                                     32 ; absolute external ram data
                                     33 ;--------------------------------------------------------
                                     34 	.area DABS (ABS)
                                     35 
                                     36 ; default segment ordering for linker
                                     37 	.area HOME
                                     38 	.area GSINIT
                                     39 	.area GSFINAL
                                     40 	.area CONST
                                     41 	.area INITIALIZER
                                     42 	.area CODE
                                     43 
                                     44 ;--------------------------------------------------------
                                     45 ; global & static initialisations
                                     46 ;--------------------------------------------------------
                                     47 	.area HOME
                                     48 	.area GSINIT
                                     49 	.area GSFINAL
                                     50 	.area GSINIT
                                     51 ;--------------------------------------------------------
                                     52 ; Home
                                     53 ;--------------------------------------------------------
                                     54 	.area HOME
                                     55 	.area HOME
                                     56 ;--------------------------------------------------------
                                     57 ; code
                                     58 ;--------------------------------------------------------
                                     59 	.area CODE
                                     60 ;	src/MODBUS.c: 11: void MASTER_Send (void){
                                     61 ;	-----------------------------------------
                                     62 ;	 function MASTER_Send
                                     63 ;	-----------------------------------------
      0080E5                         64 _MASTER_Send:
                                     65 ;	src/MODBUS.c: 12: Set_Address(10);
      0080E5 4B 0A            [ 1]   66 	push	#0x0a
      0080E7 CD 81 82         [ 4]   67 	call	_Set_Address
      0080EA 84               [ 1]   68 	pop	a
                                     69 ;	src/MODBUS.c: 13: Set_Command(3);
      0080EB 4B 03            [ 1]   70 	push	#0x03
      0080ED CD 81 89         [ 4]   71 	call	_Set_Command
      0080F0 84               [ 1]   72 	pop	a
                                     73 ;	src/MODBUS.c: 14: Set_Register(0x01f3);
      0080F1 4B F3            [ 1]   74 	push	#0xf3
      0080F3 4B 01            [ 1]   75 	push	#0x01
      0080F5 CD 81 90         [ 4]   76 	call	_Set_Register
      0080F8 5B 02            [ 2]   77 	addw	sp, #2
                                     78 ;	src/MODBUS.c: 15: Set_Counter(1);
      0080FA 4B 01            [ 1]   79 	push	#0x01
      0080FC 4B 00            [ 1]   80 	push	#0x00
      0080FE CD 81 9D         [ 4]   81 	call	_Set_Counter
      008101 5B 02            [ 2]   82 	addw	sp, #2
                                     83 ;	src/MODBUS.c: 16: UART_Send_Buff(data, sizeof data);
      008103 4B 06            [ 1]   84 	push	#0x06
      008105 4B 01            [ 1]   85 	push	#<(_data + 0)
      008107 4B 00            [ 1]   86 	push	#((_data + 0) >> 8)
      008109 CD 82 60         [ 4]   87 	call	_UART_Send_Buff
      00810C 5B 03            [ 2]   88 	addw	sp, #3
                                     89 ;	src/MODBUS.c: 17: Send_CRC(CRC_Calc(data, sizeof data));
      00810E 4B 06            [ 1]   90 	push	#0x06
      008110 4B 01            [ 1]   91 	push	#<(_data + 0)
      008112 4B 00            [ 1]   92 	push	#((_data + 0) >> 8)
      008114 CD 81 20         [ 4]   93 	call	_CRC_Calc
      008117 5B 03            [ 2]   94 	addw	sp, #3
      008119 89               [ 2]   95 	pushw	x
      00811A CD 81 73         [ 4]   96 	call	_Send_CRC
      00811D 5B 02            [ 2]   97 	addw	sp, #2
                                     98 ;	src/MODBUS.c: 18: }
      00811F 81               [ 4]   99 	ret
                                    100 ;	src/MODBUS.c: 20: unsigned int CRC_Calc (unsigned char *data, unsigned char data_length){
                                    101 ;	-----------------------------------------
                                    102 ;	 function CRC_Calc
                                    103 ;	-----------------------------------------
      008120                        104 _CRC_Calc:
      008120 52 07            [ 2]  105 	sub	sp, #7
                                    106 ;	src/MODBUS.c: 22: unsigned int crc_val = 0xFFFF;
      008122 AE FF FF         [ 2]  107 	ldw	x, #0xffff
      008125 1F 01            [ 2]  108 	ldw	(0x01, sp), x
                                    109 ;	src/MODBUS.c: 23: while(data_length--){
      008127 16 0A            [ 2]  110 	ldw	y, (0x0a, sp)
      008129 17 03            [ 2]  111 	ldw	(0x03, sp), y
      00812B 7B 0C            [ 1]  112 	ld	a, (0x0c, sp)
      00812D 6B 05            [ 1]  113 	ld	(0x05, sp), a
      00812F                        114 00105$:
      00812F 7B 05            [ 1]  115 	ld	a, (0x05, sp)
      008131 6B 07            [ 1]  116 	ld	(0x07, sp), a
      008133 0A 05            [ 1]  117 	dec	(0x05, sp)
      008135 0D 07            [ 1]  118 	tnz	(0x07, sp)
      008137 27 35            [ 1]  119 	jreq	00107$
                                    120 ;	src/MODBUS.c: 24: crc_val^=*data++;
      008139 1E 03            [ 2]  121 	ldw	x, (0x03, sp)
      00813B F6               [ 1]  122 	ld	a, (x)
      00813C 1E 03            [ 2]  123 	ldw	x, (0x03, sp)
      00813E 5C               [ 1]  124 	incw	x
      00813F 1F 03            [ 2]  125 	ldw	(0x03, sp), x
      008141 5F               [ 1]  126 	clrw	x
      008142 18 02            [ 1]  127 	xor	a, (0x02, sp)
      008144 02               [ 1]  128 	rlwa	x
      008145 18 01            [ 1]  129 	xor	a, (0x01, sp)
      008147 95               [ 1]  130 	ld	xh, a
      008148 1F 01            [ 2]  131 	ldw	(0x01, sp), x
                                    132 ;	src/MODBUS.c: 25: for(i = 0; i < 8; i++){
      00814A 5F               [ 1]  133 	clrw	x
      00814B 1F 06            [ 2]  134 	ldw	(0x06, sp), x
      00814D                        135 00108$:
                                    136 ;	src/MODBUS.c: 27: crc_val = (crc_val >> 1) ^ 0xA001;
      00814D 1E 01            [ 2]  137 	ldw	x, (0x01, sp)
      00814F 54               [ 2]  138 	srlw	x
                                    139 ;	src/MODBUS.c: 26: if(crc_val & 0x0001){
      008150 7B 02            [ 1]  140 	ld	a, (0x02, sp)
      008152 44               [ 1]  141 	srl	a
      008153 24 0B            [ 1]  142 	jrnc	00102$
                                    143 ;	src/MODBUS.c: 27: crc_val = (crc_val >> 1) ^ 0xA001;
      008155 9F               [ 1]  144 	ld	a, xl
      008156 A8 01            [ 1]  145 	xor	a, #0x01
      008158 02               [ 1]  146 	rlwa	x
      008159 A8 A0            [ 1]  147 	xor	a, #0xa0
      00815B 95               [ 1]  148 	ld	xh, a
      00815C 1F 01            [ 2]  149 	ldw	(0x01, sp), x
      00815E 20 02            [ 2]  150 	jra	00109$
      008160                        151 00102$:
                                    152 ;	src/MODBUS.c: 29: crc_val = crc_val >> 1;
      008160 1F 01            [ 2]  153 	ldw	(0x01, sp), x
      008162                        154 00109$:
                                    155 ;	src/MODBUS.c: 25: for(i = 0; i < 8; i++){
      008162 1E 06            [ 2]  156 	ldw	x, (0x06, sp)
      008164 5C               [ 1]  157 	incw	x
      008165 1F 06            [ 2]  158 	ldw	(0x06, sp), x
      008167 A3 00 08         [ 2]  159 	cpw	x, #0x0008
      00816A 2F E1            [ 1]  160 	jrslt	00108$
      00816C 20 C1            [ 2]  161 	jra	00105$
      00816E                        162 00107$:
                                    163 ;	src/MODBUS.c: 33: return crc_val;
      00816E 1E 01            [ 2]  164 	ldw	x, (0x01, sp)
                                    165 ;	src/MODBUS.c: 34: }
      008170 5B 07            [ 2]  166 	addw	sp, #7
      008172 81               [ 4]  167 	ret
                                    168 ;	src/MODBUS.c: 36: void Send_CRC (uint16_t data){
                                    169 ;	-----------------------------------------
                                    170 ;	 function Send_CRC
                                    171 ;	-----------------------------------------
      008173                        172 _Send_CRC:
                                    173 ;	src/MODBUS.c: 37: UART_Send(data);
      008173 7B 04            [ 1]  174 	ld	a, (0x04, sp)
      008175 88               [ 1]  175 	push	a
      008176 CD 82 3E         [ 4]  176 	call	_UART_Send
      008179 84               [ 1]  177 	pop	a
                                    178 ;	src/MODBUS.c: 38: UART_Send(data >> 8);
      00817A 7B 03            [ 1]  179 	ld	a, (0x03, sp)
      00817C 88               [ 1]  180 	push	a
      00817D CD 82 3E         [ 4]  181 	call	_UART_Send
      008180 84               [ 1]  182 	pop	a
                                    183 ;	src/MODBUS.c: 39: }
      008181 81               [ 4]  184 	ret
                                    185 ;	src/MODBUS.c: 41: void Set_Address (uint8_t value){
                                    186 ;	-----------------------------------------
                                    187 ;	 function Set_Address
                                    188 ;	-----------------------------------------
      008182                        189 _Set_Address:
                                    190 ;	src/MODBUS.c: 42: data [0] = value;
      008182 AE 00 01         [ 2]  191 	ldw	x, #(_data + 0)
      008185 7B 03            [ 1]  192 	ld	a, (0x03, sp)
      008187 F7               [ 1]  193 	ld	(x), a
                                    194 ;	src/MODBUS.c: 43: }
      008188 81               [ 4]  195 	ret
                                    196 ;	src/MODBUS.c: 45: void Set_Command (uint8_t value){
                                    197 ;	-----------------------------------------
                                    198 ;	 function Set_Command
                                    199 ;	-----------------------------------------
      008189                        200 _Set_Command:
                                    201 ;	src/MODBUS.c: 46: data [1] = value;
      008189 AE 00 02         [ 2]  202 	ldw	x, #(_data + 1)
      00818C 7B 03            [ 1]  203 	ld	a, (0x03, sp)
      00818E F7               [ 1]  204 	ld	(x), a
                                    205 ;	src/MODBUS.c: 47: }
      00818F 81               [ 4]  206 	ret
                                    207 ;	src/MODBUS.c: 49: void Set_Register (uint16_t value){
                                    208 ;	-----------------------------------------
                                    209 ;	 function Set_Register
                                    210 ;	-----------------------------------------
      008190                        211 _Set_Register:
                                    212 ;	src/MODBUS.c: 50: data [2] = value >> 8;
      008190 AE 00 03         [ 2]  213 	ldw	x, #(_data + 0)+2
      008193 7B 03            [ 1]  214 	ld	a, (0x03, sp)
      008195 F7               [ 1]  215 	ld	(x), a
                                    216 ;	src/MODBUS.c: 51: data [3] = value;
      008196 AE 00 04         [ 2]  217 	ldw	x, #(_data + 0)+3
      008199 7B 04            [ 1]  218 	ld	a, (0x04, sp)
      00819B F7               [ 1]  219 	ld	(x), a
                                    220 ;	src/MODBUS.c: 52: }
      00819C 81               [ 4]  221 	ret
                                    222 ;	src/MODBUS.c: 54: void Set_Counter (uint16_t value){
                                    223 ;	-----------------------------------------
                                    224 ;	 function Set_Counter
                                    225 ;	-----------------------------------------
      00819D                        226 _Set_Counter:
                                    227 ;	src/MODBUS.c: 55: data [4] = value >> 8;
      00819D AE 00 05         [ 2]  228 	ldw	x, #(_data + 0)+4
      0081A0 7B 03            [ 1]  229 	ld	a, (0x03, sp)
      0081A2 F7               [ 1]  230 	ld	(x), a
                                    231 ;	src/MODBUS.c: 56: data [5] = value;
      0081A3 AE 00 06         [ 2]  232 	ldw	x, #(_data + 0)+5
      0081A6 7B 04            [ 1]  233 	ld	a, (0x04, sp)
      0081A8 F7               [ 1]  234 	ld	(x), a
                                    235 ;	src/MODBUS.c: 57: }
      0081A9 81               [ 4]  236 	ret
                                    237 	.area CODE
                                    238 	.area CONST
                                    239 	.area INITIALIZER
                                    240 	.area CABS (ABS)

;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module INDICATION
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Indication
	.globl _seg_num
	.globl _Numbers
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
_seg_num::
	.ds 3
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
;	src/INDICATION.c: 8: void Indication (uint8_t seg){
;	-----------------------------------------
;	 function Indication
;	-----------------------------------------
_Indication:
;	src/INDICATION.c: 9: switch (seg) {
	ld	a, (0x03, sp)
	cp	a, #0x00
	jrne	00123$
	jp	00101$
00123$:
	ld	a, (0x03, sp)
	dec	a
	jrne	00126$
	jp	00102$
00126$:
	ld	a, (0x03, sp)
	cp	a, #0x02
	jrne	00129$
	jp	00103$
00129$:
	jp	00105$
;	src/INDICATION.c: 10: case 0:
00101$:
;	src/INDICATION.c: 11: DIG_1_ON;
	ld	a, 0x5005
	and	a, #0xdf
	ld	0x5005, a
;	src/INDICATION.c: 12: DIG_2_OFF;
	ld	a, 0x500a
	or	a, #0x08
	ld	0x500a, a
;	src/INDICATION.c: 13: DIG_3_OFF;
	ld	a, 0x5005
	or	a, #0x10
	ld	0x5005, a
;	src/INDICATION.c: 14: Numbers(seg_num[0]);
	ld	a, _seg_num+0
	push	a
	call	_Numbers
	pop	a
;	src/INDICATION.c: 15: break;
	jp	00105$
;	src/INDICATION.c: 16: case 1:
00102$:
;	src/INDICATION.c: 17: DIG_1_OFF;
	ld	a, 0x5005
	or	a, #0x20
	ld	0x5005, a
;	src/INDICATION.c: 18: DIG_2_ON;
	ld	a, 0x500a
	and	a, #0xf7
	ld	0x500a, a
;	src/INDICATION.c: 19: DIG_3_OFF;
	ld	a, 0x5005
	or	a, #0x10
	ld	0x5005, a
;	src/INDICATION.c: 20: Numbers(seg_num[1]);
	ld	a, _seg_num+1
	push	a
	call	_Numbers
	pop	a
;	src/INDICATION.c: 21: break;
	jp	00105$
;	src/INDICATION.c: 22: case 2:
00103$:
;	src/INDICATION.c: 23: DIG_1_OFF;
	ld	a, 0x5005
	or	a, #0x20
	ld	0x5005, a
;	src/INDICATION.c: 24: DIG_2_OFF;
	ld	a, 0x500a
	or	a, #0x08
	ld	0x500a, a
;	src/INDICATION.c: 25: DIG_3_ON;
	ld	a, 0x5005
	and	a, #0xef
	ld	0x5005, a
;	src/INDICATION.c: 26: Numbers(seg_num[2]);
	ld	a, _seg_num+2
	push	a
	call	_Numbers
	pop	a
;	src/INDICATION.c: 28: }
00105$:
;	src/INDICATION.c: 29: }
	ret
;	src/INDICATION.c: 31: void Numbers (uint8_t number){
;	-----------------------------------------
;	 function Numbers
;	-----------------------------------------
_Numbers:
;	src/INDICATION.c: 32: switch (number) {
	ld	a, (0x03, sp)
	cp	a, #0x09
	jrule	00119$
	jp	00112$
00119$:
	clrw	x
	ld	a, (0x03, sp)
	ld	xl, a
	sllw	x
	ldw	x, (#00120$, x)
	jp	(x)
00120$:
	.dw	#00101$
	.dw	#00102$
	.dw	#00103$
	.dw	#00104$
	.dw	#00105$
	.dw	#00106$
	.dw	#00107$
	.dw	#00108$
	.dw	#00109$
	.dw	#00110$
;	src/INDICATION.c: 33: case 0:
00101$:
;	src/INDICATION.c: 34: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 35: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 36: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 37: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 38: SEG_E_ON;
	ld	a, 0x500f
	or	a, #0x20
	ld	0x500f, a
;	src/INDICATION.c: 39: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 40: SEG_G_OFF;
	ld	a, 0x500f
	and	a, #0xf7
	ld	0x500f, a
;	src/INDICATION.c: 41: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 42: break;
	jp	00112$
;	src/INDICATION.c: 43: case 1:
00102$:
;	src/INDICATION.c: 44: SEG_A_OFF;
	ld	a, 0x500a
	and	a, #0xdf
	ld	0x500a, a
;	src/INDICATION.c: 45: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 46: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 47: SEG_D_OFF;
	ld	a, 0x500f
	and	a, #0xef
	ld	0x500f, a
;	src/INDICATION.c: 48: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 49: SEG_F_OFF;
	ld	a, 0x500a
	and	a, #0xef
	ld	0x500a, a
;	src/INDICATION.c: 50: SEG_G_OFF;
	ld	a, 0x500f
	and	a, #0xf7
	ld	0x500f, a
;	src/INDICATION.c: 51: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 52: break;
	jp	00112$
;	src/INDICATION.c: 53: case 2:
00103$:
;	src/INDICATION.c: 54: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 55: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 56: SEG_C_OFF;
	ld	a, 0x500f
	and	a, #0xfb
	ld	0x500f, a
;	src/INDICATION.c: 57: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 58: SEG_E_ON;
	ld	a, 0x500f
	or	a, #0x20
	ld	0x500f, a
;	src/INDICATION.c: 59: SEG_F_OFF;
	ld	a, 0x500a
	and	a, #0xef
	ld	0x500a, a
;	src/INDICATION.c: 60: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 61: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 62: break;
	jp	00112$
;	src/INDICATION.c: 63: case 3:
00104$:
;	src/INDICATION.c: 64: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 65: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 66: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 67: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 68: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 69: SEG_F_OFF;
	ld	a, 0x500a
	and	a, #0xef
	ld	0x500a, a
;	src/INDICATION.c: 70: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 71: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 72: break;
	jp	00112$
;	src/INDICATION.c: 73: case 4:
00105$:
;	src/INDICATION.c: 74: SEG_A_OFF;
	ld	a, 0x500a
	and	a, #0xdf
	ld	0x500a, a
;	src/INDICATION.c: 75: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 76: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 77: SEG_D_OFF;
	ld	a, 0x500f
	and	a, #0xef
	ld	0x500f, a
;	src/INDICATION.c: 78: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 79: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 80: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 81: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 82: break;
	jp	00112$
;	src/INDICATION.c: 83: case 5:
00106$:
;	src/INDICATION.c: 84: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 85: SEG_B_OFF;
	ld	a, 0x500a
	and	a, #0xbf
	ld	0x500a, a
;	src/INDICATION.c: 86: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 87: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 88: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 89: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 90: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 91: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 92: break;
	jp	00112$
;	src/INDICATION.c: 93: case 6:
00107$:
;	src/INDICATION.c: 94: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 95: SEG_B_OFF;
	ld	a, 0x500a
	and	a, #0xbf
	ld	0x500a, a
;	src/INDICATION.c: 96: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 97: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 98: SEG_E_ON;
	ld	a, 0x500f
	or	a, #0x20
	ld	0x500f, a
;	src/INDICATION.c: 99: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 100: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 101: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 102: break;
	jp	00112$
;	src/INDICATION.c: 103: case 7:
00108$:
;	src/INDICATION.c: 104: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 105: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 106: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 107: SEG_D_OFF;
	ld	a, 0x500f
	and	a, #0xef
	ld	0x500f, a
;	src/INDICATION.c: 108: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 109: SEG_F_OFF;
	ld	a, 0x500a
	and	a, #0xef
	ld	0x500a, a
;	src/INDICATION.c: 110: SEG_G_OFF;
	ld	a, 0x500f
	and	a, #0xf7
	ld	0x500f, a
;	src/INDICATION.c: 111: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 112: break;
	jp	00112$
;	src/INDICATION.c: 113: case 8:
00109$:
;	src/INDICATION.c: 114: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 115: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 116: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 117: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 118: SEG_E_ON;
	ld	a, 0x500f
	or	a, #0x20
	ld	0x500f, a
;	src/INDICATION.c: 119: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 120: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 121: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 122: break;
	jp	00112$
;	src/INDICATION.c: 123: case 9:
00110$:
;	src/INDICATION.c: 124: SEG_A_ON;
	ld	a, 0x500a
	or	a, #0x20
	ld	0x500a, a
;	src/INDICATION.c: 125: SEG_B_ON;
	ld	a, 0x500a
	or	a, #0x40
	ld	0x500a, a
;	src/INDICATION.c: 126: SEG_C_ON;
	ld	a, 0x500f
	or	a, #0x04
	ld	0x500f, a
;	src/INDICATION.c: 127: SEG_D_ON;
	ld	a, 0x500f
	or	a, #0x10
	ld	0x500f, a
;	src/INDICATION.c: 128: SEG_E_OFF;
	ld	a, 0x500f
	and	a, #0xdf
	ld	0x500f, a
;	src/INDICATION.c: 129: SEG_F_ON;
	ld	a, 0x500a
	or	a, #0x10
	ld	0x500a, a
;	src/INDICATION.c: 130: SEG_G_ON;
	ld	a, 0x500f
	or	a, #0x08
	ld	0x500f, a
;	src/INDICATION.c: 131: SEG_DP_OFF;
	ld	a, 0x500a
	and	a, #0x7f
	ld	0x500a, a
;	src/INDICATION.c: 133: }
00112$:
;	src/INDICATION.c: 134: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)

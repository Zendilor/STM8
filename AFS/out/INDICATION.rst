                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module INDICATION
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Indication
                                     12 	.globl _seg_num
                                     13 	.globl _Numbers
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
      000001                         18 _seg_num::
      000001                         19 	.ds 3
                                     20 ;--------------------------------------------------------
                                     21 ; ram data
                                     22 ;--------------------------------------------------------
                                     23 	.area INITIALIZED
                                     24 ;--------------------------------------------------------
                                     25 ; absolute external ram data
                                     26 ;--------------------------------------------------------
                                     27 	.area DABS (ABS)
                                     28 
                                     29 ; default segment ordering for linker
                                     30 	.area HOME
                                     31 	.area GSINIT
                                     32 	.area GSFINAL
                                     33 	.area CONST
                                     34 	.area INITIALIZER
                                     35 	.area CODE
                                     36 
                                     37 ;--------------------------------------------------------
                                     38 ; global & static initialisations
                                     39 ;--------------------------------------------------------
                                     40 	.area HOME
                                     41 	.area GSINIT
                                     42 	.area GSFINAL
                                     43 	.area GSINIT
                                     44 ;--------------------------------------------------------
                                     45 ; Home
                                     46 ;--------------------------------------------------------
                                     47 	.area HOME
                                     48 	.area HOME
                                     49 ;--------------------------------------------------------
                                     50 ; code
                                     51 ;--------------------------------------------------------
                                     52 	.area CODE
                                     53 ;	src/INDICATION.c: 8: void Indication (uint8_t seg){
                                     54 ;	-----------------------------------------
                                     55 ;	 function Indication
                                     56 ;	-----------------------------------------
      00829D                         57 _Indication:
                                     58 ;	src/INDICATION.c: 9: switch (seg) {
      00829D 7B 03            [ 1]   59 	ld	a, (0x03, sp)
      00829F A1 00            [ 1]   60 	cp	a, #0x00
      0082A1 26 03            [ 1]   61 	jrne	00123$
      0082A3 CC 82 BA         [ 2]   62 	jp	00101$
      0082A6                         63 00123$:
      0082A6 7B 03            [ 1]   64 	ld	a, (0x03, sp)
      0082A8 4A               [ 1]   65 	dec	a
      0082A9 26 03            [ 1]   66 	jrne	00126$
      0082AB CC 82 DD         [ 2]   67 	jp	00102$
      0082AE                         68 00126$:
      0082AE 7B 03            [ 1]   69 	ld	a, (0x03, sp)
      0082B0 A1 02            [ 1]   70 	cp	a, #0x02
      0082B2 26 03            [ 1]   71 	jrne	00129$
      0082B4 CC 83 00         [ 2]   72 	jp	00103$
      0082B7                         73 00129$:
      0082B7 CC 83 20         [ 2]   74 	jp	00105$
                                     75 ;	src/INDICATION.c: 10: case 0:
      0082BA                         76 00101$:
                                     77 ;	src/INDICATION.c: 11: DIG_1_ON;
      0082BA C6 50 05         [ 1]   78 	ld	a, 0x5005
      0082BD A4 DF            [ 1]   79 	and	a, #0xdf
      0082BF C7 50 05         [ 1]   80 	ld	0x5005, a
                                     81 ;	src/INDICATION.c: 12: DIG_2_OFF;
      0082C2 C6 50 0A         [ 1]   82 	ld	a, 0x500a
      0082C5 AA 08            [ 1]   83 	or	a, #0x08
      0082C7 C7 50 0A         [ 1]   84 	ld	0x500a, a
                                     85 ;	src/INDICATION.c: 13: DIG_3_OFF;
      0082CA C6 50 05         [ 1]   86 	ld	a, 0x5005
      0082CD AA 10            [ 1]   87 	or	a, #0x10
      0082CF C7 50 05         [ 1]   88 	ld	0x5005, a
                                     89 ;	src/INDICATION.c: 14: Numbers(seg_num[0]);
      0082D2 C6 00 01         [ 1]   90 	ld	a, _seg_num+0
      0082D5 88               [ 1]   91 	push	a
      0082D6 CD 83 21         [ 4]   92 	call	_Numbers
      0082D9 84               [ 1]   93 	pop	a
                                     94 ;	src/INDICATION.c: 15: break;
      0082DA CC 83 20         [ 2]   95 	jp	00105$
                                     96 ;	src/INDICATION.c: 16: case 1:
      0082DD                         97 00102$:
                                     98 ;	src/INDICATION.c: 17: DIG_1_OFF;
      0082DD C6 50 05         [ 1]   99 	ld	a, 0x5005
      0082E0 AA 20            [ 1]  100 	or	a, #0x20
      0082E2 C7 50 05         [ 1]  101 	ld	0x5005, a
                                    102 ;	src/INDICATION.c: 18: DIG_2_ON;
      0082E5 C6 50 0A         [ 1]  103 	ld	a, 0x500a
      0082E8 A4 F7            [ 1]  104 	and	a, #0xf7
      0082EA C7 50 0A         [ 1]  105 	ld	0x500a, a
                                    106 ;	src/INDICATION.c: 19: DIG_3_OFF;
      0082ED C6 50 05         [ 1]  107 	ld	a, 0x5005
      0082F0 AA 10            [ 1]  108 	or	a, #0x10
      0082F2 C7 50 05         [ 1]  109 	ld	0x5005, a
                                    110 ;	src/INDICATION.c: 20: Numbers(seg_num[1]);
      0082F5 C6 00 02         [ 1]  111 	ld	a, _seg_num+1
      0082F8 88               [ 1]  112 	push	a
      0082F9 CD 83 21         [ 4]  113 	call	_Numbers
      0082FC 84               [ 1]  114 	pop	a
                                    115 ;	src/INDICATION.c: 21: break;
      0082FD CC 83 20         [ 2]  116 	jp	00105$
                                    117 ;	src/INDICATION.c: 22: case 2:
      008300                        118 00103$:
                                    119 ;	src/INDICATION.c: 23: DIG_1_OFF;
      008300 C6 50 05         [ 1]  120 	ld	a, 0x5005
      008303 AA 20            [ 1]  121 	or	a, #0x20
      008305 C7 50 05         [ 1]  122 	ld	0x5005, a
                                    123 ;	src/INDICATION.c: 24: DIG_2_OFF;
      008308 C6 50 0A         [ 1]  124 	ld	a, 0x500a
      00830B AA 08            [ 1]  125 	or	a, #0x08
      00830D C7 50 0A         [ 1]  126 	ld	0x500a, a
                                    127 ;	src/INDICATION.c: 25: DIG_3_ON;
      008310 C6 50 05         [ 1]  128 	ld	a, 0x5005
      008313 A4 EF            [ 1]  129 	and	a, #0xef
      008315 C7 50 05         [ 1]  130 	ld	0x5005, a
                                    131 ;	src/INDICATION.c: 26: Numbers(seg_num[2]);
      008318 C6 00 03         [ 1]  132 	ld	a, _seg_num+2
      00831B 88               [ 1]  133 	push	a
      00831C CD 83 21         [ 4]  134 	call	_Numbers
      00831F 84               [ 1]  135 	pop	a
                                    136 ;	src/INDICATION.c: 28: }
      008320                        137 00105$:
                                    138 ;	src/INDICATION.c: 29: }
      008320 81               [ 4]  139 	ret
                                    140 ;	src/INDICATION.c: 31: void Numbers (uint8_t number){
                                    141 ;	-----------------------------------------
                                    142 ;	 function Numbers
                                    143 ;	-----------------------------------------
      008321                        144 _Numbers:
                                    145 ;	src/INDICATION.c: 32: switch (number) {
      008321 7B 03            [ 1]  146 	ld	a, (0x03, sp)
      008323 A1 09            [ 1]  147 	cp	a, #0x09
      008325 23 03            [ 2]  148 	jrule	00119$
      008327 CC 85 E2         [ 2]  149 	jp	00112$
      00832A                        150 00119$:
      00832A 5F               [ 1]  151 	clrw	x
      00832B 7B 03            [ 1]  152 	ld	a, (0x03, sp)
      00832D 97               [ 1]  153 	ld	xl, a
      00832E 58               [ 2]  154 	sllw	x
      00832F DE 83 33         [ 2]  155 	ldw	x, (#00120$, x)
      008332 FC               [ 2]  156 	jp	(x)
      008333                        157 00120$:
      008333 83 47                  158 	.dw	#00101$
      008335 83 8A                  159 	.dw	#00102$
      008337 83 CD                  160 	.dw	#00103$
      008339 84 10                  161 	.dw	#00104$
      00833B 84 53                  162 	.dw	#00105$
      00833D 84 96                  163 	.dw	#00106$
      00833F 84 D9                  164 	.dw	#00107$
      008341 85 1C                  165 	.dw	#00108$
      008343 85 5F                  166 	.dw	#00109$
      008345 85 A2                  167 	.dw	#00110$
                                    168 ;	src/INDICATION.c: 33: case 0:
      008347                        169 00101$:
                                    170 ;	src/INDICATION.c: 34: SEG_A_ON;
      008347 C6 50 0A         [ 1]  171 	ld	a, 0x500a
      00834A AA 20            [ 1]  172 	or	a, #0x20
      00834C C7 50 0A         [ 1]  173 	ld	0x500a, a
                                    174 ;	src/INDICATION.c: 35: SEG_B_ON;
      00834F C6 50 0A         [ 1]  175 	ld	a, 0x500a
      008352 AA 40            [ 1]  176 	or	a, #0x40
      008354 C7 50 0A         [ 1]  177 	ld	0x500a, a
                                    178 ;	src/INDICATION.c: 36: SEG_C_ON;
      008357 C6 50 0F         [ 1]  179 	ld	a, 0x500f
      00835A AA 04            [ 1]  180 	or	a, #0x04
      00835C C7 50 0F         [ 1]  181 	ld	0x500f, a
                                    182 ;	src/INDICATION.c: 37: SEG_D_ON;
      00835F C6 50 0F         [ 1]  183 	ld	a, 0x500f
      008362 AA 10            [ 1]  184 	or	a, #0x10
      008364 C7 50 0F         [ 1]  185 	ld	0x500f, a
                                    186 ;	src/INDICATION.c: 38: SEG_E_ON;
      008367 C6 50 0F         [ 1]  187 	ld	a, 0x500f
      00836A AA 20            [ 1]  188 	or	a, #0x20
      00836C C7 50 0F         [ 1]  189 	ld	0x500f, a
                                    190 ;	src/INDICATION.c: 39: SEG_F_ON;
      00836F C6 50 0A         [ 1]  191 	ld	a, 0x500a
      008372 AA 10            [ 1]  192 	or	a, #0x10
      008374 C7 50 0A         [ 1]  193 	ld	0x500a, a
                                    194 ;	src/INDICATION.c: 40: SEG_G_OFF;
      008377 C6 50 0F         [ 1]  195 	ld	a, 0x500f
      00837A A4 F7            [ 1]  196 	and	a, #0xf7
      00837C C7 50 0F         [ 1]  197 	ld	0x500f, a
                                    198 ;	src/INDICATION.c: 41: SEG_DP_OFF;
      00837F C6 50 0A         [ 1]  199 	ld	a, 0x500a
      008382 A4 7F            [ 1]  200 	and	a, #0x7f
      008384 C7 50 0A         [ 1]  201 	ld	0x500a, a
                                    202 ;	src/INDICATION.c: 42: break;
      008387 CC 85 E2         [ 2]  203 	jp	00112$
                                    204 ;	src/INDICATION.c: 43: case 1:
      00838A                        205 00102$:
                                    206 ;	src/INDICATION.c: 44: SEG_A_OFF;
      00838A C6 50 0A         [ 1]  207 	ld	a, 0x500a
      00838D A4 DF            [ 1]  208 	and	a, #0xdf
      00838F C7 50 0A         [ 1]  209 	ld	0x500a, a
                                    210 ;	src/INDICATION.c: 45: SEG_B_ON;
      008392 C6 50 0A         [ 1]  211 	ld	a, 0x500a
      008395 AA 40            [ 1]  212 	or	a, #0x40
      008397 C7 50 0A         [ 1]  213 	ld	0x500a, a
                                    214 ;	src/INDICATION.c: 46: SEG_C_ON;
      00839A C6 50 0F         [ 1]  215 	ld	a, 0x500f
      00839D AA 04            [ 1]  216 	or	a, #0x04
      00839F C7 50 0F         [ 1]  217 	ld	0x500f, a
                                    218 ;	src/INDICATION.c: 47: SEG_D_OFF;
      0083A2 C6 50 0F         [ 1]  219 	ld	a, 0x500f
      0083A5 A4 EF            [ 1]  220 	and	a, #0xef
      0083A7 C7 50 0F         [ 1]  221 	ld	0x500f, a
                                    222 ;	src/INDICATION.c: 48: SEG_E_OFF;
      0083AA C6 50 0F         [ 1]  223 	ld	a, 0x500f
      0083AD A4 DF            [ 1]  224 	and	a, #0xdf
      0083AF C7 50 0F         [ 1]  225 	ld	0x500f, a
                                    226 ;	src/INDICATION.c: 49: SEG_F_OFF;
      0083B2 C6 50 0A         [ 1]  227 	ld	a, 0x500a
      0083B5 A4 EF            [ 1]  228 	and	a, #0xef
      0083B7 C7 50 0A         [ 1]  229 	ld	0x500a, a
                                    230 ;	src/INDICATION.c: 50: SEG_G_OFF;
      0083BA C6 50 0F         [ 1]  231 	ld	a, 0x500f
      0083BD A4 F7            [ 1]  232 	and	a, #0xf7
      0083BF C7 50 0F         [ 1]  233 	ld	0x500f, a
                                    234 ;	src/INDICATION.c: 51: SEG_DP_OFF;
      0083C2 C6 50 0A         [ 1]  235 	ld	a, 0x500a
      0083C5 A4 7F            [ 1]  236 	and	a, #0x7f
      0083C7 C7 50 0A         [ 1]  237 	ld	0x500a, a
                                    238 ;	src/INDICATION.c: 52: break;
      0083CA CC 85 E2         [ 2]  239 	jp	00112$
                                    240 ;	src/INDICATION.c: 53: case 2:
      0083CD                        241 00103$:
                                    242 ;	src/INDICATION.c: 54: SEG_A_ON;
      0083CD C6 50 0A         [ 1]  243 	ld	a, 0x500a
      0083D0 AA 20            [ 1]  244 	or	a, #0x20
      0083D2 C7 50 0A         [ 1]  245 	ld	0x500a, a
                                    246 ;	src/INDICATION.c: 55: SEG_B_ON;
      0083D5 C6 50 0A         [ 1]  247 	ld	a, 0x500a
      0083D8 AA 40            [ 1]  248 	or	a, #0x40
      0083DA C7 50 0A         [ 1]  249 	ld	0x500a, a
                                    250 ;	src/INDICATION.c: 56: SEG_C_OFF;
      0083DD C6 50 0F         [ 1]  251 	ld	a, 0x500f
      0083E0 A4 FB            [ 1]  252 	and	a, #0xfb
      0083E2 C7 50 0F         [ 1]  253 	ld	0x500f, a
                                    254 ;	src/INDICATION.c: 57: SEG_D_ON;
      0083E5 C6 50 0F         [ 1]  255 	ld	a, 0x500f
      0083E8 AA 10            [ 1]  256 	or	a, #0x10
      0083EA C7 50 0F         [ 1]  257 	ld	0x500f, a
                                    258 ;	src/INDICATION.c: 58: SEG_E_ON;
      0083ED C6 50 0F         [ 1]  259 	ld	a, 0x500f
      0083F0 AA 20            [ 1]  260 	or	a, #0x20
      0083F2 C7 50 0F         [ 1]  261 	ld	0x500f, a
                                    262 ;	src/INDICATION.c: 59: SEG_F_OFF;
      0083F5 C6 50 0A         [ 1]  263 	ld	a, 0x500a
      0083F8 A4 EF            [ 1]  264 	and	a, #0xef
      0083FA C7 50 0A         [ 1]  265 	ld	0x500a, a
                                    266 ;	src/INDICATION.c: 60: SEG_G_ON;
      0083FD C6 50 0F         [ 1]  267 	ld	a, 0x500f
      008400 AA 08            [ 1]  268 	or	a, #0x08
      008402 C7 50 0F         [ 1]  269 	ld	0x500f, a
                                    270 ;	src/INDICATION.c: 61: SEG_DP_OFF;
      008405 C6 50 0A         [ 1]  271 	ld	a, 0x500a
      008408 A4 7F            [ 1]  272 	and	a, #0x7f
      00840A C7 50 0A         [ 1]  273 	ld	0x500a, a
                                    274 ;	src/INDICATION.c: 62: break;
      00840D CC 85 E2         [ 2]  275 	jp	00112$
                                    276 ;	src/INDICATION.c: 63: case 3:
      008410                        277 00104$:
                                    278 ;	src/INDICATION.c: 64: SEG_A_ON;
      008410 C6 50 0A         [ 1]  279 	ld	a, 0x500a
      008413 AA 20            [ 1]  280 	or	a, #0x20
      008415 C7 50 0A         [ 1]  281 	ld	0x500a, a
                                    282 ;	src/INDICATION.c: 65: SEG_B_ON;
      008418 C6 50 0A         [ 1]  283 	ld	a, 0x500a
      00841B AA 40            [ 1]  284 	or	a, #0x40
      00841D C7 50 0A         [ 1]  285 	ld	0x500a, a
                                    286 ;	src/INDICATION.c: 66: SEG_C_ON;
      008420 C6 50 0F         [ 1]  287 	ld	a, 0x500f
      008423 AA 04            [ 1]  288 	or	a, #0x04
      008425 C7 50 0F         [ 1]  289 	ld	0x500f, a
                                    290 ;	src/INDICATION.c: 67: SEG_D_ON;
      008428 C6 50 0F         [ 1]  291 	ld	a, 0x500f
      00842B AA 10            [ 1]  292 	or	a, #0x10
      00842D C7 50 0F         [ 1]  293 	ld	0x500f, a
                                    294 ;	src/INDICATION.c: 68: SEG_E_OFF;
      008430 C6 50 0F         [ 1]  295 	ld	a, 0x500f
      008433 A4 DF            [ 1]  296 	and	a, #0xdf
      008435 C7 50 0F         [ 1]  297 	ld	0x500f, a
                                    298 ;	src/INDICATION.c: 69: SEG_F_OFF;
      008438 C6 50 0A         [ 1]  299 	ld	a, 0x500a
      00843B A4 EF            [ 1]  300 	and	a, #0xef
      00843D C7 50 0A         [ 1]  301 	ld	0x500a, a
                                    302 ;	src/INDICATION.c: 70: SEG_G_ON;
      008440 C6 50 0F         [ 1]  303 	ld	a, 0x500f
      008443 AA 08            [ 1]  304 	or	a, #0x08
      008445 C7 50 0F         [ 1]  305 	ld	0x500f, a
                                    306 ;	src/INDICATION.c: 71: SEG_DP_OFF;
      008448 C6 50 0A         [ 1]  307 	ld	a, 0x500a
      00844B A4 7F            [ 1]  308 	and	a, #0x7f
      00844D C7 50 0A         [ 1]  309 	ld	0x500a, a
                                    310 ;	src/INDICATION.c: 72: break;
      008450 CC 85 E2         [ 2]  311 	jp	00112$
                                    312 ;	src/INDICATION.c: 73: case 4:
      008453                        313 00105$:
                                    314 ;	src/INDICATION.c: 74: SEG_A_OFF;
      008453 C6 50 0A         [ 1]  315 	ld	a, 0x500a
      008456 A4 DF            [ 1]  316 	and	a, #0xdf
      008458 C7 50 0A         [ 1]  317 	ld	0x500a, a
                                    318 ;	src/INDICATION.c: 75: SEG_B_ON;
      00845B C6 50 0A         [ 1]  319 	ld	a, 0x500a
      00845E AA 40            [ 1]  320 	or	a, #0x40
      008460 C7 50 0A         [ 1]  321 	ld	0x500a, a
                                    322 ;	src/INDICATION.c: 76: SEG_C_ON;
      008463 C6 50 0F         [ 1]  323 	ld	a, 0x500f
      008466 AA 04            [ 1]  324 	or	a, #0x04
      008468 C7 50 0F         [ 1]  325 	ld	0x500f, a
                                    326 ;	src/INDICATION.c: 77: SEG_D_OFF;
      00846B C6 50 0F         [ 1]  327 	ld	a, 0x500f
      00846E A4 EF            [ 1]  328 	and	a, #0xef
      008470 C7 50 0F         [ 1]  329 	ld	0x500f, a
                                    330 ;	src/INDICATION.c: 78: SEG_E_OFF;
      008473 C6 50 0F         [ 1]  331 	ld	a, 0x500f
      008476 A4 DF            [ 1]  332 	and	a, #0xdf
      008478 C7 50 0F         [ 1]  333 	ld	0x500f, a
                                    334 ;	src/INDICATION.c: 79: SEG_F_ON;
      00847B C6 50 0A         [ 1]  335 	ld	a, 0x500a
      00847E AA 10            [ 1]  336 	or	a, #0x10
      008480 C7 50 0A         [ 1]  337 	ld	0x500a, a
                                    338 ;	src/INDICATION.c: 80: SEG_G_ON;
      008483 C6 50 0F         [ 1]  339 	ld	a, 0x500f
      008486 AA 08            [ 1]  340 	or	a, #0x08
      008488 C7 50 0F         [ 1]  341 	ld	0x500f, a
                                    342 ;	src/INDICATION.c: 81: SEG_DP_OFF;
      00848B C6 50 0A         [ 1]  343 	ld	a, 0x500a
      00848E A4 7F            [ 1]  344 	and	a, #0x7f
      008490 C7 50 0A         [ 1]  345 	ld	0x500a, a
                                    346 ;	src/INDICATION.c: 82: break;
      008493 CC 85 E2         [ 2]  347 	jp	00112$
                                    348 ;	src/INDICATION.c: 83: case 5:
      008496                        349 00106$:
                                    350 ;	src/INDICATION.c: 84: SEG_A_ON;
      008496 C6 50 0A         [ 1]  351 	ld	a, 0x500a
      008499 AA 20            [ 1]  352 	or	a, #0x20
      00849B C7 50 0A         [ 1]  353 	ld	0x500a, a
                                    354 ;	src/INDICATION.c: 85: SEG_B_OFF;
      00849E C6 50 0A         [ 1]  355 	ld	a, 0x500a
      0084A1 A4 BF            [ 1]  356 	and	a, #0xbf
      0084A3 C7 50 0A         [ 1]  357 	ld	0x500a, a
                                    358 ;	src/INDICATION.c: 86: SEG_C_ON;
      0084A6 C6 50 0F         [ 1]  359 	ld	a, 0x500f
      0084A9 AA 04            [ 1]  360 	or	a, #0x04
      0084AB C7 50 0F         [ 1]  361 	ld	0x500f, a
                                    362 ;	src/INDICATION.c: 87: SEG_D_ON;
      0084AE C6 50 0F         [ 1]  363 	ld	a, 0x500f
      0084B1 AA 10            [ 1]  364 	or	a, #0x10
      0084B3 C7 50 0F         [ 1]  365 	ld	0x500f, a
                                    366 ;	src/INDICATION.c: 88: SEG_E_OFF;
      0084B6 C6 50 0F         [ 1]  367 	ld	a, 0x500f
      0084B9 A4 DF            [ 1]  368 	and	a, #0xdf
      0084BB C7 50 0F         [ 1]  369 	ld	0x500f, a
                                    370 ;	src/INDICATION.c: 89: SEG_F_ON;
      0084BE C6 50 0A         [ 1]  371 	ld	a, 0x500a
      0084C1 AA 10            [ 1]  372 	or	a, #0x10
      0084C3 C7 50 0A         [ 1]  373 	ld	0x500a, a
                                    374 ;	src/INDICATION.c: 90: SEG_G_ON;
      0084C6 C6 50 0F         [ 1]  375 	ld	a, 0x500f
      0084C9 AA 08            [ 1]  376 	or	a, #0x08
      0084CB C7 50 0F         [ 1]  377 	ld	0x500f, a
                                    378 ;	src/INDICATION.c: 91: SEG_DP_OFF;
      0084CE C6 50 0A         [ 1]  379 	ld	a, 0x500a
      0084D1 A4 7F            [ 1]  380 	and	a, #0x7f
      0084D3 C7 50 0A         [ 1]  381 	ld	0x500a, a
                                    382 ;	src/INDICATION.c: 92: break;
      0084D6 CC 85 E2         [ 2]  383 	jp	00112$
                                    384 ;	src/INDICATION.c: 93: case 6:
      0084D9                        385 00107$:
                                    386 ;	src/INDICATION.c: 94: SEG_A_ON;
      0084D9 C6 50 0A         [ 1]  387 	ld	a, 0x500a
      0084DC AA 20            [ 1]  388 	or	a, #0x20
      0084DE C7 50 0A         [ 1]  389 	ld	0x500a, a
                                    390 ;	src/INDICATION.c: 95: SEG_B_OFF;
      0084E1 C6 50 0A         [ 1]  391 	ld	a, 0x500a
      0084E4 A4 BF            [ 1]  392 	and	a, #0xbf
      0084E6 C7 50 0A         [ 1]  393 	ld	0x500a, a
                                    394 ;	src/INDICATION.c: 96: SEG_C_ON;
      0084E9 C6 50 0F         [ 1]  395 	ld	a, 0x500f
      0084EC AA 04            [ 1]  396 	or	a, #0x04
      0084EE C7 50 0F         [ 1]  397 	ld	0x500f, a
                                    398 ;	src/INDICATION.c: 97: SEG_D_ON;
      0084F1 C6 50 0F         [ 1]  399 	ld	a, 0x500f
      0084F4 AA 10            [ 1]  400 	or	a, #0x10
      0084F6 C7 50 0F         [ 1]  401 	ld	0x500f, a
                                    402 ;	src/INDICATION.c: 98: SEG_E_ON;
      0084F9 C6 50 0F         [ 1]  403 	ld	a, 0x500f
      0084FC AA 20            [ 1]  404 	or	a, #0x20
      0084FE C7 50 0F         [ 1]  405 	ld	0x500f, a
                                    406 ;	src/INDICATION.c: 99: SEG_F_ON;
      008501 C6 50 0A         [ 1]  407 	ld	a, 0x500a
      008504 AA 10            [ 1]  408 	or	a, #0x10
      008506 C7 50 0A         [ 1]  409 	ld	0x500a, a
                                    410 ;	src/INDICATION.c: 100: SEG_G_ON;
      008509 C6 50 0F         [ 1]  411 	ld	a, 0x500f
      00850C AA 08            [ 1]  412 	or	a, #0x08
      00850E C7 50 0F         [ 1]  413 	ld	0x500f, a
                                    414 ;	src/INDICATION.c: 101: SEG_DP_OFF;
      008511 C6 50 0A         [ 1]  415 	ld	a, 0x500a
      008514 A4 7F            [ 1]  416 	and	a, #0x7f
      008516 C7 50 0A         [ 1]  417 	ld	0x500a, a
                                    418 ;	src/INDICATION.c: 102: break;
      008519 CC 85 E2         [ 2]  419 	jp	00112$
                                    420 ;	src/INDICATION.c: 103: case 7:
      00851C                        421 00108$:
                                    422 ;	src/INDICATION.c: 104: SEG_A_ON;
      00851C C6 50 0A         [ 1]  423 	ld	a, 0x500a
      00851F AA 20            [ 1]  424 	or	a, #0x20
      008521 C7 50 0A         [ 1]  425 	ld	0x500a, a
                                    426 ;	src/INDICATION.c: 105: SEG_B_ON;
      008524 C6 50 0A         [ 1]  427 	ld	a, 0x500a
      008527 AA 40            [ 1]  428 	or	a, #0x40
      008529 C7 50 0A         [ 1]  429 	ld	0x500a, a
                                    430 ;	src/INDICATION.c: 106: SEG_C_ON;
      00852C C6 50 0F         [ 1]  431 	ld	a, 0x500f
      00852F AA 04            [ 1]  432 	or	a, #0x04
      008531 C7 50 0F         [ 1]  433 	ld	0x500f, a
                                    434 ;	src/INDICATION.c: 107: SEG_D_OFF;
      008534 C6 50 0F         [ 1]  435 	ld	a, 0x500f
      008537 A4 EF            [ 1]  436 	and	a, #0xef
      008539 C7 50 0F         [ 1]  437 	ld	0x500f, a
                                    438 ;	src/INDICATION.c: 108: SEG_E_OFF;
      00853C C6 50 0F         [ 1]  439 	ld	a, 0x500f
      00853F A4 DF            [ 1]  440 	and	a, #0xdf
      008541 C7 50 0F         [ 1]  441 	ld	0x500f, a
                                    442 ;	src/INDICATION.c: 109: SEG_F_OFF;
      008544 C6 50 0A         [ 1]  443 	ld	a, 0x500a
      008547 A4 EF            [ 1]  444 	and	a, #0xef
      008549 C7 50 0A         [ 1]  445 	ld	0x500a, a
                                    446 ;	src/INDICATION.c: 110: SEG_G_OFF;
      00854C C6 50 0F         [ 1]  447 	ld	a, 0x500f
      00854F A4 F7            [ 1]  448 	and	a, #0xf7
      008551 C7 50 0F         [ 1]  449 	ld	0x500f, a
                                    450 ;	src/INDICATION.c: 111: SEG_DP_OFF;
      008554 C6 50 0A         [ 1]  451 	ld	a, 0x500a
      008557 A4 7F            [ 1]  452 	and	a, #0x7f
      008559 C7 50 0A         [ 1]  453 	ld	0x500a, a
                                    454 ;	src/INDICATION.c: 112: break;
      00855C CC 85 E2         [ 2]  455 	jp	00112$
                                    456 ;	src/INDICATION.c: 113: case 8:
      00855F                        457 00109$:
                                    458 ;	src/INDICATION.c: 114: SEG_A_ON;
      00855F C6 50 0A         [ 1]  459 	ld	a, 0x500a
      008562 AA 20            [ 1]  460 	or	a, #0x20
      008564 C7 50 0A         [ 1]  461 	ld	0x500a, a
                                    462 ;	src/INDICATION.c: 115: SEG_B_ON;
      008567 C6 50 0A         [ 1]  463 	ld	a, 0x500a
      00856A AA 40            [ 1]  464 	or	a, #0x40
      00856C C7 50 0A         [ 1]  465 	ld	0x500a, a
                                    466 ;	src/INDICATION.c: 116: SEG_C_ON;
      00856F C6 50 0F         [ 1]  467 	ld	a, 0x500f
      008572 AA 04            [ 1]  468 	or	a, #0x04
      008574 C7 50 0F         [ 1]  469 	ld	0x500f, a
                                    470 ;	src/INDICATION.c: 117: SEG_D_ON;
      008577 C6 50 0F         [ 1]  471 	ld	a, 0x500f
      00857A AA 10            [ 1]  472 	or	a, #0x10
      00857C C7 50 0F         [ 1]  473 	ld	0x500f, a
                                    474 ;	src/INDICATION.c: 118: SEG_E_ON;
      00857F C6 50 0F         [ 1]  475 	ld	a, 0x500f
      008582 AA 20            [ 1]  476 	or	a, #0x20
      008584 C7 50 0F         [ 1]  477 	ld	0x500f, a
                                    478 ;	src/INDICATION.c: 119: SEG_F_ON;
      008587 C6 50 0A         [ 1]  479 	ld	a, 0x500a
      00858A AA 10            [ 1]  480 	or	a, #0x10
      00858C C7 50 0A         [ 1]  481 	ld	0x500a, a
                                    482 ;	src/INDICATION.c: 120: SEG_G_ON;
      00858F C6 50 0F         [ 1]  483 	ld	a, 0x500f
      008592 AA 08            [ 1]  484 	or	a, #0x08
      008594 C7 50 0F         [ 1]  485 	ld	0x500f, a
                                    486 ;	src/INDICATION.c: 121: SEG_DP_OFF;
      008597 C6 50 0A         [ 1]  487 	ld	a, 0x500a
      00859A A4 7F            [ 1]  488 	and	a, #0x7f
      00859C C7 50 0A         [ 1]  489 	ld	0x500a, a
                                    490 ;	src/INDICATION.c: 122: break;
      00859F CC 85 E2         [ 2]  491 	jp	00112$
                                    492 ;	src/INDICATION.c: 123: case 9:
      0085A2                        493 00110$:
                                    494 ;	src/INDICATION.c: 124: SEG_A_ON;
      0085A2 C6 50 0A         [ 1]  495 	ld	a, 0x500a
      0085A5 AA 20            [ 1]  496 	or	a, #0x20
      0085A7 C7 50 0A         [ 1]  497 	ld	0x500a, a
                                    498 ;	src/INDICATION.c: 125: SEG_B_ON;
      0085AA C6 50 0A         [ 1]  499 	ld	a, 0x500a
      0085AD AA 40            [ 1]  500 	or	a, #0x40
      0085AF C7 50 0A         [ 1]  501 	ld	0x500a, a
                                    502 ;	src/INDICATION.c: 126: SEG_C_ON;
      0085B2 C6 50 0F         [ 1]  503 	ld	a, 0x500f
      0085B5 AA 04            [ 1]  504 	or	a, #0x04
      0085B7 C7 50 0F         [ 1]  505 	ld	0x500f, a
                                    506 ;	src/INDICATION.c: 127: SEG_D_ON;
      0085BA C6 50 0F         [ 1]  507 	ld	a, 0x500f
      0085BD AA 10            [ 1]  508 	or	a, #0x10
      0085BF C7 50 0F         [ 1]  509 	ld	0x500f, a
                                    510 ;	src/INDICATION.c: 128: SEG_E_OFF;
      0085C2 C6 50 0F         [ 1]  511 	ld	a, 0x500f
      0085C5 A4 DF            [ 1]  512 	and	a, #0xdf
      0085C7 C7 50 0F         [ 1]  513 	ld	0x500f, a
                                    514 ;	src/INDICATION.c: 129: SEG_F_ON;
      0085CA C6 50 0A         [ 1]  515 	ld	a, 0x500a
      0085CD AA 10            [ 1]  516 	or	a, #0x10
      0085CF C7 50 0A         [ 1]  517 	ld	0x500a, a
                                    518 ;	src/INDICATION.c: 130: SEG_G_ON;
      0085D2 C6 50 0F         [ 1]  519 	ld	a, 0x500f
      0085D5 AA 08            [ 1]  520 	or	a, #0x08
      0085D7 C7 50 0F         [ 1]  521 	ld	0x500f, a
                                    522 ;	src/INDICATION.c: 131: SEG_DP_OFF;
      0085DA C6 50 0A         [ 1]  523 	ld	a, 0x500a
      0085DD A4 7F            [ 1]  524 	and	a, #0x7f
      0085DF C7 50 0A         [ 1]  525 	ld	0x500a, a
                                    526 ;	src/INDICATION.c: 133: }
      0085E2                        527 00112$:
                                    528 ;	src/INDICATION.c: 134: }
      0085E2 81               [ 4]  529 	ret
                                    530 	.area CODE
                                    531 	.area CONST
                                    532 	.area INITIALIZER
                                    533 	.area CABS (ABS)

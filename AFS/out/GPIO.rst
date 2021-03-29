                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module GPIO
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _GPIO_Config
                                     12 	.globl _GPIOB_Config
                                     13 	.globl _GPIOC_Config
                                     14 	.globl _GPIOD_Config
                                     15 ;--------------------------------------------------------
                                     16 ; ram data
                                     17 ;--------------------------------------------------------
                                     18 	.area DATA
                                     19 ;--------------------------------------------------------
                                     20 ; ram data
                                     21 ;--------------------------------------------------------
                                     22 	.area INITIALIZED
                                     23 ;--------------------------------------------------------
                                     24 ; absolute external ram data
                                     25 ;--------------------------------------------------------
                                     26 	.area DABS (ABS)
                                     27 
                                     28 ; default segment ordering for linker
                                     29 	.area HOME
                                     30 	.area GSINIT
                                     31 	.area GSFINAL
                                     32 	.area CONST
                                     33 	.area INITIALIZER
                                     34 	.area CODE
                                     35 
                                     36 ;--------------------------------------------------------
                                     37 ; global & static initialisations
                                     38 ;--------------------------------------------------------
                                     39 	.area HOME
                                     40 	.area GSINIT
                                     41 	.area GSFINAL
                                     42 	.area GSINIT
                                     43 ;--------------------------------------------------------
                                     44 ; Home
                                     45 ;--------------------------------------------------------
                                     46 	.area HOME
                                     47 	.area HOME
                                     48 ;--------------------------------------------------------
                                     49 ; code
                                     50 ;--------------------------------------------------------
                                     51 	.area CODE
                                     52 ;	src/GPIO.c: 8: void GPIO_Config (void){
                                     53 ;	-----------------------------------------
                                     54 ;	 function GPIO_Config
                                     55 ;	-----------------------------------------
      008118                         56 _GPIO_Config:
                                     57 ;	src/GPIO.c: 9: GPIOB_Config();
      008118 CD 81 22         [ 4]   58 	call	_GPIOB_Config
                                     59 ;	src/GPIO.c: 10: GPIOC_Config();
      00811B CD 81 63         [ 4]   60 	call	_GPIOC_Config
                                     61 ;	src/GPIO.c: 11: GPIOD_Config();
      00811E CC 82 04         [ 2]   62 	jp	_GPIOD_Config
      008121                         63 00101$:
                                     64 ;	src/GPIO.c: 12: }
      008121 81               [ 4]   65 	ret
                                     66 ;	src/GPIO.c: 14: void GPIOB_Config (void){
                                     67 ;	-----------------------------------------
                                     68 ;	 function GPIOB_Config
                                     69 ;	-----------------------------------------
      008122                         70 _GPIOB_Config:
                                     71 ;	src/GPIO.c: 16: GPIOB->DDR |= 0x10;   // Set PB4 as out.
      008122 C6 50 07         [ 1]   72 	ld	a, 0x5007
      008125 AA 10            [ 1]   73 	or	a, #0x10
      008127 C7 50 07         [ 1]   74 	ld	0x5007, a
                                     75 ;	src/GPIO.c: 17: GPIOB->DDR |= 0x20;   // Set PB5 as out.
      00812A C6 50 07         [ 1]   76 	ld	a, 0x5007
      00812D AA 20            [ 1]   77 	or	a, #0x20
      00812F C7 50 07         [ 1]   78 	ld	0x5007, a
                                     79 ;	src/GPIO.c: 20: GPIOB->CR1 &= ~0x10;  // Set PB4 as open drain.
      008132 C6 50 08         [ 1]   80 	ld	a, 0x5008
      008135 A4 EF            [ 1]   81 	and	a, #0xef
      008137 C7 50 08         [ 1]   82 	ld	0x5008, a
                                     83 ;	src/GPIO.c: 21: GPIOB->CR1 &= ~0x20;  // Set PB5 as open drain.
      00813A C6 50 08         [ 1]   84 	ld	a, 0x5008
      00813D A4 DF            [ 1]   85 	and	a, #0xdf
      00813F C7 50 08         [ 1]   86 	ld	0x5008, a
                                     87 ;	src/GPIO.c: 24: GPIOB->CR2 &= ~0x10;  // Set speed for PB4 2 MHz.
      008142 C6 50 09         [ 1]   88 	ld	a, 0x5009
      008145 A4 EF            [ 1]   89 	and	a, #0xef
      008147 C7 50 09         [ 1]   90 	ld	0x5009, a
                                     91 ;	src/GPIO.c: 25: GPIOB->CR2 &= ~0x20;  // Set speed for PB5 2 MHz.
      00814A C6 50 09         [ 1]   92 	ld	a, 0x5009
      00814D A4 DF            [ 1]   93 	and	a, #0xdf
      00814F C7 50 09         [ 1]   94 	ld	0x5009, a
                                     95 ;	src/GPIO.c: 28: GPIOB->ODR |= 0x10;   // Set hlvl on PB4.
      008152 C6 50 05         [ 1]   96 	ld	a, 0x5005
      008155 AA 10            [ 1]   97 	or	a, #0x10
      008157 C7 50 05         [ 1]   98 	ld	0x5005, a
                                     99 ;	src/GPIO.c: 29: GPIOB->ODR |= 0x20;   // Set hlvl on PB5.
      00815A C6 50 05         [ 1]  100 	ld	a, 0x5005
      00815D AA 20            [ 1]  101 	or	a, #0x20
      00815F C7 50 05         [ 1]  102 	ld	0x5005, a
      008162                        103 00101$:
                                    104 ;	src/GPIO.c: 30: }
      008162 81               [ 4]  105 	ret
                                    106 ;	src/GPIO.c: 32: void GPIOC_Config (void){
                                    107 ;	-----------------------------------------
                                    108 ;	 function GPIOC_Config
                                    109 ;	-----------------------------------------
      008163                        110 _GPIOC_Config:
                                    111 ;	src/GPIO.c: 34: GPIOC->DDR |= 0x08;   // Set PC3 as out.
      008163 C6 50 0C         [ 1]  112 	ld	a, 0x500c
      008166 AA 08            [ 1]  113 	or	a, #0x08
      008168 C7 50 0C         [ 1]  114 	ld	0x500c, a
                                    115 ;	src/GPIO.c: 35: GPIOC->DDR |= 0x10;   // Set PC4 as out.
      00816B C6 50 0C         [ 1]  116 	ld	a, 0x500c
      00816E AA 10            [ 1]  117 	or	a, #0x10
      008170 C7 50 0C         [ 1]  118 	ld	0x500c, a
                                    119 ;	src/GPIO.c: 36: GPIOC->DDR |= 0x20;   // Set PC5 as out.
      008173 C6 50 0C         [ 1]  120 	ld	a, 0x500c
      008176 AA 20            [ 1]  121 	or	a, #0x20
      008178 C7 50 0C         [ 1]  122 	ld	0x500c, a
                                    123 ;	src/GPIO.c: 37: GPIOC->DDR |= 0x40;   // Set PC6 as out.
      00817B C6 50 0C         [ 1]  124 	ld	a, 0x500c
      00817E AA 40            [ 1]  125 	or	a, #0x40
      008180 C7 50 0C         [ 1]  126 	ld	0x500c, a
                                    127 ;	src/GPIO.c: 38: GPIOC->DDR |= 0x80;   // Set PC7 as out.
      008183 C6 50 0C         [ 1]  128 	ld	a, 0x500c
      008186 AA 80            [ 1]  129 	or	a, #0x80
      008188 C7 50 0C         [ 1]  130 	ld	0x500c, a
                                    131 ;	src/GPIO.c: 41: GPIOC->CR1 |= 0x08;   // Set PC3 as push pull.
      00818B C6 50 0D         [ 1]  132 	ld	a, 0x500d
      00818E AA 08            [ 1]  133 	or	a, #0x08
      008190 C7 50 0D         [ 1]  134 	ld	0x500d, a
                                    135 ;	src/GPIO.c: 42: GPIOC->CR1 |= 0x10;   // Set PC4 as push pull.
      008193 C6 50 0D         [ 1]  136 	ld	a, 0x500d
      008196 AA 10            [ 1]  137 	or	a, #0x10
      008198 C7 50 0D         [ 1]  138 	ld	0x500d, a
                                    139 ;	src/GPIO.c: 43: GPIOC->CR1 |= 0x20;   // Set PC5 as push pull.
      00819B C6 50 0D         [ 1]  140 	ld	a, 0x500d
      00819E AA 20            [ 1]  141 	or	a, #0x20
      0081A0 C7 50 0D         [ 1]  142 	ld	0x500d, a
                                    143 ;	src/GPIO.c: 44: GPIOC->CR1 |= 0x40;   // Set PC6 as push pull.
      0081A3 C6 50 0D         [ 1]  144 	ld	a, 0x500d
      0081A6 AA 40            [ 1]  145 	or	a, #0x40
      0081A8 C7 50 0D         [ 1]  146 	ld	0x500d, a
                                    147 ;	src/GPIO.c: 45: GPIOC->CR1 |= 0x80;   // Set PC7 as push pull.
      0081AB C6 50 0D         [ 1]  148 	ld	a, 0x500d
      0081AE AA 80            [ 1]  149 	or	a, #0x80
      0081B0 C7 50 0D         [ 1]  150 	ld	0x500d, a
                                    151 ;	src/GPIO.c: 48: GPIOC->CR2 &= ~0x08;  // Set speed for PC3 2 MHz.
      0081B3 C6 50 0E         [ 1]  152 	ld	a, 0x500e
      0081B6 A4 F7            [ 1]  153 	and	a, #0xf7
      0081B8 C7 50 0E         [ 1]  154 	ld	0x500e, a
                                    155 ;	src/GPIO.c: 49: GPIOC->CR2 &= ~0x10;  // Set speed for PC4 2 MHz.
      0081BB C6 50 0E         [ 1]  156 	ld	a, 0x500e
      0081BE A4 EF            [ 1]  157 	and	a, #0xef
      0081C0 C7 50 0E         [ 1]  158 	ld	0x500e, a
                                    159 ;	src/GPIO.c: 50: GPIOC->CR2 &= ~0x20;  // Set speed for PC5 2 MHz.
      0081C3 C6 50 0E         [ 1]  160 	ld	a, 0x500e
      0081C6 A4 DF            [ 1]  161 	and	a, #0xdf
      0081C8 C7 50 0E         [ 1]  162 	ld	0x500e, a
                                    163 ;	src/GPIO.c: 51: GPIOC->CR2 &= ~0x40;  // Set speed for PC6 2 MHz.
      0081CB C6 50 0E         [ 1]  164 	ld	a, 0x500e
      0081CE A4 BF            [ 1]  165 	and	a, #0xbf
      0081D0 C7 50 0E         [ 1]  166 	ld	0x500e, a
                                    167 ;	src/GPIO.c: 52: GPIOC->CR2 &= ~0x80;  // Set speed for PC7 2 MHz.
      0081D3 C6 50 0E         [ 1]  168 	ld	a, 0x500e
      0081D6 A4 7F            [ 1]  169 	and	a, #0x7f
      0081D8 C7 50 0E         [ 1]  170 	ld	0x500e, a
                                    171 ;	src/GPIO.c: 55: GPIOC->ODR |= 0x08;   // Set hlvl on PC3.
      0081DB C6 50 0A         [ 1]  172 	ld	a, 0x500a
      0081DE AA 08            [ 1]  173 	or	a, #0x08
      0081E0 C7 50 0A         [ 1]  174 	ld	0x500a, a
                                    175 ;	src/GPIO.c: 56: GPIOC->ODR &= ~0x10;  // Set llvl on PC4.
      0081E3 C6 50 0A         [ 1]  176 	ld	a, 0x500a
      0081E6 A4 EF            [ 1]  177 	and	a, #0xef
      0081E8 C7 50 0A         [ 1]  178 	ld	0x500a, a
                                    179 ;	src/GPIO.c: 57: GPIOC->ODR &= ~0x20;  // Set llvl on PC5.
      0081EB C6 50 0A         [ 1]  180 	ld	a, 0x500a
      0081EE A4 DF            [ 1]  181 	and	a, #0xdf
      0081F0 C7 50 0A         [ 1]  182 	ld	0x500a, a
                                    183 ;	src/GPIO.c: 58: GPIOC->ODR &= ~0x40;  // Set llvl on PC6.
      0081F3 C6 50 0A         [ 1]  184 	ld	a, 0x500a
      0081F6 A4 BF            [ 1]  185 	and	a, #0xbf
      0081F8 C7 50 0A         [ 1]  186 	ld	0x500a, a
                                    187 ;	src/GPIO.c: 59: GPIOC->ODR &= ~0x80;  // Set llvl on PC7.
      0081FB C6 50 0A         [ 1]  188 	ld	a, 0x500a
      0081FE A4 7F            [ 1]  189 	and	a, #0x7f
      008200 C7 50 0A         [ 1]  190 	ld	0x500a, a
      008203                        191 00101$:
                                    192 ;	src/GPIO.c: 61: }
      008203 81               [ 4]  193 	ret
                                    194 ;	src/GPIO.c: 63: void GPIOD_Config (void){
                                    195 ;	-----------------------------------------
                                    196 ;	 function GPIOD_Config
                                    197 ;	-----------------------------------------
      008204                        198 _GPIOD_Config:
                                    199 ;	src/GPIO.c: 65: GPIOD->DDR |= 0x04;   // Set PD2 as out.
      008204 C6 50 11         [ 1]  200 	ld	a, 0x5011
      008207 AA 04            [ 1]  201 	or	a, #0x04
      008209 C7 50 11         [ 1]  202 	ld	0x5011, a
                                    203 ;	src/GPIO.c: 66: GPIOD->DDR |= 0x08;   // Set PD3 as out.
      00820C C6 50 11         [ 1]  204 	ld	a, 0x5011
      00820F AA 08            [ 1]  205 	or	a, #0x08
      008211 C7 50 11         [ 1]  206 	ld	0x5011, a
                                    207 ;	src/GPIO.c: 67: GPIOD->DDR |= 0x10;   // Set PD4 as out.
      008214 C6 50 11         [ 1]  208 	ld	a, 0x5011
      008217 AA 10            [ 1]  209 	or	a, #0x10
      008219 C7 50 11         [ 1]  210 	ld	0x5011, a
                                    211 ;	src/GPIO.c: 68: GPIOD->DDR |= 0x20;   // Set PD5 as out.
      00821C C6 50 11         [ 1]  212 	ld	a, 0x5011
      00821F AA 20            [ 1]  213 	or	a, #0x20
      008221 C7 50 11         [ 1]  214 	ld	0x5011, a
                                    215 ;	src/GPIO.c: 69: GPIOD->DDR &= ~0x40;   // Set PD6 as input.
      008224 C6 50 11         [ 1]  216 	ld	a, 0x5011
      008227 A4 BF            [ 1]  217 	and	a, #0xbf
      008229 C7 50 11         [ 1]  218 	ld	0x5011, a
                                    219 ;	src/GPIO.c: 72: GPIOD->CR1 |= 0x04;   // Set PD2 as push pull.
      00822C C6 50 12         [ 1]  220 	ld	a, 0x5012
      00822F AA 04            [ 1]  221 	or	a, #0x04
      008231 C7 50 12         [ 1]  222 	ld	0x5012, a
                                    223 ;	src/GPIO.c: 73: GPIOD->CR1 |= 0x08;   // Set PD3 as push pull.
      008234 C6 50 12         [ 1]  224 	ld	a, 0x5012
      008237 AA 08            [ 1]  225 	or	a, #0x08
      008239 C7 50 12         [ 1]  226 	ld	0x5012, a
                                    227 ;	src/GPIO.c: 74: GPIOD->CR1 |= 0x10;   // Set PD4 as push pull.
      00823C C6 50 12         [ 1]  228 	ld	a, 0x5012
      00823F AA 10            [ 1]  229 	or	a, #0x10
      008241 C7 50 12         [ 1]  230 	ld	0x5012, a
                                    231 ;	src/GPIO.c: 75: GPIOD->CR1 |= 0x20;   // Set PD5 as push pull.
      008244 C6 50 12         [ 1]  232 	ld	a, 0x5012
      008247 AA 20            [ 1]  233 	or	a, #0x20
      008249 C7 50 12         [ 1]  234 	ld	0x5012, a
                                    235 ;	src/GPIO.c: 76: GPIOD->CR1 &= ~0x40;   // Set PD6 as floating input.
      00824C C6 50 12         [ 1]  236 	ld	a, 0x5012
      00824F A4 BF            [ 1]  237 	and	a, #0xbf
      008251 C7 50 12         [ 1]  238 	ld	0x5012, a
                                    239 ;	src/GPIO.c: 79: GPIOD->CR2 &= ~0x04;   // Set speed for PD2 2 MHz.
      008254 C6 50 13         [ 1]  240 	ld	a, 0x5013
      008257 A4 FB            [ 1]  241 	and	a, #0xfb
      008259 C7 50 13         [ 1]  242 	ld	0x5013, a
                                    243 ;	src/GPIO.c: 80: GPIOD->CR2 &= ~0x08;   // Set speed for PD3 2 MHz.
      00825C C6 50 13         [ 1]  244 	ld	a, 0x5013
      00825F A4 F7            [ 1]  245 	and	a, #0xf7
      008261 C7 50 13         [ 1]  246 	ld	0x5013, a
                                    247 ;	src/GPIO.c: 81: GPIOD->CR2 &= ~0x10;   // Set speed for PD4 2 MHz.
      008264 C6 50 13         [ 1]  248 	ld	a, 0x5013
      008267 A4 EF            [ 1]  249 	and	a, #0xef
      008269 C7 50 13         [ 1]  250 	ld	0x5013, a
                                    251 ;	src/GPIO.c: 82: GPIOD->CR2 &= ~0x20;   // Set speed for PD5 2 MHz.
      00826C C6 50 13         [ 1]  252 	ld	a, 0x5013
      00826F A4 DF            [ 1]  253 	and	a, #0xdf
      008271 C7 50 13         [ 1]  254 	ld	0x5013, a
                                    255 ;	src/GPIO.c: 83: GPIOD->CR2 &= ~0x40;   // External interrupt disable for PD6.
      008274 C6 50 13         [ 1]  256 	ld	a, 0x5013
      008277 A4 BF            [ 1]  257 	and	a, #0xbf
      008279 C7 50 13         [ 1]  258 	ld	0x5013, a
                                    259 ;	src/GPIO.c: 86: GPIOD->ODR &= ~0x04;   // Set llvl on PD2.
      00827C C6 50 0F         [ 1]  260 	ld	a, 0x500f
      00827F A4 FB            [ 1]  261 	and	a, #0xfb
      008281 C7 50 0F         [ 1]  262 	ld	0x500f, a
                                    263 ;	src/GPIO.c: 87: GPIOD->ODR &= ~0x08;   // Set llvl on PD3.
      008284 C6 50 0F         [ 1]  264 	ld	a, 0x500f
      008287 A4 F7            [ 1]  265 	and	a, #0xf7
      008289 C7 50 0F         [ 1]  266 	ld	0x500f, a
                                    267 ;	src/GPIO.c: 88: GPIOD->ODR &= ~0x10;   // Set llvl on PD4.
      00828C C6 50 0F         [ 1]  268 	ld	a, 0x500f
      00828F A4 EF            [ 1]  269 	and	a, #0xef
      008291 C7 50 0F         [ 1]  270 	ld	0x500f, a
                                    271 ;	src/GPIO.c: 89: GPIOD->ODR &= ~0x20;   // Set llvl on PD5.
      008294 C6 50 0F         [ 1]  272 	ld	a, 0x500f
      008297 A4 DF            [ 1]  273 	and	a, #0xdf
      008299 C7 50 0F         [ 1]  274 	ld	0x500f, a
      00829C                        275 00101$:
                                    276 ;	src/GPIO.c: 90: }
      00829C 81               [ 4]  277 	ret
                                    278 	.area CODE
                                    279 	.area CONST
                                    280 	.area INITIALIZER
                                    281 	.area CABS (ABS)

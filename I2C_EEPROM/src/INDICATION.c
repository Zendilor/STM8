#include "stm8s.h"
#include "GPIO.h"

uint8_t seg_num [3];

void Numbers (uint8_t number);

void Indication (uint8_t seg){
	switch (seg) {
		case 0:
		DIG_1_ON;
		DIG_2_OFF;
		DIG_3_OFF;
		Numbers(seg_num[0]);
		break;
		case 1:
		DIG_1_OFF;
		DIG_2_ON;
		DIG_3_OFF;
		Numbers(seg_num[1]);
		break;
		case 2:
		DIG_1_OFF;
		DIG_2_OFF;
		DIG_3_ON;
		Numbers(seg_num[2]);
		break;
	}
}

void Numbers (uint8_t number){
	switch (number) {
		case 0:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_ON;
			SEG_F_ON;
			SEG_G_OFF;
			SEG_DP_OFF;
		break;
		case 1:
			SEG_A_OFF;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_OFF;
			SEG_E_OFF;
			SEG_F_OFF;
			SEG_G_OFF;
			SEG_DP_OFF;
		break;
		case 2:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_OFF;
			SEG_D_ON;
			SEG_E_ON;
			SEG_F_OFF;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 3:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_OFF;
			SEG_F_OFF;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 4:
			SEG_A_OFF;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_OFF;
			SEG_E_OFF;
			SEG_F_ON;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 5:
			SEG_A_ON;
			SEG_B_OFF;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_OFF;
			SEG_F_ON;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 6:
			SEG_A_ON;
			SEG_B_OFF;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_ON;
			SEG_F_ON;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 7:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_OFF;
			SEG_E_OFF;
			SEG_F_OFF;
			SEG_G_OFF;
			SEG_DP_OFF;
		break;
		case 8:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_ON;
			SEG_F_ON;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
		case 9:
			SEG_A_ON;
			SEG_B_ON;
			SEG_C_ON;
			SEG_D_ON;
			SEG_E_OFF;
			SEG_F_ON;
			SEG_G_ON;
			SEG_DP_OFF;
		break;
	}
}

#include "stm8s.h"
#include "I2C.h"
#include "NXP8563T.h"


void NXP8563T_Config (void){
	//NXP8563T_Write_Time(MINUTES_REG, 54);
	//NXP8563T_Write_Time(HOURS_REG, 9);
}

char NXP8563T_Read_Time (char REG){
	char data = 0;
	char Time = 0;
	data = I2C_Read(ADDR_W, REG, ADDR_R);
	Time = ((data >> 4) * 10);
	Time |= (data & 0x0F);
	return Time;
}

/*void NXP8563T_Write_Time (char REG, char DATA){
	char Seg1 = (DATA / 10);
	char Seg2 = (DATA % 10);
	char Time = (Seg1 << 4) | Seg2;
	I2C1_Write(ADDR_W, REG, Time);
}*/

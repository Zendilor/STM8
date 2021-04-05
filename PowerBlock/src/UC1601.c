#include "I2C.h"
#include "stm8s.h"
#include "UC1601S.h"
#include "UART.h"

#define D				0x02		// Data write
#define C				&~0x02
#define Address 0x70		// Address UC1601S

void BIAS (uint8_t BIAS);
void Display_Clean (void);
void VBIAS (uint8_t VBIAS);
void Write_Data_Byte (uint8_t Data);
void Page_Address_Set (uint8_t PAGE);
void LCD_Mapping_Control (void);
void Display_Onn_Off (uint8_t Onn_Off);
void Com_End_Set (uint8_t Size_Display);
void Columm_Address_Set (uint8_t Columm);
void Temperature_Compensation (uint8_t TEMP);

void UC1601S_Config (void){
	BIAS(BIAS_8);
	VBIAS(70);
	LCD_Mapping_Control();
	//Com_End_Set(30);
	Page_Address_Set(8);
	Columm_Address_Set(130);
	Write_Data_Byte(0x00);
	Display_Onn_Off(Onn);
}

void Temperature_Compensation (uint8_t TEMP){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((Temperature_REG & ~0x03) | TEMP);
	I2C_Send_Stop();
}

void Voltage_Control (uint8_t Voltage){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((Voltage_Control_REG & ~0x07) | Voltage);
	I2C_Send_Stop();
}

void Page_Address_Set (uint8_t PAGE){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((0b10110000 & 0xF0) | PAGE);
	I2C_Send_Stop();
}

void Display_Onn_Off (uint8_t Onn_Off){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((Display_REG & ~0x01) | Onn_Off);
	I2C_Send_Stop();
}

void BIAS (uint8_t BIAS){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((BIAS_REG & ~0x03) | BIAS);
	I2C_Send_Stop();
}
void VBIAS (uint8_t VBIAS){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(VBIAS_REG);
	I2C_Send_Data(VBIAS);
	I2C_Send_Stop();
}

void Columm_Address_Set (uint8_t Columm){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(0x0F & Columm);
	I2C_Send_Data(0x10 | (Columm >> 4));
	I2C_Send_Stop();
}

void Write_Data_Byte (uint8_t Data){
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Data(Data);
	I2C_Send_Stop();
}

void Display_Clean (void){
	Page_Address_Set(3);
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	for (char i = 0; i > 131; i++){
		I2C_Send_Data(0x00);
	}
	I2C_Send_Stop();
}

void Com_End_Set (uint8_t Size_Display){
	I2C_Send_Start();
	I2C_Send_Address(COM_END_REG);
	I2C_Send_Data(Size_Display);
	I2C_Send_Stop();
}

void LCD_Mapping_Control (void){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(0b11000110);
	I2C_Send_Stop();
}

/*void Display_Start (uint){

}*/

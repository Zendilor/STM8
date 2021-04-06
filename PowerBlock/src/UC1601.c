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
void LCD_Mapping_Control (void);
void Write_Data_Byte (uint8_t Data);
void Page_Address_Set (uint8_t PAGE);
void Display_Onn_Off (uint8_t Onn_Off);
void Com_End_Set (uint8_t Size_Display);
void Display_Partial_End (uint8_t Size);
void Columm_Address_Set (uint8_t Columm);
void Display_Partial_Start (uint8_t Size);
void RAM_Address_Control (uint8_t Controls);
void Temperature_Compensation (uint8_t TEMP);
void Display_Partial_Enable (uint8_t Enable_Disable);

void UC1601S_Config (void){
	//Display_Partial_Enable(Enable);
	Display_Partial_Start(40);
	Display_Partial_End(131);
	Com_End_Set(31);
	LCD_Mapping_Control();
	Display_Clean();
	Page_Address_Set(0);
	Columm_Address_Set(0);

	Write_Data_Byte(0x7F);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x3E);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x3E);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x1F);
	Write_Data_Byte(0x20);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x20);
	Write_Data_Byte(0x1F);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x7F);
	Write_Data_Byte(0x49);
	Write_Data_Byte(0x49);
	Write_Data_Byte(0x49);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x00);
	Write_Data_Byte(0x00);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x07);
	Write_Data_Byte(0x08);
	Write_Data_Byte(0x78);
	Write_Data_Byte(0x08);
	Write_Data_Byte(0x07);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x3E);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x41);
	Write_Data_Byte(0x3E);
	Write_Data_Byte(0x00);

	Write_Data_Byte(0x3F);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x40);
	Write_Data_Byte(0x3F);
	Write_Data_Byte(0x00);

	BIAS(BIAS_6);
	VBIAS(120);
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
	I2C_Send_Stop();
}

void Display_Clean (void){
	Page_Address_Set(4);
	Columm_Address_Set(0);
	for (uint16_t count = 0; count < 1056; count++){
		Write_Data_Byte(0x00);
	}
}

void Com_End_Set (uint8_t Size_Display){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(COM_END_REG);
	I2C_Send_Data(Size_Display);
	I2C_Send_Stop();
}

void LCD_Mapping_Control (void){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(0b11000100);
	I2C_Send_Stop();
}

void RAM_Address_Control (uint8_t Controls){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(RAM_Address_Control_REG | (0x7 & Controls));
	I2C_Send_Stop();
}

void Display_Partial_End (uint8_t Size){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Display_END_REG);
	I2C_Send_Data(Size);
	I2C_Send_Stop();
}

void Display_Partial_Start (uint8_t Size){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Display_Start_REG);
	I2C_Send_Data(Size);
	I2C_Send_Stop();
}

void Display_Partial_Enable (uint8_t Enable_Disable){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Display_Partial_Enable_REG | (0x1 & Enable_Disable));
	I2C_Send_Stop();
}

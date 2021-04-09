#include "I2C.h"
#include "stm8s.h"
#include "UC1601S.h"
#include "UART.h"

uint8_t buffer [] = {
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

#define D				0x02		// Data write
#define C				&~0x02
#define Address 0x70		// Address UC1601S

void System_Reset (void);
void BIAS (uint8_t BIAS);
void Display_Clean (void);
void VBIAS (uint8_t VBIAS);
void Scrol_Line (uint8_t Line);
void Write_Data (uint8_t Data);
void Frame_Rate (uint8_t Frame);
void Pixel_Enable (uint8_t Onn_Off);
void Partial_Enable (uint8_t En_Dis);
void Cursor_Set (uint8_t Y, uint8_t X);
void LCD_Mapping_Control (uint8_t Y_X);
void Display_Onn_Off (uint8_t Onn_Off);
void Inversion_On_Off (uint8_t Onn_Off);
void Com_End_Set (uint8_t Size_Display);
void Display_Partial_End (uint8_t Size);
void Display_Partial_Start (uint8_t Size);
void RAM_Address_Control (uint8_t Controls);
void Temperature_Compensation (uint8_t TEMP);
void Write_String (uint8_t Y, uint8_t X, uint8_t *buff, uint8_t size);


void UC1601S_Config (void){
	System_Reset();
	LCD_Mapping_Control(0x04);
	Frame_Rate(0x01);
	Com_End_Set(31);
	BIAS(BIAS_7);
	VBIAS(50);
	Display_Clean();
	Write_String(3, 4, buffer,sizeof buffer);
	Display_Onn_Off(Onn);
}

void Write_String (uint8_t Y, uint8_t X, uint8_t *buff, uint8_t size){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Page_Addres_REG | (0x0F & Y));
	I2C_Send_Data(Column_LSB_REG |(0x0F & X));
	I2C_Send_Data(Column_MSB_REG | (X >> 4));
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	while(size--){
		I2C_Send_Data(*(buff++));
	}
}

void Write_Data (uint8_t Data){
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	I2C_Send_Data(Data);
	I2C_Send_Stop();
}

void Cursor_Set (uint8_t Y, uint8_t X){
	if(Y > 3);
	Y=0;
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Page_Addres_REG | (0x0F & Y));
	I2C_Send_Data(Column_LSB_REG | X);
	I2C_Send_Data(Column_MSB_REG | (X >> 4));
	I2C_Send_Stop();
}

void Display_Clean (void){
	Cursor_Set(0, 0);
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	for (uint16_t count = 0; count < 1056; count++){
		I2C_Send_Data(0x00);
	}
	I2C_Send_Stop();
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
	I2C_Send_Data(Voltage_Control_REG | (0x07 & Voltage));
	I2C_Send_Stop();
}

void Scrol_Line (uint8_t Line){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Line | (0x1F & Line));
	I2C_Send_Stop();
}

void VBIAS (uint8_t VBIAS){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(VBIAS_REG);
	I2C_Send_Data(VBIAS);
	I2C_Send_Stop();
}

void Partial_Enable (uint8_t En_Dis){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Partial_REG | (0x01 & En_Dis));
	I2C_Send_Stop();
}

void RAM_Address_Control (uint8_t Controls){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(RAM_Address_Control_REG | (0x7 & Controls));
	I2C_Send_Stop();
}

void Frame_Rate (uint8_t Frame){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Frame_REG | (0x01 & Frame));
	I2C_Send_Stop();
}

void Pixel_Enable (uint8_t Onn_Off){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Pixel_REG | (0x01 & Onn_Off));
	I2C_Send_Stop();
}

void Inversion_On_Off (uint8_t Onn_Off){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Inversion_REG | (Onn_Off | 0x01));
	I2C_Send_Stop();
}

void Display_Onn_Off (uint8_t Onn_Off){
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((Display_REG & ~0x01) | Onn_Off);
	I2C_Send_Stop();
}

void LCD_Mapping_Control (uint8_t Y_X){	// Set LCD mirrow control.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(LCD_Mapping_REG | (0x6 & Y_X));
	I2C_Send_Stop();
}

void System_Reset (void){	// Send system reset.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(System_Reset_REG);
	I2C_Send_Stop();
}

void BIAS (uint8_t BIAS){	// Set LCD BIAS.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data((BIAS_REG & ~0x03) | BIAS);
	I2C_Send_Stop();
}

void Com_End_Set (uint8_t Size_Display){	// Set CEN register.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(COM_END_REG);
	I2C_Send_Data(Size_Display);
	I2C_Send_Stop();
}

void Display_Partial_Start (uint8_t Size){	// Set DST register.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Display_Start_REG);
	I2C_Send_Data(Size);
	I2C_Send_Stop();
}

void Display_Partial_End (uint8_t Size){	// Set DEN register.
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Display_END_REG);
	I2C_Send_Data(Size);
	I2C_Send_Stop();
}

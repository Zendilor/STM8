#include "I2C.h"
#include "stm8s.h"
#include "UC1601S.h"
#include "UART.h"

#define D				0x02		// Data write
#define C				&~0x02
#define Address 0x70		// Address UC1601S



uint8_t Letters [] = {
	0x3E,0x51,0x49,0x45,0x3E, // 0x30 0
};

uint8_t Numbers [] = {
	0x3E,0x51,0x49,0x45,0x3E, // 0x30 0
	0x00,0x42,0x7F,0x40,0x00, // 0x31 1
	0x42,0x61,0x51,0x49,0x46, // 0x32 2
	0x21,0x41,0x45,0x4B,0x31, // 0x33 3
	0x18,0x14,0x12,0x7F,0x10, // 0x34 4
	0x27,0x45,0x45,0x45,0x39, // 0x35 5
	0x3C,0x4A,0x49,0x49,0x30, // 0x36 6
	0x01,0x71,0x09,0x05,0x03, // 0x37 7
	0x36,0x49,0x49,0x49,0x36, // 0x38 8
	0x06,0x49,0x49,0x29,0x1E, // 0x39 9
};

void System_Reset (void);
void BIAS (uint8_t BIAS);
void Display_Clean (void);
void VBIAS (uint8_t VBIAS);
void Scrol_Line (uint8_t Line);
void Write_Data (uint8_t Data);
void Frame_Rate (uint8_t Frame);
void Pixel_Enable (uint8_t Onn_Off);
void Partial_Enable (uint8_t En_Dis);
void Voltage_Control (uint8_t Voltage);
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

void Write_Number (uint8_t Y, uint8_t X, uint8_t Number);	// Test functions.

void UC1601S_Config (void){
	System_Reset();
	LCD_Mapping_Control(0x04);
	Voltage_Control(0x7);
	Display_Partial_Start(0);
	Display_Partial_End(63);
	Partial_Enable(0x1);
	Frame_Rate(0x01);
	Com_End_Set(31);
	BIAS(BIAS_7);
	VBIAS(50);
	Display_Clean();
	//Write_String(0,0,test_buff, sizeof test_buff);
	Display_Onn_Off(Onn);
}

void Write_Number (uint8_t Y, uint8_t X, uint8_t Number){
	Number = Number * 5;
	uint8_t count = 5;
	I2C_Send_Start();
	I2C_Send_Address(Address);
	I2C_Send_Data(Page_Addres_REG | (0x0F & Y));
	I2C_Send_Data(Column_LSB_REG |(0x0F & X));
	I2C_Send_Data(Column_MSB_REG | (X >> 4));
	I2C_Send_Start();
	I2C_Send_Address(Address | D);
	while(count--){
		I2C_Send_Data(Numbers[Number++]);
	}
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

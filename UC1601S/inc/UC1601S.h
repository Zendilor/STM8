#include "stm8s.h"

/* All Registers */
#define Temperature_REG				0x24
#define Voltage_Control_REG 	0x28
#define System_Reset_REG			0xE2
#define LCD_Mapping_REG				0xC0
#define Inversion_REG					0xA6
#define Pixel_REG							0xA2
#define Frame_REG							0xA0
#define Partial_REG						0x84
#define Scrol_Line_REG				0x40
#define Page_Addres_REG				0xB0
#define Column_LSB_REG				0x00
#define Column_MSB_REG				0x10
//////////////////////////////


/* Temperature_Compensation */
#define TEMP_005				0x00
#define TEMP_010				0x01
#define TEMP_015				0x02
#define TEMP_000				0x03
//////////////////////////////

/* Voltage Control */
#define Capacitance_15nF		0x00
#define Capacitance_15_24nF	0x01
#define External_Vlcd				0x00
#define Internal_Vlcd				0x06
//////////////////////////////

/* Page Address */

//////////////////////////////

/* Display */
#define Display_REG		0xAE
#define Off						0x00
#define Onn						0x01
//////////////////////////////

/* BIAS */
#define BIAS_REG			0xE8
#define BIAS_6				0x00
#define BIAS_7				0x01
#define BIAS_8				0x03
#define BIAS_9				0x03
//////////////////////////////

/* VBIAS */
#define VBIAS_REG			0x81
//////////////////////////////

/* COM-END */
#define COM_END_REG		0xF1
//////////////////////////////

/* LCD Mapping control */
#define MX							0x20
#define MY							0x40
//////////////////////////////

/* RAM Address Control */
#define RAM_Address_Control_REG	0x88
//////////////////////////////

/* Partial Display END */
#define Display_END_REG		0xF3
//////////////////////////////

/* Partial Display Start */
#define Display_Start_REG		0xF2
//////////////////////////////

/* Partial Display Start */
#define Display_Partial_Enable_REG	0xF4
#define Enable											0x01
#define Disable											0x00
//////////////////////////////

void UC1601S_Config (void);

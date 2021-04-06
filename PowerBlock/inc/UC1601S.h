#include "stm8s.h"

/* Temperature_Compensation */
#define Temperature_REG	0x24
#define TEMP_005				0x00
#define TEMP_010				0x01
#define TEMP_015				0x02
#define TEMP_000				0x03
//////////////////////////////

/* Voltage Control */
#define Voltage_Control_REG 0x28
#define Capacitance_15nF		0x00
#define Capacitance_15_24nF	0x01
#define External_Vlcd				0x00
#define Internal_Vlcd				0x06
//////////////////////////////

/* Page Address */
#define Page_Addres_REG	0xB0
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
#define LCD_Mapping_REG	0x90
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

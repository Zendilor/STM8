void NXP8563T_Config (void);
char NXP8563T_Read_Time (char REG);
void NXP8563T_Write_Time (char REG, char DATA);

/*Addres write and read*/
#define ADDR_R		0xA3
#define ADDR_W		0xA2
/////////////////////////

/*All Regs*/
#define CONTROL_STATUS1_REG			0x00	// Control status register1.
#define CONTROL_STATUS2_REG			0x01	// Control status register2.
#define VL_SECONDS_REG					0x02	// Seconds register.
#define MINUTES_REG							0x03	// Mitutes register.
#define HOURS_REG								0x04	// Hours register.
#define DAYS_REG								0x05	// Days register.
#define WEEKDAYS_REG						0x06	// Weekdays register.
#define CENTURY_MONTHS_REG			0x07	// Century_months register.
#define YEARS_REG								0x08	// Yers register.
#define MINUTE_ALARM_REG				0x09	// Minute_alarm register.
#define HOUR_ALARM_REG					0x0A	// Hour_alarm register.
#define DAY_ALARM_REG						0x0B	// Day_alarm register.
#define WEEKDAY_ALARM_REG				0x0C	// Weekday_alarm register.
#define CLKOUT_CONTROL_REG			0x0D	// CLKOUT_control register.
#define TIMER_CONTROL_REG				0x0E	// Timer_control register.
#define TIMER_REG								0x0F	// Timer register.

/*Control register1 bits*/
#define TEST1_BIT			0x80
#define STOP_BIT			0x20
#define TESTC_BIT			0x04
//////////////////////////

/*Control register bits*/
#define TI_TP_BIT			0x08
#define AF_BIT				0x04
#define TF_BIT				0x02
#define AIE_BIT				0x01
/////////////////////////


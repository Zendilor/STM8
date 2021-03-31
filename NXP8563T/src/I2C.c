#include "stm8s.h"
#include "UART.h"		// Include for debug.

/* I2C config slow mode */
#define F_CPU					16000000	// CPU frequency in MHz.
#define MaxRiseTime		1000			// Maximum rise front time (see datasheet).
#define Frequency_I2C	100000		// Set speed for I2C (in Hz).

/* I2C slow mode config */
void I2C_Config (void){
	I2C->FREQR = F_CPU / 1000000;																					// Set I2C input frequency.
	I2C->TRISER = (MaxRiseTime / (1000000000 / F_CPU)) + 1;								// Max rise time.
	I2C->CCRL = (1000000000 / Frequency_I2C) / ((1000000000/F_CPU) * 2);	// Set clock control.
	I2C->CR1 |= I2C_CR1_PE;																								// Enable I2C.
}

char I2C_Read (char ADDR_W, char REG, char ADDR_R){
	char data = 0;
	I2C->CR2 |= I2C_CR2_START;
	while(!(I2C->SR1 & I2C_SR1_SB));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;

	I2C->DR = ADDR_W;
	while(!(I2C->SR1 & I2C_SR1_ADDR));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;

	I2C->DR = REG;
	while(!(I2C->SR1 & I2C_SR1_TXE));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;
	I2C->CR2 |= I2C_CR2_STOP;

	I2C->CR2 |= I2C_CR2_START;
	while(!(I2C->SR1 & I2C_SR1_SB));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;


	I2C->DR = ADDR_R;
	while(!(I2C->SR1 & I2C_SR1_ADDR));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;

	while(!(I2C->SR1 & I2C_SR1_RXNE));
	data = I2C->DR;
	I2C->CR2 |= I2C_CR2_STOP;
	return data;
}

#include "stm8s.h"
#include "UART.h"		// Include for debug.

/* I2C config slow mode */
#define F_CPU					16000000	// CPU frequency in MHz.
#define MaxRiseTime		1000			// Maximum rise front time (see datasheet).
#define Frequency_I2C	100000		// Set speed for I2C (in Hz).

/* I2C slow mode config */
void I2C_Config (void){
	I2C->CCRL = (1000000000 / Frequency_I2C) / ((1000000000/F_CPU) * 2);	// Set clock control.
	I2C->TRISER = (MaxRiseTime / (1000000000 / F_CPU)) + 1;								// Max rise time.
	I2C->FREQR = F_CPU / 1000000;																					// Set I2C input frequency.
	I2C->CR1 |= I2C_CR1_PE;																								// Enable I2C.
}

void I2C_Send_Start (void){
	I2C->CR2 |= I2C_CR2_START;
	while(!(I2C->SR1 & I2C_SR1_SB));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;
}

void I2C_Send_Stop (void){
	I2C->CR2 |= I2C_CR2_STOP;
	while(!(I2C->CR2 & I2C_CR2_STOP));
}

void I2C_Send_Address (uint8_t Address){
	I2C->DR = Address;
	while(!(I2C->SR1 & I2C_SR1_ADDR));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;
}

void I2C_Send_Data (uint8_t Data){
	I2C->DR = Data;
	while(!(I2C->SR1 & I2C_SR1_TXE));
	(void) I2C->SR1;
	(void) I2C->SR2;
	(void) I2C->SR3;
}

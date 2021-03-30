#include "stm8s.h"
#include "UART.h"		// Include for debug.

/* I2C slow mode config */
void I2C_Config (void){
	I2C->FREQR = 16;					// Set I2C input frequency.
	I2C->CCRH = 0;
	I2C->CCRL = 80;					// Set clock control. ()(1/100kHz)/2/)125ns.
	I2C->OARH = I2C_OARH_ADDCONF;
	I2C->TRISER = 17;					// Max rise time. 1000 ns / 125 ns.
	I2C->CR1 |= I2C_CR1_PE;		// Enable I2C.
	I2C->CR2  |= I2C_CR2_ACK;	// ACK enable.

	UART_Send(0x36);
	I2C->CR1 = I2C_CR2_START;
	while(!(I2C->SR1 & I2C_SR1_SB));
	UART_Send(0x36);
}

char I2C_Read (char ADDR_W, char REG, char ADDR_R){
	char data = 0;
	I2C->CR1 |= I2C_CR2_START;
	//while(!(I2C->SR1 & I2C_SR1_SB));
	(void) I2C->SR1;
	(void) I2C->SR2;

	I2C->DR = ADDR_W;
	//while(!(I2C->SR1 & I2C_SR1_ADDR));
	(void) I2C->SR1;
	(void) I2C->SR2;

	I2C->DR = REG;
	//while(!(I2C->SR1 & I2C_SR1_TXE));

	I2C->CR1 |= I2C_CR2_STOP;
	I2C->CR1 |= I2C_CR2_START;
	//while(!(I2C->SR1 & I2C_SR1_SB));
	(void) I2C->SR1;

	I2C->DR = ADDR_R;
	//while(!(I2C->SR1 & I2C_SR1_ADDR));
	(void) I2C->SR1;
	(void) I2C->SR2;
	//UART_Send(0x33);
	//while(!(I2C->SR1 & I2C_SR1_RXNE));
	//UART_Send(0x33);
	data = I2C->DR;
	I2C->CR1 |= I2C_CR2_STOP;
	return data;
}

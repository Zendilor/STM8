#include "stm8s.h"

#define F_CPU		16		// Set CPU frequency in MHz.

void I2C_Config (void){
	//I2C->CCRH |= I2C_CCRH_FS;	// Set fast mode cycle.


	I2C->FREQR = F_CPU;				// Set frequency MHz.
	I2C->TRISER = F_CPU +1;		// Set max rise time.
	I2C->CR1 |= I2C_CR1_PE;		// Enable I2C.
}

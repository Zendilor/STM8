#include "stm8s.h"
<<<<<<< HEAD
#include "UART.h"
#include "CLK.h"
=======

#define FLASH_START *(uint8_t*)0x4000

eeprom data = 0;
>>>>>>> 17bc8e848d4f6a5d2679e0cac89cf159c4c85621

int main (void){
  CLK_Config();
	UART_Config();
<<<<<<< HEAD
	/*FLASH->DUKR = 0xAE;
	FLASH->DUKR = 0x56;
	while(!(FLASH->IAPSR & FLASH_IAPSR_DUL));

	FLASH->IAPSR &= ~FLASH_IAPSR_DUL;*/
  UART_Send(0x31);

=======
	EEPROM_Config();
	/*FLASH->DUKR = 0xAE;
	FLASH->DUKR = 0x56;
	while(!(FLASH->IAPSR & FLASH_IAPSR_DUL));
	FLASH_START = 0x3639;
	FLASH->IAPSR &= ~FLASH_IAPSR_DUL;*/
	UART_Send_16bit(FLASH_START);
>>>>>>> 17bc8e848d4f6a5d2679e0cac89cf159c4c85621
  while (1){

  }
}

INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
	UART_Send(UART1->DR);
	UART_Send(0x31);
}


INTERRUPT_HANDLER(IRQ_TIMER2, 13){
	TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.

}

INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
  ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1
}

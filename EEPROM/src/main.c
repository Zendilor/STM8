#include "stm8s.h"
#include "UART.h"
#include "CLK.h"

int main (void){
  CLK_Config();
	UART_Config();
	/*FLASH->DUKR = 0xAE;
	FLASH->DUKR = 0x56;
	while(!(FLASH->IAPSR & FLASH_IAPSR_DUL));

	FLASH->IAPSR &= ~FLASH_IAPSR_DUL;*/
  UART_Send(0x31);

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

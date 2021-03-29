#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "stm8s.h"

void Convert_value (void);

int main (void){
	enableInterrupts();
	//CLK_Config();
	//GPIO_Config();
	//TIMER_Config();
	//ADC_Config();

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

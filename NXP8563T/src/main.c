#include "CLK.h"
#include "GPIO.h"
#include "I2C.h"
#include "UART.h"
#include "stm8s.h"
#include "NXP8563T.h"

void Convert_value (void);

int main (void){
	//enableInterrupts();
	CLK_Config();
	UART_Config();
	GPIO_Config();
	I2C_Config();
	//UART_Send(I2C_Read(ADDR_W, CONTROL_STATUS1_REG, ADDR_R));
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

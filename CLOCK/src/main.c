#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "ADC.h"
#include "stm8s.h"

uint16_t data = 0xEFCD;

int main (void){
  enableInterrupts();
  CLK_Config();
  GPIO_Config();
  UART_Config();
  ADC_Config();
  TIMER_Config();

  while (1){

  }
}

INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
  UART_Send(UART1->DR);
}

INTERRUPT_HANDLER(IRQ_TIMER2, 13){
  TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
  UART_Send(0x39);
}

INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
  ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
  //UART_Send_16bit(Get_Result());
  UART_Send(ADC1->DRH);
  ADC1->CR1 |= ADC1_CR1_ADON;
}

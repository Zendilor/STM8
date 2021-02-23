#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "ADC.h"
#include "stm8s.h"

void Convert_value (void);

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
  //UART_Send(UART1->DR);
}

INTERRUPT_HANDLER(IRQ_TIMER2, 13){
  TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
  ADC1->CR1 |= ADC1_CR1_ADON;
}

INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
  ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
  Convert_value();
  //ADC1->CR1 |= ADC1_CR1_ADON;
}

void Convert_value (void){
  unsigned int data = Get_Result();
  UART_Send_16bit(data);
  data = data * 64.0615835;
  TIM2->ARRL = data;
  TIM2->ARRH = data >> 8;
  data = (data * 60) / 100;
  TIM2->CCR1L = data;
  TIM2->CCR1H = data >> 8;
}

#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "ADC.h"
#include "stm8s.h"

char data = 0;

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

INTERRUPT_HANDLER(IRQ_TIMER2,13){
  TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
  UART_Send(0x39);
}

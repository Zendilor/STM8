#include "stm8s.h"

void INTERRUPT_Config (void){
  enableInterrupts();
}

INTERRUPT_HANDLER(IRQHandler_USART1, 18){
  UART1->DR = UART1->DR;
}
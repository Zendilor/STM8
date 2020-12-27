#include "stm8s.h"
#include "UART.h"

void INTERRUPT_Config (void){
  enableInterrupts();
}

/*INTERRUPT_HANDLER(IRQHandler_TIMER2, 13){
  UART_Send(0x35);
  TIM2->SR1 &= ~TIM2_SR1_UIF; // Clear flag interrupt flag.
}*/

/*INTERRUPT_HANDLER(IRQHandler_UART1_RX, 18){
  UART_Send(0x31);
}*/

INTERRUPT_HANDLER(IRQHandler_UART1_TX, 17){
  UART1->SR &= ~UART1_SR_TC;
  UART_Send(0x38);
}

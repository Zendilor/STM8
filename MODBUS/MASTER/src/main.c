#include "CLK.h"
#include "UART.h"
#include "TIMER.h"
#include "MODBUS.h"
#include "stm8s.h"


int main (void){
  CLK_Config();
  UART_Config();
  MASTER_Send();
  TIMER_Config();

  enableInterrupts();
  //UART_Send(0x31);
  while (1){

  }
}

INTERRUPT_HANDLER(IRQ_UART1_RX, 18){

}

INTERRUPT_HANDLER(IRQ_TIMER2, 13){
  TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag TIMER2.
  MASTER_Send();
  //UART_Send(0x31);
}

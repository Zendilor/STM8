#include "stm8s.h"

void UART_Config (void){
  UART1->BRR1 = 0x0D;
  UART1->BRR2 = 0x00;
  UART1->CR2 |= 0x08;
  UART1->CR2 |= 0x04;
  UART1->CR2 |= 0x20;
}

void UART_Send (char data){
  UART1->DR = data;
  while(!(UART1->SR & 0x40));
}
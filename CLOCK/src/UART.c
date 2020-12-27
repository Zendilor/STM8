#include "stm8s.h"

void UART_Config (void){
  //UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
  //UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
  //UART1->CR2 |= UART1_CR2_RIEN; // Enable interrupt receive.
  UART1->BRR1 = 0x68;
  UART1->BRR2 = 0x02;
  UART1->CR2 |= UART1_CR2_TCIEN;
  UART1->CR2 |= 0x08;
  UART1->CR2 |= 0x04;
  UART1->CR2 |= 0x20;
}

void UART_Send (uint8_t data){
  while(!(UART1->SR & UART1_SR_TXE));
  UART1->DR = data;
  //while(!(UART1->SR & UART1_SR_TC));
  //UART1->SR &= ~UART1_SR_TC;
}

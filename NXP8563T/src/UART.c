#include "stm8s.h"
#include "UART.h"


uint32_t frequency = 16000000;     // Frequency MCU.
uint32_t baud_rate = 9600;        // Baud_rate UART1.

void UART_Send (uint8_t data);

void UART_Config (void){
  UART1->BRR1 = ((frequency / baud_rate) & 0x0FF0) >> 4;   // Set bir low bite.
  UART1->BRR2 = (((frequency / baud_rate) & 0xF000) >> 2) | ((frequency / baud_rate) & 0x000F);
  //UART1->CR2 |= UART1_CR2_TCIEN;
  UART1->CR2 |= UART1_CR2_TEN;  // Enable transmit.
  UART1->CR2 |= UART1_CR2_REN;  // Enable receiver.
  //UART1->CR2 |= UART1_CR2_RIEN; // Enable interrupt receive.
}

void UART_Send (uint8_t data){
  while(!(UART1->SR & UART1_SR_TXE));
  UART1->DR = data;
}

void UART_Send_16bit (int data){
  UART_Send(data >> 8);
  UART_Send(data);
}

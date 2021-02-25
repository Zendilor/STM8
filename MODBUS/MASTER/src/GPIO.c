#include "stm8s.h"


void GPIOD_Config (void);

void GPIO_Config (void){
  GPIOD_Config();
}

void GPIOD_Config (void){
  GPIOD->DDR |= 0x20;   // Set PD5(UART_TX) as out.
  GPIOD->DDR &= 0x40;   // Set PD6(UART_RX) as input.


  GPIOD->CR1 |= 0x20;   // Set PD5(UART_TX) push-pull out.
  GPIOD->CR1 &= 0x40;   // Set PD6(UART_RX) floating input.


  GPIOD->CR2 &= 0x20;   // Set speed for PD5(UART_TX) 2 MHz.
  GPIOD->CR2 &= 0x40;   // External interrupt disable.
}

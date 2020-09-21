#include "stm8s.h"

void GPIOA_Config (void); // Config PORTA
void GPIOD_Config (void); // Config PORTD

void GPIO_Config (void){
  GPIOA_Config();
  GPIOD_Config();
}

void GPIOA_Config (void){
  GPIOA->DDR |= 0x08;   // Set PA3 at out.
  GPIOA->CR1 |= 0x08;   // Set PA3 push pull.
  GPIOA->CR2 |= 0x08;   // Set PA3 speed 50 MHz.
}

void GPIOD_Config (void){
  GPIOD->DDR |= 0x04;   // Set PD2 at out.
  GPIOD->CR1 |= 0x04;   // Set PD2 at out.
  GPIOD->CR2 |= 0x04;   // Set PD2 speed 50 MHz.
}
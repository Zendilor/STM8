#include "stm8s.h"

void GPIOB_Config (void);
void GPIOD_Config (void);

void GPIO_Config (void){
  //GPIOB_Config();
  GPIOD_Config();
}

void GPIOB_Config (void){
  GPIOB->DDR |= 0x20; // Set PB5 as out.
  GPIOB->CR1 |= 0x20; // Set PB5 as push-pull.
  GPIOB->ODR &= ~0x20; // Set hlvl to PB5.
}

void GPIOD_Config (void){
  GPIOD->DDR &= ~0x40;  // Set PD6 as input.
  GPIOD->CR1 &= ~0x40;  // Set PD6 floating input.

  GPIOD->DDR |= 0x10;
  GPIOD->CR1 |= 0x10;
  GPIOD->ODR |= 0x10;
}

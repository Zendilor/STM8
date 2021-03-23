#include "stm8s.h"

void GPIOB_Config (void);
void GPIOD_Config (void);
void GPIOC_Config (void);


void GPIO_Config (void){
  GPIOB_Config();
  GPIOC_Config();
  GPIOD_Config();
}

void GPIOB_Config (void){
  /*Config DDR register*/
  GPIOB->DDR |= 0x10;   // Set PB4 as out.
  GPIOB->DDR |= 0x20;   // Set PB5 as out.

  /*Config CR1 register*/
  GPIOB->CR1 &= ~0x10;  // Set PB4 as open drain.
  GPIOB->CR1 &= ~0x20;  // Set PB5 as open drain.

  /*Config CR2 register*/
  GPIOB->CR2 &= ~0x10;  // Set speed for PB4 2 MHz.
  GPIOB->CR2 &= ~0x20;  // Set speed for PB5 2 MHz.

  /*Config ODR register*/
  GPIOB->ODR |= 0x10;   // Set hlvl on PB4.
  GPIOB->ODR |= 0x20;   // Set hlvl on PB5.
}

void GPIOC_Config (void){
  /*Config DDR register*/
  GPIOC->DDR |= 0x08;   // Set PC3 as out.
  GPIOC->DDR |= 0x10;   // Set PC4 as out.
  GPIOC->DDR |= 0x20;   // Set PC5 as out.
  GPIOC->DDR |= 0x40;   // Set PC6 as out.
  GPIOC->DDR |= 0x80;   // Set PC7 as out.

  /*Config CR1 register*/
  GPIOC->CR1 |= 0x08;   // Set PC3 as push pull.
  GPIOC->CR1 |= 0x10;   // Set PC4 as push pull.
  GPIOC->CR1 |= 0x20;   // Set PC5 as push pull.
  GPIOC->CR1 |= 0x40;   // Set PC6 as push pull.
  GPIOC->CR1 |= 0x80;   // Set PC7 as push pull.

  /*Config CR2 register*/
  GPIOC->CR2 &= ~0x08;  // Set speed for PC3 2 MHz.
  GPIOC->CR2 &= ~0x10;  // Set speed for PC4 2 MHz.
  GPIOC->CR2 &= ~0x20;  // Set speed for PC5 2 MHz.
  GPIOC->CR2 &= ~0x40;  // Set speed for PC6 2 MHz.
  GPIOC->CR2 &= ~0x80;  // Set speed for PC7 2 MHz.

  /*Config ODR register*/
  GPIOC->ODR |= 0x08;   // Set hlvl on PC3.
  GPIOC->ODR &= ~0x10;  // Set llvl on PC4.
  GPIOC->ODR &= ~0x20;  // Set llvl on PC5.
  GPIOC->ODR &= ~0x40;  // Set llvl on PC6.
  GPIOC->ODR &= ~0x80;  // Set llvl on PC7.

}

void GPIOD_Config (void){
  /*Config DDR register*/
  GPIOD->DDR |= 0x04;   // Set PD2 as out.
  GPIOD->DDR |= 0x08;   // Set PD3 as out.
  GPIOD->DDR |= 0x10;   // Set PD4 as out.
  GPIOD->DDR |= 0x20;   // Set PD5 as out.
  GPIOD->DDR &= ~0x40;   // Set PD6 as input.

  /*Config CR1 register*/
  GPIOD->CR1 |= 0x04;   // Set PD2 as push pull.
  GPIOD->CR1 |= 0x08;   // Set PD3 as push pull.
  GPIOD->CR1 |= 0x10;   // Set PD4 as push pull.
  GPIOD->CR1 |= 0x20;   // Set PD5 as push pull.
  GPIOD->CR1 &= ~0x40;   // Set PD6 as floating input.

  /*Config CR2 register*/
  GPIOD->CR2 &= ~0x04;   // Set speed for PD2 2 MHz.
  GPIOD->CR2 &= ~0x08;   // Set speed for PD3 2 MHz.
  GPIOD->CR2 &= ~0x10;   // Set speed for PD4 2 MHz.
  GPIOD->CR2 &= ~0x20;   // Set speed for PD5 2 MHz.
  GPIOD->CR2 &= ~0x40;   // External interrupt disable for PD6.

  /*Config ODR register*/
  GPIOD->ODR &= ~0x04;   // Set llvl on PD2.
  GPIOD->ODR &= ~0x08;   // Set llvl on PD3.
  GPIOD->ODR &= ~0x10;   // Set llvl on PD4.
  GPIOD->ODR &= ~0x20;   // Set llvl on PD5.
}

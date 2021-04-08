#include "stm8s.h"

void GPIOB_Config (void);
void GPIOC_Config (void);
void GPIOD_Config (void);


void GPIO_Config (void){
  //GPIOB_Config(); // Config PORTB.
  GPIOC_Config();   // Config PORTC.
  //GPIOD_Config(); // Config PORTD.
}

void GPIOB_Config (void){
  /*Config DDR register*/
  GPIOB->DDR |= 0x10;   // Set PB4 as out.
  GPIOB->DDR |= 0x20;   // Set PB5 as out.

  /*Config CR1 register*/
  GPIOB->CR1 &= ~0x10;  // Set PB4 as open drain.
  GPIOB->CR1 &= ~0x20;  // Set PB5 as open drain.

  /*Config CR2 register*/
  GPIOB->CR2 |= 0x10;  // Set speed for PB4 2 MHz.
  GPIOB->CR2 |= 0x20;  // Set speed for PB5 2 MHz.

  /*Config ODR register*/
  //GPIOB->ODR &= ~0x10;   // Set hlvl on PB4.
  //GPIOB->ODR &= ~0x20;   // Set hlvl on PB5.
}

void GPIOC_Config (void){
  /*Config DDR register*/
  GPIOC->DDR |= 0x08;   // Set PC3 as out.

  /*Config CR1 register*/
  GPIOC->CR1 |= 0x08;  // Set PC3 as push pull.


  /*Config CR2 register*/
  GPIOC->CR2 &= ~0x08;  // Set speed for PC3 2 MHz.

  /*Config ODR register*/
  GPIOC->ODR |= 0x08;   // Set hlvl on PC3.
}

void GPIOD_Config (void){
  /*Config DDR register*/
  GPIOD->DDR |= 0x20;   // Set PD5 as out.
  GPIOD->DDR &= ~0x40;  // Set PD6 as input.

  /*Config CR1 register*/
  GPIOD->CR1 |= 0x20;   // Set PD5 as push pull.
  GPIOD->CR1 &= ~0x40;   // Set PD6 as floating input.

  /*Config CR2 register*/
  GPIOD->CR2 &= ~0x20;   // Set speed for PD5 2 MHz.
  GPIOD->CR2 &= ~0x40;   // External interrupt disable for PD6.

  /*Config ODR register*/
}

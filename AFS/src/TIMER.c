#include "stm8s.h"

uint16_t Divider = 65535;   // Divider timer.
uint8_t Duty = 10;         // Duty cycle(on percent).


void TIMER2_Config (void);
void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER2_Config();
  //TIMER4_Config();
}

void TIMER1_Config (void){
  TIM1->CR1 |= TIM1_CR1_ARPE; // Enable preload.

  TIM1->CR1 |= TIM1_CR1_CEN;   // Enable TIM1.
}

void TIMER2_Config (void){
  TIM2->CCR1H = ((Divider * Duty) / 100) >> 8;
  TIM2->CCR1L = (Divider * Duty) / 100;
  TIM2->ARRH = Divider >> 8;
  TIM2->ARRL = Divider;
  TIM2->CCMR1 |= 0x60;        // Set PWM 1 mode.
  TIM2->CCMR1 |= 0x08;        // Output compare preload enable.
  TIM2->CCER1 |= TIM2_CCER1_CC1E;
  //TIM2->IER |= TIM2_IER_UIE;  // Enable interrupt update.
  TIM2->PSCR = 1;          // Prescaler 1.
  TIM2->CR1 |= TIM2_CR1_CEN;   // Enable counter.
}

/*void TIMER4_Config (void){
  TIM4->CR1 |= TIM4_CR1_ARPE;   // Enable auto-reload.


  TIM4->CR1 |= TIM4_CR1_CEN;    // Enable counter.
}*/

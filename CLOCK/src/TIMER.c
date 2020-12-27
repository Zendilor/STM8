#include "stm8s.h"

void TIMER2_Config (void);
void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER2_Config();
  //TIMER4_Config();
}

void TIMER1_Config (void){

}

void TIMER2_Config (void){
  TIM2->PSCR = 0x08;          // Prescaler 256
  TIM2->ARRH = 0xF4;
  TIM2->ARRL = 0x24;
  TIM2->CR1 |= TIM2_CR1_ARPE; // Enable auto-reload preload mode.
  TIM2->IER |= TIM2_IER_UIE;  // Enable interrupt update.
  TIM2->CR1 |= TIM2_CR1_CEN;   // Enable counter.
}

void TIMER4_Config (void){
  TIM4->CR1 |= TIM4_CR1_ARPE; // Enable auto preload.
  TIM4->IER |= TIM4_IER_UIE;  // Enable interrupt.


  TIM4->CR1 |= TIM4_CR1_CEN;  // Enable counter.
}

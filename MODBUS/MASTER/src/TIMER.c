#include "stm8s.h"

uint16_t Divider = 50000;   // Divider for TIMER2.

void TIMER2_Config (void);

void TIMER_Config (void){
  TIMER2_Config();
}

void TIMER2_Config (void){
  TIM2->ARRH = Divider >> 8;    // High byte counter.
  TIM2->ARRL = Divider;         // Low byte counter.
  TIM2->IER |= TIM2_IER_UIE;    // Enable interrupt update.
  TIM2->PSCR = 10;              // Set prescaler for TIMER2.
  TIM2->CR1 |= TIM2_CR1_ARPE;   // Auto-reload preload enable.
  TIM2->CR1 |= TIM2_CR1_CEN;    // Enable counter.
}

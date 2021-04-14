#include "stm8s.h"

uint16_t Divider = 375;   // Divider timer.
uint8_t Duty = 1;        // Duty cycle(on percent).

uint16_t TIM1_DIV = 15998;    // Divider for TIM1.
uint16_t TIM1_REL = 998;    // Autoreload value.


void TIMER1_Config (void);
void TIMER2_Config (void);
void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER1_Config();
  //TIMER2_Config();
  //TIMER4_Config();
}

void TIMER1_Config (void){
  TIM1->CR1 |= TIM1_CR1_ARPE;   // Enable preload.
  TIM1->PSCRH = TIM1_DIV >> 8;  // Set divider H byte.
  TIM1->PSCRL = TIM1_DIV;       // Set divider L byte.
  TIM1->ARRH = TIM1_REL >> 8;   // Set autoreload H value.
  TIM1->ARRL = TIM1_REL;        // Set autoreload l value.
  TIM1->IER |= TIM1_IER_UIE;    // Enable interrupt.
  TIM1->CR1 |= TIM1_CR1_CEN;    // Enable TIM1.
}

void TIMER2_Config (void){
  TIM2->ARRH = Divider >> 8;
  TIM2->ARRL = Divider;
  TIM2->IER |= TIM2_IER_UIE;  // Enable interrupt update.
  TIM2->PSCR = 8;             // Prescaler 1.
  TIM2->CR1 |= TIM2_CR1_CEN;  // Enable counter.
}

/*void TIMER4_Config (void){
  TIM4->CR1 |= TIM4_CR1_ARPE;   // Enable auto-reload.


  TIM4->CR1 |= TIM4_CR1_CEN;    // Enable counter.
}*/

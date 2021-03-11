#include "stm8s.h"
#include "UART.h"

uint16_t Divider = 15625;   // Divider for TIMER2.

uint16_t Prescaler_TIM1 = 64000;
uint16_t Autoreload_TIM1 = 1;


void TIMER1_Config (void);
void TIMER2_Config (void);
void TIMER4_Config (void);

void TIMER_Config (void){
  TIMER1_Config();
  //TIMER2_Config();
  //TIMER4_Config();
}

void TIMER1_Config (void){
  TIM1->PSCRH = Prescaler_TIM1 >> 8;  // Set prescalar high byte for TIMER1.
  TIM1->PSCRL = Prescaler_TIM1;       // Set prescaler low byte for TIMER1.
  TIM1->ARRH  = Autoreload_TIM1 >> 8; // Set Autoreload high byte for TIMER1.
  TIM1->ARRL  = Autoreload_TIM1;      // Set Autoreload low byte for TIMER1.
  TIM1->CR1 |= TIM1_CR1_ARPE;   // Auto-reload preload enable.
  TIM1->IER |= TIM1_IER_UIE;    // Enable interrupt update.
  TIM1->CR1 |= TIM1_CR1_CEN;    // Enable counter.
}

void TIMER2_Config (void){
  TIM2->ARRH = Divider >> 8;    // High byte counter.
  TIM2->ARRL = Divider;         // Low byte counter.
  TIM2->IER |= TIM2_IER_UIE;    // Enable interrupt update.
  TIM2->PSCR = 10;              // Set prescaler for TIMER2.
  TIM2->CR1 |= TIM2_CR1_ARPE;   // Auto-reload preload enable.
  TIM2->CR1 |= TIM2_CR1_CEN;    // Enable counter.
}

void TIMER4_Config (void){
  TIM4->CR1 |= TIM4_CR1_ARPE;   // Auto-reload preload enable.
  TIM4->IER |= TIM4_IER_UIE;    // Enable interrupt update.

  TIM4->CR1 |= TIM4_CR1_CEN;    // Enable counter.
}

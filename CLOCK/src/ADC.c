#include "stm8s.h"


void ADC_Config (void){
  ADC1->CR1 |= 0x40;          // Set ADC division 8.
  ADC1->CSR |= 0x02;          // Set CH 2.
  ADC1->CR1 |= ADC1_CR1_ADON; // Enable ADC.
  ADC1->CR1 |= ADC1_CR1_ADON; // Start scan.
}

char Get_Result (void){
  while(!(ADC1->CSR & ADC1_CSR_EOC));
  return ADC1->DRH;
}

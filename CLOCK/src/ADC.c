#include "stm8s.h"


void ADC_Config (void){
  ADC1->CR1 |= 0x70;            // Set ADC division 18.
  ADC1->CSR |= 0x02;            // Set CH 2.
  ADC1->CSR |= ADC1_CSR_EOCIE;  // Enable interrupt.
  //ADC1->CR1 |= ADC1_CR1_CONT;   // Enable continuos conversion mode.
  ADC1->CR1 |= ADC1_CR1_ADON;   // Enable ADC.
  ADC1->CR1 |= ADC1_CR1_ADON;   // Start scan.
}

char Get_Result (void){
  return ADC1->DRH;
}

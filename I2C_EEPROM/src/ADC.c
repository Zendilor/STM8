#include "stm8s.h"


void ADC_Config (void){
  ADC1->CR1 |= 0x70;            // Set ADC division 18.
  ADC1->CSR |= 0x06;            // Set CH 6.
  ADC1->CSR |= ADC1_CSR_EOCIE;  // Enable interrupt.
  ADC1->CR2 |= ADC1_CR2_ALIGN;  // Align data to righ.
  ADC1->CR1 |= ADC1_CR1_ADON;   // Enable ADC.
  ADC1->CR1 |= ADC1_CR1_ADON;   // Start scan.
}

uint16_t Get_Result (void){
  int data = ADC1->DRL;
  data |= ADC1->DRH << 8;
  return data;
}

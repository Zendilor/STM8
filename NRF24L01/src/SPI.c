#include "stm8s.h"
#include "SPI.h"

void SPI_Config (void){
  SPI->CR1 |= SPI_CR1_SPE;      // Enable SPI.
  SPI->CR1 |= SPI_CR1_MSTR;     // Set SPI at master.
  SPI->CR2 |= SPI_CR2_SSI;
  SPI->CR2 |= SPI_CR2_SSM;
  NSS_HIGH;
}

char SPI_Send (char data){		// SPI1 Send data.
  SPI->DR = data;
  //while(SPI->SR & SPI_SR_BSY);
  while(!(SPI->SR & SPI_SR_RXNE));
  return SPI->DR;
}

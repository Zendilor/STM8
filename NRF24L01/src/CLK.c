#include "stm8s.h"

void CLK_Config (void){
  CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable peripheral clocking.
  CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable peripheral clocking.

  CLK->PCKENR1 |= CLK_PCKENR1_SPI;    // Enavle clock for SPI.
  CLK->PCKENR1 |= CLK_PCKENR1_UART1;  // Enavle clock for SPI.
}

#include "stm8s.h"
#include "UART.h"
void CLK_Deinit (void);

void CLK_Config (void){
  CLK_Deinit();
  /*Config PCKENR1 and PCKENR2 registers*/
  CLK->PCKENR1 |= CLK_PCKENR1_UART2;  // Enable clock for UART1 (see datasheet).
  CLK->PCKENR1 |= CLK_PCKENR1_I2C;    // Enable clock for I2C.
}

void CLK_Deinit (void){
  CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable all clocking.
  CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable all clocking.
  CLK->CKDIVR &= ~CLK_CKDIVR_RESET_VALUE;   // Disable all divider.
}

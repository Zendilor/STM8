#include "stm8s.h"

void CLK_Config (void){
  CLK->PCKENR1 &= ~CLK_PCKENR1_RESET_VALUE; // Disable all clocking.
  CLK->PCKENR2 &= ~CLK_PCKENR2_RESET_VALUE; // Disable all clocking.
}

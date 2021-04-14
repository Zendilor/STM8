#include "CLK.h"
#include "I2C.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "stm8s.h"
#include "UC1601S.h"

uint8_t data = 255;

int main (void){
	enableInterrupts();
	CLK_Config();
	UART_Config();
	GPIO_Config();
	I2C_Config();
	TIMER_Config();
	UC1601S_Config();

  while (1){
		Write_Number(0,0,data / 100);
		Write_Number(0,6,data % 100 / 10);
		Write_Number(0,12,data % 10);
  }
}

INTERRUPT_HANDLER(IRQ_TIMER1, 11){
	TIM1->SR1 &= ~TIM1_SR1_UIF;   // Clear interrupt flag.
	data --;
}

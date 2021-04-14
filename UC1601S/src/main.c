#include "CLK.h"
#include "I2C.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "stm8s.h"
#include "UC1601S.h"

void UART_Send2 (uint8_t *data, uint8_t size){
   while(!(UART1->SR & UART1_SR_TXE));
	 while(size --){
		 UART1->DR = *(data++);
		 while(!(UART1->SR & UART1_SR_TXE));
	 }
}

int main (void){
	//enableInterrupts();
	CLK_Config();
	UART_Config();
	GPIO_Config();
	I2C_Config();
	TIMER_Config();
	UC1601S_Config();
	UART_Send2("HE",sizeof "HE");
  while (1){

  }
}

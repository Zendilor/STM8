#include "CLK.h"
#include "I2C.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "stm8s.h"
#include "UC1601S.h"

int main (void){
	//enableInterrupts();
	CLK_Config();
	UART_Config();
  //UART_Send(datas);
  //UART_Send1(s);
	//GPIO_Config();
	//I2C_Config();
	//TIMER_Config();
	//UC1601S_Config();
  
  while (1){

  }
}

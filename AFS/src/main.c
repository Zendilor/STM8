#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"
#include "ADC.h"
#include "INDICATION.h"
#include "stm8s.h"

void Convert_value (void);

extern uint8_t seg_num [3];

float coefiz = 0.00322265625;
uint16_t data_ADC = 0;

char segs = 0;

int main (void){
	enableInterrupts();
	CLK_Config();
	GPIO_Config();
	TIMER_Config();
	ADC_Config();

  while (1){

  }
}

INTERRUPT_HANDLER(IRQ_UART1_RX, 18){
	UART_Send(UART1->DR);
	UART_Send(0x31);
}


INTERRUPT_HANDLER(IRQ_TIMER2, 13){
	TIM2->SR1 &= ~TIM2_SR1_UIF;   // Clear interrupt flag.
	Indication(segs);
	segs++;
	if (segs > 2){
		segs = 0;
	}
	ADC1->CR1 |= ADC1_CR1_ADON;
}

INTERRUPT_HANDLER(IRQ_ADC, 22){ // Interrupt body for ADC1.
  ADC1->CSR &= ~ADC1_CSR_EOC;    // Clear flag interrupt for ADC1.
	data_ADC = Get_Result() * coefiz;
	seg_num [0] = data_ADC;
}

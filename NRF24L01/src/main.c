#include "CLK.h"
#include "GPIO.h"
#include "UART.h"
#include "SPI.h"
#include "INTERRUPT.h"
#include "NRF24L01.h"


char FIFO_STATUS = 0;
char STATUS = 0;

int main (void){
  CLK_Config();
  GPIO_Config();
  SPI_Config();
  UART_Config();
  INTERRUPT_Config();

  NRF_Config_Receiver();

  while(1){
    FIFO_STATUS = NRF_READ_REG(FIFO_STATUS_REG);
    STATUS = NRF_READ_REG(STATUS_REG);
    Receiver_IRQ();
    FIFO_STATUS = NRF_READ_REG(FIFO_STATUS_REG);
    STATUS = NRF_READ_REG(STATUS_REG);
  }
}

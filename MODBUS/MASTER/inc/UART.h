//#inclide "stm8s.h"

void UART_Config (void);
void UART_Send (char data);
void UART_Send_16bit (int data);
void UART_Send_Buff (char *buff, char count);

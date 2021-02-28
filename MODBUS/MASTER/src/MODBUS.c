#include "MODBUS.h"
#include "UART.h"
#include "stm8s.h"

uint8_t data [6];

void Send_CRC (uint16_t data);
unsigned int CRC_Calc (unsigned char *data, unsigned char data_length);


void MASTER_Send (void){
  Set_Address(10);
  Set_Command(3);
  Set_Register(0x01f3);
  Set_Counter(1);
  UART_Send_Buff(data, sizeof data);
  Send_CRC(CRC_Calc(data, sizeof data));
}

unsigned int CRC_Calc (unsigned char *data, unsigned char data_length){
  int i;
  unsigned int crc_val = 0xFFFF;
  while(data_length--){
    crc_val^=*data++;
    for(i = 0; i < 8; i++){
      if(crc_val & 0x0001){
        crc_val = (crc_val >> 1) ^ 0xA001;
      }else{
        crc_val = crc_val >> 1;
      }
    }
  }
  return crc_val;
}

void Send_CRC (uint16_t data){
  UART_Send(data);
  UART_Send(data >> 8);
}

void Set_Address (uint8_t value){
  data [0] = value;
}

void Set_Command (uint8_t value){
  data [1] = value;
}

void Set_Register (uint16_t value){
  data [2] = value >> 8;
  data [3] = value;
}

void Set_Counter (uint16_t value){
  data [4] = value >> 8;
  data [5] = value;
}

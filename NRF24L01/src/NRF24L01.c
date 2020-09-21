#include "SPI.h"
#include "NRF24L01.h"
#include "stm8s.h"

char Transmit = 1;

char PIPE0_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA0};
char PIPE1_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA1};
char PIPE2_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA2};
char PIPE3_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA3};
char PIPE4_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA4};
char PIPE5_ADDRES [5] = {0xAA, 0xAA, 0xAA, 0xAA, 0xA5};

char PIPE0_DATA [4];
char PIPE1_DATA [4];
char PIPE2_DATA [4];
char PIPE3_DATA [4];
char PIPE4_DATA [4];
char PIPE5_DATA [4];

void NRF_FLUSH_TX(void);
void NRF_FLUSH_RX (void);
char NRF_R_RX_PL_WID (void);

///////////////////////////////////////////////////////
char NRF_READ_REG (char reg);
void NRF_WRITE_REG (char reg, char data);
void NRF_READ_BUFF (char cmd, char *buff, char count);
void NRF_WRITE_BUFF (char cmd, char *buff, char count);
///////////////////////////////////////////////////////

void NRF_Config_Transmitter (void){
	NRF_WRITE_REG(CONFIG_REG, EN_CRC | PWR_UP);
	NRF_WRITE_REG(EN_RXADDR_REG, ERX_P0);
	NRF_WRITE_REG(SETUP_AW_REG, AW_5_BYTE);
	NRF_WRITE_REG(SETUP_RETR_REG, RETRASMIT_15 | WAIT_4000us);
	NRF_WRITE_REG(RF_CH_REG, 120);
	NRF_WRITE_BUFF(((RX_ADDR_P0_REG & 0x1F) | W_REGISTER), PIPE1_ADDRES, sizeof PIPE1_ADDRES);
	NRF_WRITE_BUFF(((TX_ADDR_REG & 0x1F) | W_REGISTER), PIPE1_ADDRES, sizeof PIPE1_ADDRES);
	NRF_WRITE_REG(DYNPD_REG, DPL_P0);
	NRF_WRITE_REG(FEATURE_REG, EN_DPL | EN_ACK_PAY);
}
///////////////////////////////////////////////////////

void NRF_Config_Receiver (void){
	NRF_WRITE_BUFF(((RX_ADDR_P1_REG & 0x1F) | W_REGISTER), PIPE1_ADDRES, sizeof PIPE1_ADDRES);	
	NRF_WRITE_REG(EN_AA_REG, ENAA_P1);
	NRF_WRITE_REG(EN_RXADDR_REG, ERX_P1);
	NRF_WRITE_REG(SETUP_AW_REG, AW_5_BYTE);
	NRF_WRITE_REG(RF_CH_REG, 120);
	NRF_WRITE_REG(DYNPD_REG, DPL_P1);
	NRF_WRITE_REG(FEATURE_REG, EN_DPL);
	NRF_WRITE_REG(CONFIG_REG, EN_CRC | PWR_UP | PRIM_RX);
	CE_HIGH;
}

char NRF_READ_REG (char reg){
	NSS_LOW;
	SPI_Send((reg & 0x1F) | R_REGISTER);
	uint8_t data = SPI_Send(NOP);
	NSS_HIGH;
	return data;
}

void NRF_WRITE_REG (char reg, char data){
	NSS_LOW;
	SPI_Send((reg & 0x1F) | W_REGISTER);
	SPI_Send(data);
	NSS_HIGH;
}

void NRF_READ_BUFF (char cmd, char *buff, char count){
	NSS_LOW;
	SPI_Send(cmd);
	while(count--){
		*(buff++) = SPI_Send(NOP);
	}
	NSS_HIGH;
}

void NRF_WRITE_BUFF (char cmd, char *buff, char count){
	NSS_LOW;
	SPI_Send(cmd);
	while(count--){
		SPI_Send(*(buff++));
	}
	NSS_HIGH;
}
///////////////////////////////////////////////////////
void NRF_SEND (char *buff, char count){
	if(Transmit == Enable){
		NSS_LOW;
		SPI_Send(W_TX_PAYLOAD);
		while(count--){
			SPI_Send(*(buff++));
		}
		NSS_HIGH;
		Transmit = Disable;
		CE_HIGH;
                CE_LOW;
		//TIM4->CR1 |= TIM_CR1_CEN;
		//while(TIM4->CR1 & TIM_CR1_CEN);		
	}
}

///////////////////////////////////////////////////////
void NRF_FLUSH_TX (void){
	NSS_LOW;
	SPI_Send(FLUSH_TX);
	SPI_Send(NOP);
	NSS_HIGH;
}

void NRF_FLUSH_RX (void){
	NSS_LOW;
	SPI_Send(FLUSH_RX);
	SPI_Send(NOP);
	NSS_HIGH;
}

void NRF_REUSE_TX_PL (void){
	NSS_LOW;
	SPI_Send(REUSE_TX_PL);
	SPI_Send(NOP);
	NSS_HIGH;	
}

char NRF_R_RX_PL_WID (void){
	NSS_LOW;
	SPI_Send(R_RX_PL_WID);
	uint8_t data = SPI_Send(NOP);
	NSS_HIGH;
	return data;
}

void Transmitter_IRQ (void){
	if(NRF_READ_REG(STATUS_REG) & TX_DS){
		Transmit = Enable;
		NRF_WRITE_REG(STATUS_REG, TX_DS);
	}else if(NRF_READ_REG(STATUS_REG) & MAX_RT){
		NRF_FLUSH_TX();
		NRF_WRITE_REG(STATUS_REG, MAX_RT);
		Transmit = Enable;
	}
}

void Receiver_IRQ (void){
	if(NRF_READ_REG(STATUS_REG) & RX_DR){
		if(NRF_READ_REG(STATUS_REG) & PIPE_1){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE1_DATA, sizeof PIPE1_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}else if(NRF_READ_REG(STATUS_REG) & PIPE_2){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE2_DATA, sizeof PIPE2_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}else if(NRF_READ_REG(STATUS_REG) & PIPE_3){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE3_DATA, sizeof PIPE3_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}else if(NRF_READ_REG(STATUS_REG) & PIPE_4){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE4_DATA, sizeof PIPE4_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}else if(NRF_READ_REG(STATUS_REG) & PIPE_5){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE5_DATA, sizeof PIPE5_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}else if((NRF_READ_REG(STATUS_REG) & 0x0E) == 0){
			NRF_READ_BUFF(R_RX_PAYLOAD, PIPE0_DATA, sizeof PIPE0_DATA);
			NRF_WRITE_REG(STATUS_REG, RX_DR);
		}
	}
}


#define CE_LOW  GPIOD->ODR &= ~0x04;  // CE_LOW
#define CE_HIGH GPIOD->ODR |= 0x04;   // CE_HIGH

/*All flags*/
#define		Enable 	0x01
#define		Disable	0x00
/*NRF24L01 all register and command*/

/*NRF24L01 Command*/
#define R_REGISTER					0x00	// Read register.
#define W_REGISTER					0x20	// Write register.
#define R_RX_PAYLOAD				0x61	// Read RX-payload (1-32 bytes).
#define W_TX_PAYLOAD				0xA0	// Write TX-payload (1-32 bytes).
#define FLUSH_TX						0xE1	// Flush TX FIFO.
#define FLUSH_RX						0xE2	// Flush RX FIFO.
#define REUSE_TX_PL					0xE3	// Reuse last transmitted payload.
#define R_RX_PL_WID					0x60	// Read RX payload width for the top.
#define W_ACK_PAYLOAD				0xA8	// Write payload to be transmitted togeder whit ACK packet (USED in RX mode).
#define W_TX_PAYLOAD_NOACK	0xB0	// Disables AUTOACK on this specific packet.
#define NOP									0xFF	// NOP Command.
////////////////////////////

/*NRF24L01 Global Register*/
#define CONFIG_REG			0x00
#define EN_AA_REG				0x01
#define EN_RXADDR_REG		0x02
#define SETUP_AW_REG		0x03
#define SETUP_RETR_REG	0x04
#define RF_CH_REG				0x05
#define RF_SETUP_REG		0x06
#define STATUS_REG			0x07
#define OBSERVE_TX_REG	0x08
#define RPD_REG					0x09
#define RX_ADDR_P0_REG	0x0A
#define RX_ADDR_P1_REG	0x0B
#define RX_ADDR_P2_REG	0x0C
#define RX_ADDR_P3_REG	0x0D
#define RX_ADDR_P4_REG	0x0E
#define RX_ADDR_P5_REG	0x0F
#define TX_ADDR_REG			0x10
#define	RX_PW_P0_REG		0x11
#define RX_PW_P1_REG		0x12
#define RX_PW_P2_REG		0x13
#define RX_PW_P3_REG		0x14
#define RX_PW_P4_REG		0x15
#define RX_PW_P5_REG		0x16
#define FIFO_STATUS_REG	0x17
#define DYNPD_REG				0x1C
#define FEATURE_REG			0x1D
////////////////////////////

/*NRF24L01 Config register*/
#define MASK_RX_DR			0x40
#define MASK_TX_DS			0x20
#define MASK_MAX_RT			0x10
#define EN_CRC					0x08
#define CRCO						0x04
#define PWR_UP					0x02
#define PRIM_RX					0x01
////////////////////////////

/*NRF24L01	EN_AA register*/
#define ENAA_P5					0x20
#define ENAA_P4					0x10
#define ENAA_P3					0x08
#define ENAA_P2					0x04
#define ENAA_P1					0x02
#define ENAA_P0					0x01
////////////////////////////

/*NRF24L01 EN_RXADDR register*/
#define ERX_P5					0x20
#define ERX_P4					0x10
#define ERX_P3					0x08
#define ERX_P2					0x04
#define ERX_P1					0x02
#define ERX_P0					0x01
///////////////////////////////

/*NRF24L01 SETUP_AW register*/
#define AW_5_BYTE				0x03
#define AW_4_BYTE				0x02
#define AW_3_BYTE				0x01
#define AW_Illegal			0x00
//////////////////////////////

/*NRF24L01 SETUP_RETR register*/
#define WAIT_250us			0x00
#define WAIT_500us			0x10
#define WAIT_750us			0x20
#define WAIT_1000us			0x30
#define WAIT_1250us			0x40
#define WAIT_1500us			0x50
#define WAIT_1750us			0x60
#define WAIT_2000us			0x70
#define WAIT_2250us			0x80
#define WAIT_2500us			0x90
#define WAIT_2750us			0xA0
#define WAIT_3000us			0xB0
#define WAIT_3250us			0xC0
#define WAIT_3500us			0xD0
#define WAIT_3750us			0xE0
#define WAIT_4000us			0xF0
#define RETRASMIT_DIS		0x00
#define RETRASMIT_1			0x01
#define RETRASMIT_2			0x02
#define RETRASMIT_3			0x03
#define RETRASMIT_4			0x04
#define RETRASMIT_5			0x05
#define RETRASMIT_6			0x06
#define RETRASMIT_7			0x07
#define RETRASMIT_8			0x08
#define RETRASMIT_9			0x09
#define RETRASMIT_10		0x0A
#define RETRASMIT_11		0x0B
#define RETRASMIT_12		0x0C
#define RETRASMIT_13		0x0D
#define RETRASMIT_14		0x0E
#define RETRASMIT_15		0x0F
////////////////////////////////

/*NRF24L01 RF_SETUP register*/
#define CONT_WAVE				0x80
#define RF_DR_LOW				0x20
#define PLL_LOCK				0x10
#define RF_DR_HIGH			0x08
#define RF_PWR_min18dbm	0x00
#define RF_PWR_min12dbm	0x02
#define RF_PWR_min6dbm	0x04
#define RF_PWR_0dbm			0x06
//////////////////////////////

/*NRF24L01 STATUS register*/
#define RX_DR						0x40
#define TX_DS						0x20
#define MAX_RT					0x10
#define PIPE_0
#define PIPE_1					0x02
#define PIPE_2					0x04
#define PIPE_3					0x06
#define PIPE_4					0x08
#define PIPE_5					0x0A
#define TX_FULL					0x01
////////////////////////////

/*NRF24L01 FIFO register*/
#define FIFO_TX_REUSE		0x40
#define FIFO_TX_FULL		0x20
#define FIFO_TX_EMPTY		0x10
#define FIFO_RX_FULL		0x02
#define FIFO_RX_EMPTY		0x01
//////////////////////////

/*NRF24L01 DYNPD register*/
#define DPL_P5					0x20
#define DPL_P4					0x10
#define DPL_P3					0x08
#define DPL_P2					0x04
#define DPL_P1					0x02
#define DPL_P0					0x01
///////////////////////////

/*NRF24L01 FEATURE register*/
#define EN_DPL					0x04
#define EN_ACK_PAY			0x02
#define EN_DYN_ACK			0x01
/////////////////////////////

/*All functions					*/
void NRF_Config_Transmitter (void);
void NRF_Config_Receiver (void);
void NRF_SEND (char *buff, char lenght);
void Transmitter_IRQ (void);
void Receiver_IRQ (void);
char NRF_READ_REG (char reg);
//////////////////////////

#define NSS_LOW         GPIOA->ODR &= ~0x08;
#define NSS_HIGH        GPIOA->ODR |= 0x08;

void SPI_Config (void);
char SPI_Send (char data);

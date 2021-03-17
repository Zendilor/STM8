void GPIO_Config (void);

/*ON segments*/
#define SEG_A_ON		(GPIOC->ODR |= 0x20)
#define SEG_B_ON		(GPIOB->ODR |= 0x20)
#define SEG_C_ON		(GPIOD->ODR |= 0x04)
#define SEG_D_ON		(GPIOD->ODR |= 0x10)
#define SEG_E_ON		(GPIOD->ODR |= 0x20)
#define SEG_F_ON		(GPIOC->ODR |= 0x10)
#define SEG_G_ON		(GPIOD->ODR |= 0x08)
#define SEG_DP_ON		(GPIOC->ODR |= 0x80)


/*OFF segments*/
#define SEG_A_OFF		(GPIOC->ODR &= ~0x20)
#define SEG_B_OFF		(GPIOB->ODR &= ~0x20)
#define SEG_C_OFF		(GPIOD->ODR &= ~0x04)
#define SEG_D_OFF		(GPIOD->ODR &= ~0x10)
#define SEG_E_OFF		(GPIOD->ODR &= ~0x20)
#define SEG_F_OFF		(GPIOC->ODR &= ~0x10)
#define SEG_G_OFF 	(GPIOD->ODR &= ~0x08)
#define SEG_DP_OFF	(GPIOC->ODR &= ~0x80)

/*ON digits*/
#define DIG_1_ON	(GPIOC->ODR &= ~0x40)
#define DIG_2_ON	(GPIOC->ODR &= ~0x08)
#define DIG_3_ON	(GPIOB->ODR &= ~0x10)

/*OFF digit*/
#define DIG_1_OFF	(GPIOC->ODR |= 0x40)
#define DIG_2_OFF	(GPIOC->ODR |= 0x08)
#define DIG_3_OFF	(GPIOB->ODR |= 0x10)

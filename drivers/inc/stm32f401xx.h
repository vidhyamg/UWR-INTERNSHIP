/*
 * stm32f401xx.h
 *
 *  Created on: Jun 11, 2026
 *      Author: deepu
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_
#define _VO  volatile
/*
 * Memory Base Address
 */

#define FLASH_BASEADDR  0x08000000U            /* Flash memory base address */
#define ROM_BASEADDR    0x1FFF0000U            /*System Memory base address*/
#define SRAM_BASEADDR   0x20000000U            /* SRAM base  address*/

/*
 * Peripheral bus addresses
 */

#define PERIPH_BASEADDR  0x40000000U
#define APB1_BASEADDR    PERIPH_BASEADDR
#define APB2_BASEADDR    0x40010000U
#define AHB1_BASEADDR    0x40020000U
#define AHB2_BASEADDR    0x50000000U

/*
 * AHB1 Peripheral Base Addresses
 */


#define GPIOA_BASEADDR    (AHB1_BASEADDR + 0x0000)
#define GPIOB_BASEADDR    (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR    (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR    (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR    (AHB1_BASEADDR + 0x1000)
#define GPIOH_BASEADDR    (AHB1_BASEADDR + 0x1C00)

#define CRC_BASEADDR      (AHB1_BASEADDR + 0x3000)
#define RCC_BASEADDR      (AHB1_BASEADDR + 0x3800)
#define FLASH_IF_BASEADDR (AHB1_BASEADDR + 0x3C00)
#define DMA1_BASEADDR      (AHB1_BASEADDR + 0x6000)
#define DMA2_BASEADDR      (AHB1_BASEADDR + 0x6400)

/*
 * AHB2 Peripheral Base Addresses
 */



#define USB_OTG_FS_BASEADDR      (AHB2_BASEADDR + 0x0000)

/*
 * APB1 Peripheral Base Addresses
 */

/*Timers*/
#define TIM2_BASEADDR      (APB1_BASEADDR + 0x0000)
#define TIM3_BASEADDR      (APB1_BASEADDR + 0x0400)
#define TIM4_BASEADDR      (APB1_BASEADDR + 0x0800)
#define TIM5_BASEADDR      (APB1_BASEADDR + 0x0C00)
/*SPI*/
#define SPI2_BASEADDR      (APB1_BASEADDR + 0x3800)
#define SPI3_BASEADDR      (APB1_BASEADDR + 0x3C00)

/* USART */
#define USART2_BASEADDR      (APB1_BASEADDR + 0x4400)

/*I2C*/
#define I2C1_BASEADDR      (APB1_BASEADDR + 0x5400)
#define I2C2_BASEADDR      (APB1_BASEADDR + 0x5800)
#define I2C3_BASEADDR      (APB1_BASEADDR + 0x5C00)

/*
 * APB2 Peripheral Base Addresses
 */

/* Timers */
#define TIM1_BASEADDR      (APB2_BASEADDR + 0x0000)
#define TIM8_BASEADDR      (APB2_BASEADDR + 0x0400)

/* USART */
#define USART1_BASEADDR    (APB2_BASEADDR + 0x1000)
#define USART6_BASEADDR    (APB2_BASEADDR + 0x1400)

/*ADC*/
#define ADC1_BASEADDR      (APB2_BASEADDR + 0x2000)

/* SPI */
#define SPI1_BASEADDR      (APB2_BASEADDR + 0x3000)
#define SPI4_BASEADDR      (APB2_BASEADDR + 0x3400)

/* System Configuration */
#define SYSCFG_BASEADDR    (APB2_BASEADDR + 0x3800)
#define EXTI_BASEADDR      (APB2_BASEADDR + 0x3C00)

/* Timers */
#define TIM9_BASEADDR      (APB2_BASEADDR + 0x4000)
#define TIM10_BASEADDR     (APB2_BASEADDR + 0x4400)
#define TIM11_BASEADDR     (APB2_BASEADDR + 0x4800)

/*
 * GPIO Peripheral Register Definition Structure
 */
typedef struct
{
	_VO uint32_t MODER;           /* Mode register,Offset: 0x00 */
	_VO uint32_t OTYPER;          /* Output type register,Offset: 0x04 */
	_VO uint32_t OSPEEDR;         /* Output speed register,Offset: 0x08*/
	_VO uint32_t PUPDR;           /*Pull-up/pull-down register, Offset: 0x0C */
	_VO uint32_t IDR;             /* Input data register,Offset: 0x10 */
	_VO uint32_t ODR;             /* Output data register,Offset: 0x14 */
	_VO uint32_t BSRR;            /* Bit set/reset register,Offset: 0x18 */
	_VO uint32_t LCKR;            /* Configuration lock register,Offset: 0x1C */
	_VO uint32_t AFR[2];          /* Alternate function registers,
                                 AFR[0] = AFRL (Offset: 0x20)
                                 AFR[1] = AFRH (Offset: 0x24) */
} GPIO_RegDef_t;


/*
 * RCC Peripheral Register Definition Structure
 */
typedef struct
{

	_VO  uint32_t CR;             /*Clock control register,Offset: 0x00 */
	_VO  uint32_t PLLCFGR;        /*PLL configuration register,Offset: 0x04 */
	_VO  uint32_t CFGR;          /*Clock configuration register,Offset: 0x08 */
	_VO  uint32_t CIR;           /*Clock interrupt register,Offset: 0x0C */
	_VO  uint32_t AHB1RSTR;      /*AHB1 peripheral reset register,Offset: 0x10 */
	_VO  uint32_t AHB2RSTR;      /* AHB2 peripheral reset register,Offset: 0x14 */
	uint32_t Reserved0[2];
	_VO  uint32_t APB1RSTR;      /*APB1 peripheral reset register,Offset: 0x20 */
	_VO  uint32_t APB2RSTR;      /*APB2 peripheral reset register,Offset: 0x24 */
	uint32_t Reserved1[2];
	_VO  uint32_t AHB1ENR;       /*AHB1 clock enable register,Offset: 0x30 */
	_VO  uint32_t AHB2ENR;       /*AHB2 clock enable register,Offset: 0x34 */
	uint32_t Reserved2[2];
    _VO  uint32_t APB1ENR;       /*APB1 clock enable register,ffset: 0x40 */
    _VO  uint32_t APB2ENR;       /*APB2 clock enable register,ffset: 0x44 */
    uint32_t Reserved3[2];
    _VO  uint32_t AHB1LPENR;     /*AHB1 clock enabled in low power mode register,offset: 0x50 */
    _VO  uint32_t AHB2LPENR;     /*AHB2 clock enabled in low power mode register,offset: 0x54 */
    uint32_t Reserved4[2];
    _VO  uint32_t APB1LPENR;     /*APB1 clock enabled in low power mode register,offset: 0x60 */
    _VO  uint32_t APB2LPENR;     /*APB2 clock enabled in low power mode register,offset: 0x64 */
    uint32_t Reserved5[2];
    _VO  uint32_t BDCR;          /*Backup domain control register,offset: 0x70 */
    _VO  uint32_t CSR;           /*Clock control  and status register,offset: 0x74 */
    uint32_t Reserved6[2];
    _VO  uint32_t SSCGR;         /*Spread spectrum Clock control generation register,offset: 0x80 */
    _VO  uint32_t PLLI2SCFGR;    /*PLLI2S configuration register,offset: 0x80 */

} RCC_RegDef_t;


/*
 * SPI Peripheral Register Definition Structure
 */
typedef struct
{
	_VO   uint32_t   CR1;      /*Control register 1,Offset: 0x00 */
	_VO   uint32_t   CR2;      /*Control register 2,Offset: 0x04 */
	_VO   uint32_t   SR;       /* Status register, Offset: 0x08 */
	_VO   uint32_t   DR;       /* Data register, Offset: 0x0C */
	_VO   uint32_t   CRCPR1;   /*CRC polynomial register,Offset: 0x10*/
	_VO   uint32_t   RXCRCR;   /*RX CRC register,Offset: 0x14 */
	_VO   uint32_t   TXCRCR;   /*TX CRC register,Offset: 0x18 */
	_VO   uint32_t   I2SCFGR;  /*I2S configuration,Offset: 0x1C */
	_VO   uint32_t   I2SPR;    /*I2S Prescaler,Offset: 0x20 */

} SPI_RegDef_t;;

/*
 *I2C Peripheral Register Definition Structure
 */

typedef struct
{
	_VO   uint32_t   CR1;       /* Control register 1,Offset: 0x00 */
	_VO   uint32_t   CR2;       /* Control register 2,Offset: 0x04 */
	_VO   uint32_t   OAR1;      /*Own address register 1,Offset: 0x08 */
	_VO   uint32_t   OAR2;      /*Own address register 2,Offset: 0x0C */
	_VO   uint32_t   DR;        /* Data register,Offset: 0x10 */
	_VO   uint32_t   SR1;       /* Status register1,Offset: 0x14 */
	_VO   uint32_t   SR2;       /* Status register2,Offset: 0x18 */
	_VO   uint32_t   CCR;       /*  Clock Control register,Offset: 0x1C */
	_VO   uint32_t   TRISE;     /*TRISE register, Offset: 0x20 */
	_VO   uint32_t   FLTR;      /*FLTR register,Offset: 0x24 */
} I2C_RegDef_t;

/*
 *USART Peripheral Register Definition Structure
 */

typedef struct
{
    _VO uint32_t SR;       /*Status register,Offset: 0x00 */
    _VO uint32_t DR;       /*Data register,Offset: 0x04 */
    _VO uint32_t BRR;      /* Baud rate register,Offset: 0x08 */
    _VO uint32_t CR1;      /*Control register 1,Offset: 0x0C */
    _VO uint32_t CR2;      /*Control register 2,Offset: 0x10 */
    _VO uint32_t CR3;      /*Control register 3,Offset: 0x14 */
    _VO uint32_t GTPR;     /*Guard time & prescaler reg,Offset: 0x18 */

}  USART_RegDef_t;

/*
 * EXTI register definition structure
*/

typedef struct
{
	_VO uint32_t EXTI_IMR;                   /*Interrupt mask register,offset: 0x00 */
    _VO uint32_t EXTI_EMR;                   /*Event mask register,offset: 0x04 */
	_VO uint32_t EXTI_RTSR;                   /*Rising trigger selection register,offset: 0x00 */
	_VO uint32_t EXTI_FTSR;                   /*Falling trigger selection register,offset: 0x00 */
	_VO uint32_t MEEXTI_SWIER;                /*Software interrupt event register,offset: 0x00 */
	_VO uint32_t EXTI_PR;                     /*Pending register,offset: 0x00 */

} EXTI_RegDef_t;



/*
 * SYSCFG Peripheral Register Definition Structure
 */
typedef struct
{
   _VO uint32_t MEMRMP;                   /*!< SYSCFG memory remap register,                  Address offset: 0x00 */
   _VO uint32_t PMC;                      /*!< SYSCFG peripheral mode configuration register, Address offset: 0x04 */
   _VO uint32_t EXTICR[4];                /*!< SYSCFG external interrupt configuration,       Address offset: 0x08-0x14 */
    uint32_t      RESERVED1[2];             /*!< Reserved,                                      Address offset: 0x18-0x1C */
   _VO uint32_t CMPCR;                    /*!< SYSCFG compensation cell control register,     Address offset: 0x20 */
    uint32_t      RESERVED2[2];             /*!< Reserved,                                      Address offset: 0x24-0x28 */
   _VO uint32_t CFGR;                     /*!< SYSCFG configuration register,                 Address offset: 0x2C */
} SYSCFG_RegDef_t;




	/*
	Peripheral Definitions,(Peripheral base addresses typecasted to xxx_RegDef_t)
	 */

	/* GPIO */

#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)

	/* RCC */

#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)

	/* SPI */

#define SPI1    ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3    ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4    ((SPI_RegDef_t*)SPI4_BASEADDR)



	/* I2C */
#define I2C1    ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2    ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3    ((I2C_RegDef_t*)I2C3_BASEADDR)

   /* USART */
#define USART1  ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  ((USART_RegDef_t*)USART2_BASEADDR)
#define USART6  ((USART_RegDef_t*)USART6_BASEADDR)

    /*EXTI */
#define EXTI         ((EXTI_RegDef_t*)EXTI_BASEADDR)

   /*SYSCONFIG*/
#define SYSCFG          ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
/*
 * Clock Enable Macros for GPIOx
 * GPIOx clocks are on AHB1 bus
 */

#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1 << 7))

/* SPI Clock Enable */
#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()     (RCC->APB2ENR |= (1 << 13))

/* I2C Clock Enable */
#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1 << 23))

/* USART Clock Enable */
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()                    (RCC->APB2ENR |= (1 << 14))


/*
 * Clock Disable Macros
*/

/* GPIO Clock Disable */
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1 << 7))


/* SPI Clock Disable */
#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()     (RCC->APB2ENR &= ~ (1 << 13))

/* I2C Clock Disable */
#define I2C1_PCLK_DI()     (RCC->APB1ENR &= ~ (1 << 21))
#define I2C2_PCLK_DI()     (RCC->APB1ENR &= ~ (1 << 22))
#define I2C3_PCLK_DI()     (RCC->APB1ENR &= ~ (1 << 23))

/* USART Clock Disable */
#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~ (1 << 4))
#define USART2_PCLK_DI()   (RCC->APB1ENR &= ~ (1 << 17))
#define USART6_PCLK_DI()   (RCC->APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI()                    (RCC->APB2ENR &= ~(1 << 14))

/**********************************
 * Peripheral Reset Macros
 **********************************/

/* GPIO Reset - using do-while(0) for safe macro usage */
/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()                   do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)


/*
 * Macros to reset SPIx peripherals
 */
#define SPI1_REG_RESET()                    do{ (RCC->APB2RSTR |= (1 << 12)); (RCC->APB2RSTR &= ~(1 << 12)); }while(0)
#define SPI2_REG_RESET()                    do{ (RCC->APB1RSTR |= (1 << 14)); (RCC->APB1RSTR &= ~(1 << 14)); }while(0)
#define SPI3_REG_RESET()                    do{ (RCC->APB1RSTR |= (1 << 15)); (RCC->APB1RSTR &= ~(1 << 15)); }while(0)
#define SPI4_REG_RESET()                    do{ (RCC->APB2RSTR |= (1 << 13)); (RCC->APB2RSTR &= ~(1 << 13)); }while(0)


/*
 * Macros to reset I2Cx peripherals
 */
#define I2C1_REG_RESET()                    do{ (RCC->APB1RSTR |= (1 << 21)); (RCC->APB1RSTR &= ~(1 << 21)); }while(0)
#define I2C2_REG_RESET()                    do{ (RCC->APB1RSTR |= (1 << 22)); (RCC->APB1RSTR &= ~(1 << 22)); }while(0)
#define I2C3_REG_RESET()                    do{ (RCC->APB1RSTR |= (1 << 23)); (RCC->APB1RSTR &= ~(1 << 23)); }while(0)


/*
 * Macros to reset USARTx peripherals
 */
#define USART1_REG_RESET()                  do{ (RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 << 4)); }while(0)
#define USART2_REG_RESET()                  do{ (RCC->APB1RSTR |= (1 << 17)); (RCC->APB1RSTR &= ~(1 << 17)); }while(0)
#define USART3_REG_RESET()                  do{ (RCC->APB1RSTR |= (1 << 18)); (RCC->APB1RSTR &= ~(1 << 18)); }while(0)
#define UART4_REG_RESET()                   do{ (RCC->APB1RSTR |= (1 << 19)); (RCC->APB1RSTR &= ~(1 << 19)); }while(0)
#define UART5_REG_RESET()                   do{ (RCC->APB1RSTR |= (1 << 20)); (RCC->APB1RSTR &= ~(1 << 20)); }while(0)
#define USART6_REG_RESET()                  do{ (RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 << 5)); }while(0)






/*General purpose macros
 * */

#define ENABLE   1
#define DISABLE  0
#define SET      ENABLE
#define RESET    DISABLE
#define GPIO_PIN_SET  SET



















#endif /* INC_STM32F401XX_H_ */

/*
 * stm32f401xe_spi.h
 *
 *  Created on: Sep 2, 2026
 *      Author: Vidhya
 */

#ifndef INC_STM32F401XE_SPI_H_
#define INC_STM32F401XE_SPI_H_


#include "stm32f401xe.h"
/*
 * @brief Configuration structure for SPI
 * @details configuration settings for the SPI peripheral, including clock polarity, clock phase, device mode, bus configuration, data frame format, and software slave management.
 */
typedef struct
{
	uint8_t SPI_CPOL;          /* clk polarity*/
	uint8_t SPI_CPHA;          /*Clk phase*/
	uint8_t SPI_DeviceMode;   /* MASTER OR SLAVE*/
	uint8_t SPI_SclkSpeed;     /* SET PRESCALAR*/
	uint8_t SPI_BusConfig;    /* FULL DUPLEX OR HALF DUPLEX OR SIMPLEX*/
	uint8_t SPI_DFF;     /* 8 BIT OR 16 BIT DATA*/
	uint8_t SPI_SSM;           /* SOFTWARE SLAVE MANAGEMENT */


}SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 * @details This structure is used to manage the SPI peripheral, including the base address of the SPI peripheral,
 * configuration settings, and pointers to transmit and receive buffers for interrupt-based communication.
 */
typedef struct
{
    SPI_RegDef_t  *pSPIx;       // Pointer to SPI peripheral
    SPI_Config_t  SPIConfig;   // Configuration settings

    // For interrupt-based communication
    uint8_t       *pTxBuffer;   // TX buffer pointer
    uint8_t       *pRxBuffer;   // RX buffer pointer
    uint32_t      TxLen;        // TX length
    uint32_t      RxLen;        // RX length
    uint8_t       TxState;      // TX state
    uint8_t       RxState;      // RX state
} SPI_Handle_t;


/*
 *  @brief SPI Macros
 */


/*
 * SPI_DeviceMode
 * @brief SPI device mode definitions
 */
#define SPI_DEVICE_MODE_MASTER    1       //< Master mode
#define SPI_DEVICE_MODE_SLAVE     0       //< Slave mode


/*
 * @SPI_BusConfig
 * @brief SPI bus configuration definitions
 */
#define SPI_BUS_CONFIG_FD                1          //< Full-duplex mode
#define SPI_BUS_CONFIG_HD                2          //< Half-duplex mode
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY    3         //< Simplex receive-only mode

/*
 * @SPI_SclkSpeed
 * @brief SPI clock speed definitions
 */
#define SPI_SCLK_SPEED_DIV2             	0             //< Clock speed divided by 2
#define SPI_SCLK_SPEED_DIV4             	1             //< Clock speed divided by 4
#define SPI_SCLK_SPEED_DIV8             	2             //< Clock speed divided by 8
#define SPI_SCLK_SPEED_DIV16             	3             //< Clock speed divided by 16
#define SPI_SCLK_SPEED_DIV32             	4             //< Clock speed divided by 32
#define SPI_SCLK_SPEED_DIV64             	5             //< Clock speed divided by 64
#define SPI_SCLK_SPEED_DIV128             	6             //< Clock speed divided by 128
#define SPI_SCLK_SPEED_DIV256             	7

/*
 * @SPI_DFF
 * @brief SPI data frame format definitions
 */
#define SPI_DFF_8BITS 	0                                //< 8-bit data frame format
#define SPI_DFF_16BITS  1                                //< 16-bit data frame format

/*
 * @CPOL
 * @brief SPI clock polarity definitions
 */
#define SPI_CPOL_HIGH 1                                   //< Clock polarity high
#define SPI_CPOL_LOW 0                                   //< Clock polarity low

/*
 * @CPHA
    * @brief SPI clock phase definitions
 */
#define SPI_CPHA_HIGH 1                                //< Clock phase high
#define SPI_CPHA_LOW 0                                //< Clock phase low

/*
 * @SPI_SSM
    * @brief SPI software slave management definitions
 */
#define SPI_SSM_EN     1                                //< Software slave management enabled
#define SPI_SSM_DI     0                                //< Software slave management disabled

/*
 * SPI related status flags definitions
 */
#define SPI_TXE_FLAG    ( 1 << SPI_SR_TXE)             //< Transmit buffer empty flag
#define SPI_RXNE_FLAG   ( 1 << SPI_SR_RXNE)            //< Receive buffer not empty flag
#define SPI_BUSY_FLAG   ( 1 << SPI_SR_BSY)             //< SPI busy flag


#define SPI_STATE_BUSY    0                            //SPI is busy in communication
#define SPI_STATE_READY   1                           //SPI is ready for communication

#define SPI_PRESCALAR_2     0                        //prescalar value for SPI clock speed
#define SPI_PRESCALAR_4     1
#define SPI_PRESCALAR_8     2
#define SPI_PRESCALAR_16    3
#define SPI_PRESCALAR_32    4
#define SPI_PRESCALAR_64    5
#define SPI_PRESCALAR_128   6
#define SPI_PRESCALAR_256   7


/*
 * APIs for SPI
 *
 */

/*
 * Peripheral Clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);


/*
 * Data Send and Receive (Blocking/Polling)
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/*
 * Other Peripheral Control APIs
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx , uint32_t FlagName);
void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx);



#endif /* INC_STM32F401XE_SPI_H_ */

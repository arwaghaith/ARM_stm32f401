/* BEGIN: ed8c6549bwf9 */
/* RCC Base Address*/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***************************************************************************************************************************/
                                           /* RCC Base Address*/
/***************************************************************************************************************************/                                          
#define RCC_BASE_ADDRESS 0x40023800

/***************************************************************************************************************************/
                                           /* RCC Registers addresses*/
/***************************************************************************************************************************/

#define RCC_CR          (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x00))    /* RCC clock control register */
#define RCC_PLLCFGR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x04))    /* RCC PLL configuration register */
#define RCC_CFGR        (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x08))    /* RCC clock configuration register */
#define RCC_CIR         (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x0C))    /* RCC clock interrupt register */
#define RCC_AHB1RSTR    (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x10))    /* RCC AHB1 peripheral reset register */
#define RCC_AHB2RSTR    (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x14))    /* RCC AHB2 peripheral reset register */
#define RCC_APB1RSTR    (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x20))    /* RCC APB1 peripheral reset register */
#define RCC_APB2RSTR    (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x24))    /* RCC APB2 peripheral reset register */
#define RCC_AHB1ENR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x30))    /* RCC AHB1 peripheral clock enable register */
#define RCC_AHB2ENR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x34))    /* RCC AHB2 peripheral clock enable register */
#define RCC_AHB3ENR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x38))    /* RCC AHB3 peripheral clock enable register */
#define RCC_APB1ENR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x40))    /* RCC APB1 peripheral clock enable register */
#define RCC_APB2ENR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x44))    /* RCC APB2 peripheral clock enable register */
#define RCC_AHB1LPENR   (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x50))    /* RCC AHB1 peripheral clock enable in low power mode register */
#define RCC_AHB2LPENR   (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x54))    /* RCC AHB2 peripheral clock enable in low power mode register */
#define RCC_AHB3LPENR   (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x58))    /* RCC AHB3 peripheral clock enable in low power mode register */
#define RCC_APB1LPENR   (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x60))    /* RCC APB1 peripheral clock enable in low power mode register */
#define RCC_APB2LPENR   (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x64))    /* RCC APB2 peripheral clock enable in low power mode register */
#define RCC_BDCR        (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x70))    /* RCC Backup domain control register */
#define RCC_CSR         (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x74))    /* RCC clock control & status register */
#define RCC_SSCGR       (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x80))    /* RCC spread spectrum clock generation register */
#define RCC_PLLI2SCFGR  (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x84))    /* RCC PLLI2S configuration register */
#define RCC_DCKCFGR     (*(volatile uint32_t*)(RCC_BASE_ADDRESS + 0x8C))    /* RCC Dedicated Clock Configuration Register */
/***************************************************************************************************************************/


/****************************************************************************************************************************/
                                           /*Register Masks*/
/****************************************************************************************************************************/

/*Selecting System Clock Mask*/
#define RCC_CFGR_SW_MASK 0x3

/*Selecting System Clock Status Mask*/
#define RCC_CFGR_SWS_MASK 0xC

/*Selecting PLL Source Mask*/
# define PLL_M_MASK 0x3F
# define PLL_N_MASK 0x7FC0
# define PLL_P_MASK 0x30000
# define PLL_SRC_MASK 0x400000
# define PLL_Q_MASK 0xF000000

/*RCC_PLLCFGR_MASK*/

#define HSI_SW_MASK 0x0
#define HSE_SW_MASK 0x1
#define PLL_SW_MASK 0x2

/*RCC_CFGR_PRESCALAR_MASK*/

#define RCC_HPRE_MASK 0xF0
#define RCC_PPRE1_MASK 0x1C00
#define RCC_PPRE2_MASK 0xE000





/****************************************************************************************************************************/
                                           /*Register shifts*/
/****************************************************************************************************************************/                                           


/*Selecting prescalar shift*/

#define RCC_HPRE_SHIFT 4
#define RCC_PPRE1_SHIFT 10
#define RCC_PPRE2_SHIFT 13

/*configuring the PLL shift*/

#define RCC_PLLCFGR_PLLM_SHIFT 0
#define RCC_PLLCFGR_PLLN_SHIFT 6
#define RCC_PLLCFGR_PLLP_SHIFT 16
#define RCC_PLLCFGR_PLLSRC_SHIFT 22
#define RCC_PLLCFGR_PLLQ_SHIFT 24
/****************************************************************************************************************************/


/* RCC_CR Register Bits*/


#define RCC_CR_HSION    0
#define RCC_CR_HSIRDY   1
#define RCC_CR_HSITRIM  3
#define RCC_CR_HSICAL   8
#define RCC_CR_HSEON    16
#define RCC_CR_HSERDY   17
#define RCC_CR_HSEBYP   18
#define RCC_CR_CSSON    19
#define RCC_CR_PLLON    24
#define RCC_CR_PLLRDY   25
#define RCC_CR_PLLI2SON 26
#define RCC_CR_PLLI2SRDY 27
#define RCC_CR_PLLSAION 28
#define RCC_CR_PLLSAIRDY 29

/* RCC_PLLCFGR Register Bits*/
#define RCC_PLLCFGR_PLLM 0
#define RCC_PLLCFGR_PLLN 6
#define RCC_PLLCFGR_PLLP 16
#define RCC_PLLCFGR_PLLSRC 22
#define RCC_PLLCFGR_PLLQ 24
#define RCC_PLLCFGR_PLLR 28

/* RCC_CFGR Register Bits*/
#define RCC_CFGR_SW 0
#define RCC_CFGR_SWS 2
#define RCC_CFGR_HPRE 4
#define RCC_CFGR_PPRE1 10
#define RCC_CFGR_PPRE2 13
#define RCC_CFGR_RTCPRE 16
#define RCC_CFGR_MCO1 21
#define RCC_CFGR_I2SSRC 23
#define RCC_CFGR_MCO1PRE 24
#define RCC_CFGR_MCO2PRE 27
#define RCC_CFGR_MCO2 30

/* RCC_CFGR_MC02PRE Bits*/
#define RCC_CFGR_SW0 0
#define RCC_CFGR_SW1 1
#define RCC_CFGR_SW2 2




/* RCC_CIR Register Bits*/
#define RCC_CIR_LSIRDYF 0
#define RCC_CIR_LSERDYF 1
#define RCC_CIR_HSIRDYF 2
#define RCC_CIR_HSERDYF 3
#define RCC_CIR_PLLRDYF 4
#define RCC_CIR_PLLI2SRDYF 5
#define RCC_CIR_PLLSAIRDYF 6
#define RCC_CIR_CSSF 7
#define RCC_CIR_LSIRDYIE 8
#define RCC_CIR_LSERDYIE 9
#define RCC_CIR_HSIRDYIE 10
#define RCC_CIR_HSERDYIE 11
#define RCC_CIR_PLLRDYIE 12
#define RCC_CIR_PLLI2SRDYIE 13
#define RCC_CIR_PLLSAIRDYIE 14
#define RCC_CIR_LSIRDYC 16
#define RCC_CIR_LSERDYC 17
#define RCC_CIR_HSIRDYC 18
#define RCC_CIR_HSERDYC 19
#define RCC_CIR_PLLRDYC 20
#define RCC_CIR_PLLI2SRDYC 21
#define RCC_CIR_PLLSAIRDYC 22
#define RCC_CIR_CSSC 23

/**************************************************************************************/

/**********************************************************************************/
/*RCC_AHB1 peripheral register*/
/*clock reset register */
/*********************************************************************************/
#define DMA2RST 22
#define DMA1RST 21
#define CRCRST 12
#define GPIOHRST 7
#define GPIOERST 4
#define GPIODRST 3
#define GPIOCRST 2
#define GPIOBRST 1

/*****************************************************************************************/

/*RCC_AHB2 peripheral register*/
/*clock reset register */
#define OTGFSRST 7

/*****************************************************************************************/

/*RCC_APB1 peripheral register*/
/*clock reset register */
#define PWRRST 28
#define I2C3RST 23
#define I2C2RST 22
#define I2C1RST 21
#define USART3RST 18
#define SPI3RST 15
#define SPI2RST 14
#define WWDGRST 11
#define TIM5RST 3
#define TIM4RST 2
#define TIM3RST 1
#define TIM2RST 0
/*****************************************************************************************/

/*RCC_APB2 peripheral register*/
    /*clock reset register */
#define TIM11RST 18
#define TIM10RST 17
#define TIM9RST 16
#define SYSCFGRST 14
#define SPI5RST 20
#define SPI4RST 15
#define SPI1RST 12
#define SDIORST 11
#define ADC1RST 8
#define USART6RST 5
#define USART1RST 4
#define TIM8RST 1
#define TIM1RST 0
/*****************************************************************************************/

/*RCC_AHB1 peripheral register*/

/*clock enable register */
#define DMA2EN 22
#define DMA1EN 21
#define CRCEN 12
#define GPIOHEN 7
#define GPIOEEN 4
#define GPIODEN 3
#define GPIOCEN 2
#define GPIOBEN 1
#define GPIOAEN 0
/*****************************************************************************************/

/*RCC_AHB2 peripheral register*/
/*clock enable register */
#define OTGFSEN 7
/*****************************************************************************************/

/*RCC_APB1 peripheral register*/
/*clock enable register */
#define PWREN 28
#define I2C3EN 23
#define I2C2EN 22
#define I2C1EN 21
#define USART3EN 18
#define SPI3EN 15
#define SPI2EN 14
#define WWDGEN 11
#define TIM5EN 3
#define TIM4EN 2
#define TIM3EN 1
#define TIM2EN 0
/*****************************************************************************************/

/*RCC_APB2 peripheral register*/
/*clock enable register */
#define TIM11EN 18
#define TIM10EN 17
#define TIM9EN 16
#define SYSCFGEN 14
#define SPI4EN 13
#define SPI1EN 12
#define SDIOEN 11
#define ADC1EN 8
#define USART6EN 5
#define USART1EN 4
#define TIM8EN 1
#define TIM1EN 0
/*****************************************************************************************/

/*RCC_AHB1 peripheral register*/

/*clock low power enable register */

#define DMA2LPEN 22
#define DMA1LPEN 21
#define SRAM2LPEN 17
#define SRAM1LPEN 16
#define FLITFLPEN 15
#define CRCLPEN 12
#define GPIOHLPEN 7
#define GPIOELPEN 4
#define GPIODLPEN 3
#define GPIOCLPEN 2
#define GPIOBLPEN 1
#define GPIOALPEN 0
/*****************************************************************************************/

/*RCC_AHB2 peripheral register*/

/*clock low power enable register */
#define OTGFSLPEN 7
/*****************************************************************************************/

/*RCC_APB1 peripheral register*/

/*clock low power enable register */
#define PWRLPEN 28
#define I2C3LPEN 23
#define I2C2LPEN 22
#define I2C1LPEN 21
#define USART3LPEN 18
#define SPI3LPEN 15
#define SPI2LPEN 14
#define WWDGLPEN 11
#define TIM5LPEN 3
#define TIM4LPEN 2
#define TIM3LPEN 1
#define TIM2LPEN 0
/*****************************************************************************************/

/*RCC_APB2 peripheral register*/
/*clock low power enable register */

#define TIM11LPEN 18
#define TIM10LPEN 17
#define TIM9LPEN 16
#define SYSCFGLPEN 14
#define SPI5LPEN 20
#define SPI4LPEN 13
#define SPI1LPEN 12
#define SDIOLPEN 11
#define ADC1LPEN 8
#define USART6LPEN 5
#define USART1LPEN 4
#define TIM8LPEN 1
#define TIM1LPEN 0
/*****************************************************************************************/

#define RCC_PLLCFGR_RESET_VALUE 0x24003010

#endif









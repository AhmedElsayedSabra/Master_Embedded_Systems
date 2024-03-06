
#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//******************************************************************
// Include Header
//******************************************************************
#include "Platform_Type.h"
//******************************************************************
// Base Addresses For Memory
//******************************************************************
#define FLASH_MEMORY_Base							0x80000000UL
#define SYSTEM_MEMORY_Base							0x1ffff800UL
#define SRAM_MEMORY_Base							0x20000000UL
#define Peripherals_Base							0x40000000UL
#define CortexM3_Internal_Peripherals_Base			0xE0000000UL
//******************************************************************
// NVIC registers
//******************************************************************
#define NVIC_BASE						0xE000E100
#define NVIC_ISER0						*(vuint32_t *)(NVIC_BASE + 0x000)
#define NVIC_ISER1						*(vuint32_t *)(NVIC_BASE + 0x004)
#define NVIC_ISER2						*(vuint32_t *)(NVIC_BASE + 0x008)
#define NVIC_ICER0						*(vuint32_t *)(NVIC_BASE + 0x080)
#define NVIC_ICER1						*(vuint32_t *)(NVIC_BASE + 0x084)
#define NVIC_ICER2						*(vuint32_t *)(NVIC_BASE + 0x088)
//****************************************************************
// Base Addresses For peripherals Register In AHB
//****************************************************************
#define SDIO_Base								0x40018000UL
#define DMA1_Base								0x40020000UL
#define DMA2_Base								0x40020400UL
#define RCC_Base								0x40021000UL
#define FLASH_MEMORY_INTERFACE_Base				0x40022000UL
#define CRC_Base								0x40023000UL
#define ETHERNET_Base							0x40028000UL
#define USB_OTG_FS_Base							0x50000000UL
#define FSMC_Base								0xA0000000UL
//***********************************************************
// Base Addresses For peropherals Register In APB2
//***********************************************************
#define AFIO_Base								0x40010000UL
#define EXTI_Base								0x40010400UL
#define GPIOA_Base								0x40010800UL	// Fully Includded in LQFP48
#define GPIOB_Base								0x40010C00UL	// Fully Includded in LQFP48
#define GPIOC_Base								0x40011000UL	// Patial Includded in LQFP48
#define GPIOD_Base								0x40011400UL	// Patial Includded in LQFP48
#define GPIOE_Base								0x40011800UL
#define GPIOF_Base								0x40011C00UL
#define GPIOG_Base								0x40012000UL
#define ADC1_Base								0x40012400UL
#define ADC2_Base								0x40012800UL
#define TIM1_Base								0x40012C00UL
#define SPI1_Base								0x40013000UL
#define TIM8_Base								0x40013400UL
#define USART1_Base								0x40013800UL
#define ADC3_Base								0x40013C00UL
#define TIM9_Base								0x40014C00UL
#define TIM10_Base								0x40015000UL
#define TIM11_Base								0x40015400UL

//***********************************************************
// 						Generic Macros
//***********************************************************
// 						  EXTI- IVT
//***********************************************************
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40
//******************************************************************
//					 NVIC Enable
//******************************************************************
#define NVIC_IRQ6_EXTI0_ENABLE					(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE					(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE					(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE					(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE					(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_ENABLE				(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_ENABLE				(NVIC_ISER1 |= (1<<8)) //(32-63) ISER[1] 40-32 = 8
//******************************************************************
//					 NVIC Disable
//******************************************************************
#define NVIC_IRQ6_EXTI0_DISABLE					(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE					(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE					(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE					(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE				(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_DISABLE				(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_DISABLE			(NVIC_ICER1 |= (1<<8)) //(32-63)ICER[1] 40-32 = 8
//***********************************************************
// 					Peripherals Register
//***********************************************************
typedef struct
{
	vuint32_t CR        ;
	vuint32_t CFGR      ;
	vuint32_t CIR       ;
	vuint32_t APB2RSTR  ;
	vuint32_t APB1RSTR  ;
	vuint32_t AHBENR    ;
	vuint32_t APB2ENR   ;
	vuint32_t APB1ENR   ;
	vuint32_t BDCR      ;
	vuint32_t CSR       ;
}RCC_TypeDef;
typedef struct
{
	vuint32_t IMR   ;
	vuint32_t EMR   ;
	vuint32_t RTSR  ;
	vuint32_t FTSR  ;
	vuint32_t SWIER ;
	vuint32_t PR    ;
}EXTI_TypeDef;

typedef struct
{
	vuint32_t CRL   ;
	vuint32_t CRH  ;
	vuint32_t IDR   ;
	vuint32_t ODR   ;
	vuint32_t BSRR  ;
	vuint32_t BRR  ;
	vuint32_t LCKR  ;
}GPIO_TypeDef;

typedef struct
{
	vuint32_t CR1  ;
	vuint32_t CR2   ;
	vuint32_t SMCR  ;
	vuint32_t DIER   ;
	vuint32_t SR   ;
	vuint32_t EGR   ;
	vuint32_t CCMR1 ;
	vuint32_t CCMR2  ;
	vuint32_t CCER ;
	vuint32_t CNT   ;
	vuint32_t PSC    ;
}TIM_TypeDef;

typedef struct
{
	vuint32_t CR1     ;
	vuint32_t CR2     ;
	vuint32_t SR      ;
	vuint32_t DR      ;
	vuint32_t CRCPR   ;
	vuint32_t RXCRCR  ;
	vuint32_t TXCRCR  ;
	vuint32_t I2SCFGR ;
	vuint32_t I2SPR   ;
}SPI_TypeDef;

typedef struct
{
	vuint32_t SR   ;
	vuint32_t DR   ;
	vuint32_t BRR  ;
	vuint32_t CR1  ;
	vuint32_t CR2  ;
	vuint32_t CR3  ;
	vuint32_t GTPR ;
}USART_TypeDef;

typedef struct
{
	vuint32_t EVCR        ;
	vuint32_t MAPR        ;
	vuint32_t EXTICR[4]   ;
	vuint32_t RESERVED0	  ;
	vuint32_t MAPR2	      ;
}AFIO_TypeDef;
typedef struct
{
	vuint32_t SR    ;
	vuint32_t CR1   ;
	vuint32_t CR2   ;
	vuint32_t SMPR1 ;
	vuint32_t SMPR2 ;
	vuint32_t JOFR1 ;
	vuint32_t JOFR2 ;
	vuint32_t JOFR3 ;
	vuint32_t JOFR4 ;
	vuint32_t HTR   ;
	vuint32_t LTR   ;
	vuint32_t SQR1  ;
}ADC_TypeDef;
//*************************************
// Peripherals Instant
//*************************************
#define GPIOA	((GPIO_TypeDef *)(GPIOA_Base))
#define GPIOB	((GPIO_TypeDef *)(GPIOB_Base))
#define GPIOC	((GPIO_TypeDef *)(GPIOC_Base))
#define GPIOD	((GPIO_TypeDef *)(GPIOD_Base))
#define GPIOE	((GPIO_TypeDef *)(GPIOE_Base))
#define RCC 	((RCC_TypeDef *)(RCC_Base))
#define AFIO	((AFIO_TypeDef *)(AFIO_Base))
#define USART1 	((USART_TypeDef *)(USART1_Base))
#define SPI1    ((SPI_TypeDef *)(SPI1_Base))
#define TIM1 	((TIM_TypeDef *)(TIM1_Base))
#define EXTI	((EXTI_TypeDef *)(EXTI_Base))
#define ADC1 	((ADC_TypeDef *)(ADC1_Base))
#define ADC2    ((ADC_TypeDef *)(ADC2_Base))
//*************************************
// Clock Enable Macros
//*************************************
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1<<0)
#define RCC_ADC1_CLK_EN()	(RCC->APB2ENR |= 1<<9)
#define RCC_ADC2_CLK_EN()	(RCC->APB2ENR |= 1<<10)
#define RCC_TIM1_CLK_EN()	(RCC->APB2ENR |= 1<<11)
#define RCC_SPI1_CLK_EN()	(RCC->APB2ENR |= 1<<12)
#define RCC_USART1_CLK_EN()	(RCC->APB2ENR |= 1<<14)
//*************************************
// Clock Disable Macros
//*************************************
#define RCC_GPIOA_CLK_Dis()	 (RCC->APB2ENR &=~(1<<2))
#define RCC_GPIOB_CLK_Dis()	 (RCC->APB2ENR &=~(1<<3))
#define RCC_GPIOC_CLK_Dis()	 (RCC->APB2ENR &=~(1<<4))
#define RCC_GPIOD_CLK_Dis()	 (RCC->APB2ENR &=~(1<<5))
#define RCC_GPIOE_CLK_Dis()	 (RCC->APB2ENR &=~(1<<6))
#define RCC_AFIO_CLK_Dis()	 (RCC->APB2ENR &=~(1<<0))
#define RCC_ADC1_CLK_Dis()	 (RCC->APB2ENR &=~(1<<9))
#define RCC_ADC2_CLK_Dis()	 (RCC->APB2ENR &=~(1<<10))
#define RCC_TIM1_CLK_Dis()	 (RCC->APB2ENR &=~(1<<11))
#define RCC_SPI1_CLK_Dis()	 (RCC->APB2ENR &=~(1<<12))
#define RCC_USART1_CLK_Dis() (RCC->APB2ENR &=~(1<<14))
#endif /* INC_STM32F103X6_H_ */

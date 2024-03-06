#include "Stm32_F103c6_GPIO_Driver.h"
#include "Utilites.h"
uint8_t MCAL_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0 : return 0   ; break ;
	case GPIO_PIN_1 : return 4   ; break ;
	case GPIO_PIN_2 : return 8   ; break ;
	case GPIO_PIN_3 : return 12  ; break ;
	case GPIO_PIN_4 : return 16  ; break ;
	case GPIO_PIN_5 : return 20  ; break ;
	case GPIO_PIN_6 : return 24  ; break ;
	case GPIO_PIN_7 : return 28  ; break ;
	case GPIO_PIN_8 : return 0   ; break ;
	case GPIO_PIN_9 : return 4   ; break ;
	case GPIO_PIN_10 :return 8   ; break ;
	case GPIO_PIN_11 : return 12 ; break ;
	case GPIO_PIN_12 : return 16 ; break ;
	case GPIO_PIN_13 : return 20 ; break ;
	case GPIO_PIN_14 : return 24 ; break ;
	case GPIO_PIN_15 : return 28 ; break ;
	}
	return 0 ;
}
void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx ,GPIO_PinConfig_TypeDef* PinConfig)
{
	// CRL Register Configure the pin from 0 to 7 && CRH Register Configure the pin from 8 to 15
	vuint32_t *ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	// CNF[10] MODE [00 ]
	(*ConfigRegister) &=~(0b1111 << MCAL_CRLH_Position(PinConfig->GPIO_PinNumber)) ;
	uint8_t PIN_Config = 0 ;
	if (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP)
	{
		PIN_Config |=((((PinConfig->GPIO_MODE - 4) << 2 ) | (PinConfig->GPIO_OUTPUT_SPEED)) & 0x0f);
	}
	else
	{
		if (PinConfig->GPIO_MODE == GPIO_MODE_Analog || PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)
		{
			PIN_Config |=(((PinConfig->GPIO_MODE << 2 ) | 0x0) & 0x0f);
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{
			PIN_Config |=(((GPIO_MODE_INPUT_FLO << 2 ) | 0x0) & 0x0f);
		}
		else
		{
			PIN_Config |=(((GPIO_MODE_INPUT_PU << 2 ) | 0x0) & 0x0f);
			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;
			else
				GPIOx->ODR &=~ (PinConfig->GPIO_PinNumber) ;
		}
	}
	(*ConfigRegister) |= PIN_Config<<MCAL_CRLH_Position(PinConfig->GPIO_PinNumber);
}
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx , uint8_t PinNumber)
{
	GPIOx->BRR = 0x00000000;
	GPIOx->BSRR =0x00000000 ;
	GPIOx->CRH = 0x44444444;
	GPIOx->CRL = 0x44444444 ;
	// GPIOx->IDR = (Read Only) ;
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR = 0x00000000;
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= 1<<2 ;
		RCC->APB2RSTR &=~ (1<<2) ;
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= 1<<3   ;
		RCC->APB2RSTR &=~ (1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= 1<<4   ;
		RCC->APB2RSTR &=~ (1<<4);
	}else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= 1<<5   ;
		RCC->APB2RSTR &=~ (1<<5);
	}else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= 1<<6   ;
		RCC->APB2RSTR &=~ (1<<6);
	}
}
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	uint8_t Pin_Status ; //Set Based On @ref GPIO_Pin_Status
	if ((GPIOx->IDR & PinNumber) != GPIO_PIN_LOW)
		Pin_Status = GPIO_PIN_HIGH;
	else
		Pin_Status = GPIO_PIN_LOW;
	return Pin_Status ;
}
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	uint16_t Port_Value ;
	Port_Value = (uint16_t) GPIOx->IDR ;
	return  Port_Value;
}
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t Value)
{
	if (Value == GPIO_PIN_HIGH)
		GPIOx->ODR |= PinNumber;   // GPIOx->BSRR =(uint32_t)PinNumber
	else
		GPIOx->ODR &=~ PinNumber;  // GPIOx->BRR  = (uint32_t)PinNumber
}
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx ,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value ;
}

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}
void MCAL_GPIO_TooglePort(GPIO_TypeDef* GPIOx)
{
	for (int i = 0 ;i <= 15 ; i++ )
		TOGGLE_BIT(GPIOx->ODR,i);
}
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx ,uint16_t PinNumber)
{
	uint32_t Temp = 1<<16 ;
	Temp |=PinNumber ;
	GPIOx->LCKR = Temp ;
	GPIOx->LCKR = PinNumber ;
	Temp = GPIOx->LCKR ;
	if ((uint32_t)GPIOx->LCKR& (1<<16))
		return GPIO_LCK_Success ;
	else
		return GPIO_LCk_Error ;
}

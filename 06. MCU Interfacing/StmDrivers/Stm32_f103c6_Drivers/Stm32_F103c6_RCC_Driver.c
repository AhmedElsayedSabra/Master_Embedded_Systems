//*===============================================
//*                   Includes
//*===============================================
#include "Stm32_F103c6_RCC_Driver.h"
const uint8_t APBPrescTable[8U] = {0,0,0,0,1,2,3,4};
const uint8_t AHBPrescTable[16U] = {0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};
uint32_t MCAL_RCC_GetSYS_CLKFreq(void)
{
	switch((RCC->CFGR >> 2) &0b11)
	{
	case 0 :
		return HSI_CLOCK ;
		break ;
	case 1 :
		return HSE_CLOCK ;
		break ;
	case 2 :
		return (uint32_t)16000000;
		break ;
	default :
		return (uint32_t)16000000;
		break ;
	}
}
uint32_t MCAL_RCC_GetHCLKFreq(void)
{
	return (MCAL_RCC_GetSYS_CLKFreq() >> AHBPrescTable[(RCC->CFGR >> 4) & 0b1111]);
}
uint32_t MCAL_RCC_GetPCLK1Freq(void)
{
	return (MCAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR >> 8) & 0b111]) ;
}
uint32_t MCAL_RCC_GetPCLK2Freq(void)
{
	return (MCAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR >> 11) & 0b111]) ;
}

#include<stdint.h>
void Reset_Handler(void);
void Default_Handler(void);
extern int main(void);
extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS  ;
extern unsigned int _E_BSS  ;
extern unsigned int _Stack_top ;
void NMI_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Hard_Fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void MM_Fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Bus_Fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Usage_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void RESERVED0_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void RESERVED1_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void RESERVED2_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void RESERVED3_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Sv_Call_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Debug_reserved_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void RESERVED4_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void Pendsv_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void SysTick_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void IRQ0_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void IRQ1_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void IRQ2_Handler(void)__attribute__((weak,alias ("Default_Handler")));;

unsigned int vectors[]__attribute__((section(".vectors"))) =
{
    (uint32_t) &_Stack_top ,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler ,
    (uint32_t)&Hard_Fault_Handler ,
    (uint32_t) &MM_Fault_Handler ,
    (uint32_t) &Bus_Fault_Handler ,
    (uint32_t) &Usage_fault_Handler ,
    (uint32_t) &RESERVED0_Handler ,
    (uint32_t) &RESERVED1_Handler ,
    (uint32_t) &RESERVED2_Handler ,
    (uint32_t) &RESERVED3_Handler ,
    (uint32_t) &Sv_Call_Handler ,
    (uint32_t) &Debug_reserved_Handler ,
    (uint32_t) &RESERVED4_Handler ,
    (uint32_t) &Pendsv_Handler,
    (uint32_t) &SysTick_Handler ,
    (uint32_t) &IRQ0_Handler,
    (uint32_t) &IRQ1_Handler ,
    (uint32_t) &IRQ2_Handler 
};  

void Reset_Handler(void)
{
    // copy .data section from rom to ram 
    uint32_t Data_Size = (uint8_t *)&_E_DATA  - (uint8_t *)&_S_DATA ;
    uint8_t *Ptr_Src = (uint8_t *)&_E_text ;
    uint8_t *Ptr_Des = (uint8_t *)&_S_DATA ;
    for(int i = 0 ; i < Data_Size ; i++)
    {
        *((uint8_t*)Ptr_Des++) = *((uint8_t*)Ptr_Src++) ;
    }
    // init .bss with into ram 
    uint32_t BSS_Size = (uint8_t *)&_E_BSS  - (uint8_t *)&_S_BSS ;
    Ptr_Des = (uint8_t *)&_S_BSS ;
    for(int j = 0 ; j < BSS_Size ; j++)
    {
        *((uint8_t*)Ptr_Des++) = (uint8_t)0 ;
    }
    // jump to main 
    main();
}
void Default_Handler(void)
{
    Reset_Handler();
}
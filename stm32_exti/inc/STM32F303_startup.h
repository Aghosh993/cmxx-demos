#pragma once
#include <stdint.h>

#define PERIPHERAL_IRQS 85

extern uint32_t __data_start__, __data_end__, __bss_start__, __bss_end__, __etext;
extern int main();
extern uint32_t __StackTop;

class IRQ {
public:
	// Cortex-M4 Exceptions: //
	static void Reset_Handler(void);
	static void NMI_Handler(void);
	static void HardFault_Handler(void);
	static void MemManage_Handler(void);
	static void BusFault_Handler(void);
	static void UsageFault_Handler(void);
	static void SVC_Handler(void);
	static void DebugMon_Handler(void);
	static void PendSV_Handler(void);
	static void SysTick_Handler(void);

	// STM32F303 Exceptions: //
    static void WWDG_handler(void);
    static void PVD_handler(void);
    static void TAMP_STAMP_handler(void);
    static void RTC_WKUP_handler(void);
    static void FLASH_handler(void);
    static void RCC_handler(void);
    static void EXTI0_handler(void);
    static void EXTI1_handler(void);
    static void EXTI2_TSC_handler(void);
    static void EXTI3_handler(void);
    static void EXTI4_handler(void);
    static void DMA1_CH1_handler(void);
    static void DMA1_CH2_handler(void);
    static void DMA1_CH3_handler(void);
    static void DMA1_CH4_handler(void);
    static void DMA1_CH5_handler(void);
    static void DMA1_CH6_handler(void);
    static void DMA1_CH7_handler(void);
    static void ADC1_2_handler(void);
    static void USB_HP_CAN_TX_handler(void);
    static void USB_LP_CAN_RX0_handler(void);
    static void CAN_RX1_handler(void);
    static void CAN_SCE_handler(void);
    static void EXTI9_5_handler(void);
    static void TIM1_BRK_TIM15_handler(void);
    static void TIM1_UP_TIM16_handler(void);
    static void TIM1_TRG_COM_TIM17_handler(void);
    static void TIM1_CC_handler(void);
    static void TIM2_handler(void);
    static void TIM3_handler(void);
    static void TIM4_handler(void);
    static void I2C1_EV_EXTI23_handler(void);
    static void I2C1_ER_handler(void);
    static void I2C2_EV_EXTI24_handler(void);
    static void I2C2_ER_handler(void);
    static void SPI1_handler(void);
    static void SPI2_handler(void);
    static void USART1_EXTI25_handler(void);
    static void USART2_EXTI26_handler(void);
    static void USART3_EXTI28_handler(void);
    static void EXTI15_10_handler(void);
    static void RTCAlarm_handler(void);
    static void USB_WKUP_handler(void);
    static void TIM8_BRK_handler(void);
    static void TIM8_UP_handler(void);
    static void TIM8_TRG_COM_handler(void);
    static void TIM8_CC_handler(void);
    static void ADC3_handler(void);
    static void FMC_handler(void);
    static void SPI3_handler(void);
    static void UART4_EXTI34_handler(void);
    static void UART5_EXTI35_handler(void);
    static void TIM6_DACUNDER_handler(void);
    static void TIM7_handler(void);
    static void DMA2_CH1_handler(void);
    static void DMA2_CH2_handler(void);
    static void DMA2_CH3_handler(void);
    static void DMA2_CH4_handler(void);
    static void DMA2_CH5_handler(void);
    static void ADC4_handler(void);
    static void COMP123_handler(void);
    static void COMP456_handler(void);
    static void COMP7_handler(void);
    static void I2C3_EV_handler(void);
    static void I2C3_ER_handler(void);
    static void USB_HP_handler(void);
    static void USB_LP_handler(void);
    static void USB_WKUP_EXTI_handler(void);
    static void TIM20_BRK_handler(void);
    static void TIM20_UP_handler(void);
    static void TIM20_TRG_COM_handler(void);
    static void TIM20_CC_handler(void);
    static void FPU_handler(void);
    static void SPI4_handler(void);
	// Class-wide methods: //
	static void registerInterrupt(int nInterrupt, IRQ *thisPtr);
	// User-defined interrupt implementation: //
	virtual void ISR(void);
private:
	static IRQ* irqRegistrationTable[PERIPHERAL_IRQS];
};
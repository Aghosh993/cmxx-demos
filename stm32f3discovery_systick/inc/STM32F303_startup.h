#pragma once
#include <cstdint>

#define PERIPHERAL_IRQS 86

extern uint32_t __data_start__, __data_end__, __bss_start__, __bss_end__, __etext;
extern int main();
extern uint32_t __StackTop;

class IRQ {
public:
	/*
		Enum containing offsets of user-registered Core/Peripheral IRQ handlers,
		starting with the SysTick handler.
		NOTE: All handlers BELOW the Systick (i.e. exceptions from Reset to PendSV)
		are intentionally left to be hand-populated!
	 */
	typedef enum {
		SysTick_IRQoffset=0,
		WWDG_IRQoffset=1,
		PVD_IRQoffset=2,
		TAMP_STAMP_IRQoffset=3,
		RTC_WKUP_IRQoffset=4,
		FLASH_IRQoffset=5,
		RCC_IRQoffset=6,
		EXTI0_IRQoffset=7,
		EXTI1_IRQoffset=8,
		EXTI2_TSC_IRQoffset=9,
		EXTI3_IRQoffset=10,
		EXTI4_IRQoffset=11,
		DMA1_CH1_IRQoffset=12,
		DMA1_CH2_IRQoffset=13,
		DMA1_CH3_IRQoffset=14,
		DMA1_CH4_IRQoffset=15,
		DMA1_CH5_IRQoffset=16,
		DMA1_CH6_IRQoffset=17,
		DMA1_CH7_IRQoffset=18,
		ADC1_2_IRQoffset=19,
		USB_HP_CAN_TX_IRQoffset=20,
		USB_LP_CAN_RX0_IRQoffset=21,
		CAN_RX1_IRQoffset=22,
		CAN_SCE_IRQoffset=23,
		EXTI9_5_IRQoffset=24,
		TIM1_BRK_TIM15_IRQoffset=25,
		TIM1_UP_TIM16_IRQoffset=26,
		TIM1_TRG_COM_TIM17_IRQoffset=27,
		TIM1_CC_IRQoffset=28,
		TIM2_IRQoffset=29,
		TIM3_IRQoffset=30,
		TIM4_IRQoffset=31,
		I2C1_EV_EXTI23_IRQoffset=32,
		I2C1_ER_IRQoffset=33,
		I2C2_EV_EXTI24_IRQoffset=34,
		I2C2_ER_IRQoffset=35,
		SPI1_IRQoffset=36,
		SPI2_IRQoffset=37,
		USART1_EXTI25_IRQoffset=38,
		USART2_EXTI26_IRQoffset=39,
		USART3_EXTI28_IRQoffset=40,
		EXTI15_10_IRQoffset=41,
		RTCAlarm_IRQoffset=42,
		USB_WKUP_IRQoffset=43,
		TIM8_BRK_IRQoffset=44,
		TIM8_UP_IRQoffset=45,
		TIM8_TRG_COM_IRQoffset=46,
		TIM8_CC_IRQoffset=47,
		ADC3_IRQoffset=48,
		FMC_IRQoffset=49,
		SPI3_IRQoffset=52,
		UART4_EXTI34_IRQoffset=53,
		UART5_EXTI35_IRQoffset=54,
		TIM6_DACUNDER_IRQoffset=55,
		TIM7_IRQoffset=56,
		DMA2_CH1_IRQoffset=57,
		DMA2_CH2_IRQoffset=58,
		DMA2_CH3_IRQoffset=59,
		DMA2_CH4_IRQoffset=60,
		DMA2_CH5_IRQoffset=61,
		ADC4_IRQoffset=62,
		COMP123_IRQoffset=65,
		COMP456_IRQoffset=66,
		COMP7_IRQoffset=67,
		I2C3_EV_IRQoffset=73,
		I2C3_ER_IRQoffset=74,
		USB_HP_IRQoffset=75,
		USB_LP_IRQoffset=76,
		USB_WKUP_EXTI_IRQoffset=77,
		TIM20_BRK_IRQoffset=78,
		TIM20_UP_IRQoffset=79,
		TIM20_TRG_COM_IRQoffset=80,
		TIM20_CC_IRQoffset=81,
		FPU_IRQoffset=82,
		SPI4_IRQoffset=85
	} irqTableOffset;
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
	static void registerInterrupt(irqTableOffset irq, IRQ *thisPtr);
	// User-defined interrupt implementation: //
	virtual void ISR(void);
private:
	static IRQ* irqRegistrationTable[PERIPHERAL_IRQS];
};
#include <STM32F303_startup.h>

static IRQ defaultRegistration;

IRQ* IRQ::irqRegistrationTable[PERIPHERAL_IRQS] = {
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration,
	&defaultRegistration
};

// Cortex-M4 Exceptions: //
void IRQ::Reset_Handler(void)
{
	/*
		Copy initialization data from flash into SRAM:
	 */
	uint32_t *src, *dst;
	src = &__etext;
	for(dst = &__data_start__; dst < &__data_end__; )
	{
		*dst++ = *src++;
	}
	/*
		Zero out BSS (RAM):
	 */
	for(dst = &__bss_start__; dst < &__bss_end__;)
	{
		*dst++ = 0U;
	}
	main();
	while(1);
}

void IRQ::NMI_Handler(void)
{
	while(1);
}

void IRQ::HardFault_Handler(void)
{
	while(1);
}

void IRQ::MemManage_Handler(void)
{
	while(1);
}

void IRQ::BusFault_Handler(void)
{
	while(1);
}

void IRQ::UsageFault_Handler(void)
{
	while(1);
}

void IRQ::SVC_Handler(void)
{
	while(1);
}

void IRQ::DebugMon_Handler(void)
{
	while(1);
}

void IRQ::PendSV_Handler(void)
{
	while(1);
}

void IRQ::SysTick_Handler(void)
{
	irqRegistrationTable[IRQ::SysTick_IRQoffset]->ISR();
}

// STM32F303 Exceptions: //
void IRQ::WWDG_handler(void)
{
    irqRegistrationTable[IRQ::WWDG_IRQoffset]->ISR();
}

void IRQ::PVD_handler(void)
{
    irqRegistrationTable[IRQ::PVD_IRQoffset]->ISR();
}

void IRQ::TAMP_STAMP_handler(void)
{
    irqRegistrationTable[IRQ::TAMP_STAMP_IRQoffset]->ISR();
}

void IRQ::RTC_WKUP_handler(void)
{
    irqRegistrationTable[IRQ::RTC_WKUP_IRQoffset]->ISR();
}

void IRQ::FLASH_handler(void)
{
    irqRegistrationTable[IRQ::FLASH_IRQoffset]->ISR();
}

void IRQ::RCC_handler(void)
{
    irqRegistrationTable[IRQ::RCC_IRQoffset]->ISR();
}

void IRQ::EXTI0_handler(void)
{
    irqRegistrationTable[IRQ::EXTI0_IRQoffset]->ISR();
}

void IRQ::EXTI1_handler(void)
{
    irqRegistrationTable[IRQ::EXTI1_IRQoffset]->ISR();
}

void IRQ::EXTI2_TSC_handler(void)
{
    irqRegistrationTable[IRQ::EXTI2_TSC_IRQoffset]->ISR();
}

void IRQ::EXTI3_handler(void)
{
    irqRegistrationTable[IRQ::EXTI3_IRQoffset]->ISR();
}

void IRQ::EXTI4_handler(void)
{
    irqRegistrationTable[IRQ::EXTI4_IRQoffset]->ISR();
}

void IRQ::DMA1_CH1_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH1_IRQoffset]->ISR();
}

void IRQ::DMA1_CH2_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH2_IRQoffset]->ISR();
}

void IRQ::DMA1_CH3_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH3_IRQoffset]->ISR();
}

void IRQ::DMA1_CH4_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH4_IRQoffset]->ISR();
}

void IRQ::DMA1_CH5_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH5_IRQoffset]->ISR();
}

void IRQ::DMA1_CH6_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH6_IRQoffset]->ISR();
}

void IRQ::DMA1_CH7_handler(void)
{
    irqRegistrationTable[IRQ::DMA1_CH7_IRQoffset]->ISR();
}

void IRQ::ADC1_2_handler(void)
{
    irqRegistrationTable[IRQ::ADC1_2_IRQoffset]->ISR();
}

void IRQ::USB_HP_CAN_TX_handler(void)
{
    irqRegistrationTable[IRQ::USB_HP_CAN_TX_IRQoffset]->ISR();
}

void IRQ::USB_LP_CAN_RX0_handler(void)
{
    irqRegistrationTable[IRQ::USB_LP_CAN_RX0_IRQoffset]->ISR();
}

void IRQ::CAN_RX1_handler(void)
{
    irqRegistrationTable[IRQ::CAN_RX1_IRQoffset]->ISR();
}

void IRQ::CAN_SCE_handler(void)
{
    irqRegistrationTable[IRQ::CAN_SCE_IRQoffset]->ISR();
}

void IRQ::EXTI9_5_handler(void)
{
    irqRegistrationTable[IRQ::EXTI9_5_IRQoffset]->ISR();
}

void IRQ::TIM1_BRK_TIM15_handler(void)
{
    irqRegistrationTable[IRQ::TIM1_BRK_TIM15_IRQoffset]->ISR();
}

void IRQ::TIM1_UP_TIM16_handler(void)
{
    irqRegistrationTable[IRQ::TIM1_UP_TIM16_IRQoffset]->ISR();
}

void IRQ::TIM1_TRG_COM_TIM17_handler(void)
{
    irqRegistrationTable[IRQ::TIM1_TRG_COM_TIM17_IRQoffset]->ISR();
}

void IRQ::TIM1_CC_handler(void)
{
    irqRegistrationTable[IRQ::TIM1_CC_IRQoffset]->ISR();
}

void IRQ::TIM2_handler(void)
{
    irqRegistrationTable[IRQ::TIM2_IRQoffset]->ISR();
}

void IRQ::TIM3_handler(void)
{
    irqRegistrationTable[IRQ::TIM3_IRQoffset]->ISR();
}

void IRQ::TIM4_handler(void)
{
    irqRegistrationTable[IRQ::TIM4_IRQoffset]->ISR();
}

void IRQ::I2C1_EV_EXTI23_handler(void)
{
    irqRegistrationTable[IRQ::I2C1_EV_EXTI23_IRQoffset]->ISR();
}

void IRQ::I2C1_ER_handler(void)
{
    irqRegistrationTable[IRQ::I2C1_ER_IRQoffset]->ISR();
}

void IRQ::I2C2_EV_EXTI24_handler(void)
{
    irqRegistrationTable[IRQ::I2C2_EV_EXTI24_IRQoffset]->ISR();
}

void IRQ::I2C2_ER_handler(void)
{
    irqRegistrationTable[IRQ::I2C2_ER_IRQoffset]->ISR();
}

void IRQ::SPI1_handler(void)
{
    irqRegistrationTable[IRQ::SPI1_IRQoffset]->ISR();
}

void IRQ::SPI2_handler(void)
{
    irqRegistrationTable[IRQ::SPI2_IRQoffset]->ISR();
}

void IRQ::USART1_EXTI25_handler(void)
{
    irqRegistrationTable[IRQ::USART1_EXTI25_IRQoffset]->ISR();
}

void IRQ::USART2_EXTI26_handler(void)
{
    irqRegistrationTable[IRQ::USART2_EXTI26_IRQoffset]->ISR();
}

void IRQ::USART3_EXTI28_handler(void)
{
    irqRegistrationTable[IRQ::USART3_EXTI28_IRQoffset]->ISR();
}

void IRQ::EXTI15_10_handler(void)
{
    irqRegistrationTable[IRQ::EXTI15_10_IRQoffset]->ISR();
}

void IRQ::RTCAlarm_handler(void)
{
    irqRegistrationTable[IRQ::RTCAlarm_IRQoffset]->ISR();
}

void IRQ::USB_WKUP_handler(void)
{
    irqRegistrationTable[IRQ::USB_WKUP_IRQoffset]->ISR();
}

void IRQ::TIM8_BRK_handler(void)
{
    irqRegistrationTable[IRQ::TIM8_BRK_IRQoffset]->ISR();
}

void IRQ::TIM8_UP_handler(void)
{
    irqRegistrationTable[IRQ::TIM8_UP_IRQoffset]->ISR();
}

void IRQ::TIM8_TRG_COM_handler(void)
{
    irqRegistrationTable[IRQ::TIM8_TRG_COM_IRQoffset]->ISR();
}

void IRQ::TIM8_CC_handler(void)
{
    irqRegistrationTable[IRQ::TIM8_CC_IRQoffset]->ISR();
}

void IRQ::ADC3_handler(void)
{
    irqRegistrationTable[IRQ::ADC3_IRQoffset]->ISR();
}

void IRQ::FMC_handler(void)
{
    irqRegistrationTable[IRQ::FMC_IRQoffset]->ISR();
}

void IRQ::SPI3_handler(void)
{
    irqRegistrationTable[IRQ::SPI3_IRQoffset]->ISR();
}

void IRQ::UART4_EXTI34_handler(void)
{
    irqRegistrationTable[IRQ::UART4_EXTI34_IRQoffset]->ISR();
}

void IRQ::UART5_EXTI35_handler(void)
{
    irqRegistrationTable[IRQ::UART5_EXTI35_IRQoffset]->ISR();
}

void IRQ::TIM6_DACUNDER_handler(void)
{
    irqRegistrationTable[IRQ::TIM6_DACUNDER_IRQoffset]->ISR();
}

void IRQ::TIM7_handler(void)
{
    irqRegistrationTable[IRQ::TIM7_IRQoffset]->ISR();
}

void IRQ::DMA2_CH1_handler(void)
{
    irqRegistrationTable[IRQ::DMA2_CH1_IRQoffset]->ISR();
}

void IRQ::DMA2_CH2_handler(void)
{
    irqRegistrationTable[IRQ::DMA2_CH2_IRQoffset]->ISR();
}

void IRQ::DMA2_CH3_handler(void)
{
    irqRegistrationTable[IRQ::DMA2_CH3_IRQoffset]->ISR();
}

void IRQ::DMA2_CH4_handler(void)
{
    irqRegistrationTable[IRQ::DMA2_CH4_IRQoffset]->ISR();
}

void IRQ::DMA2_CH5_handler(void)
{
    irqRegistrationTable[IRQ::DMA2_CH5_IRQoffset]->ISR();
}

void IRQ::ADC4_handler(void)
{
    irqRegistrationTable[IRQ::ADC4_IRQoffset]->ISR();
}

void IRQ::COMP123_handler(void)
{
    irqRegistrationTable[IRQ::COMP123_IRQoffset]->ISR();
}

void IRQ::COMP456_handler(void)
{
    irqRegistrationTable[IRQ::COMP456_IRQoffset]->ISR();
}

void IRQ::COMP7_handler(void)
{
    irqRegistrationTable[IRQ::COMP7_IRQoffset]->ISR();
}

void IRQ::I2C3_EV_handler(void)
{
    irqRegistrationTable[IRQ::I2C3_EV_IRQoffset]->ISR();
}

void IRQ::I2C3_ER_handler(void)
{
    irqRegistrationTable[IRQ::I2C3_ER_IRQoffset]->ISR();
}

void IRQ::USB_HP_handler(void)
{
    irqRegistrationTable[IRQ::USB_HP_IRQoffset]->ISR();
}

void IRQ::USB_LP_handler(void)
{
    irqRegistrationTable[IRQ::USB_LP_IRQoffset]->ISR();
}

void IRQ::USB_WKUP_EXTI_handler(void)
{
    irqRegistrationTable[IRQ::USB_WKUP_EXTI_IRQoffset]->ISR();
}

void IRQ::TIM20_BRK_handler(void)
{
    irqRegistrationTable[IRQ::TIM20_BRK_IRQoffset]->ISR();
}

void IRQ::TIM20_UP_handler(void)
{
    irqRegistrationTable[IRQ::TIM20_UP_IRQoffset]->ISR();
}

void IRQ::TIM20_TRG_COM_handler(void)
{
    irqRegistrationTable[IRQ::TIM20_TRG_COM_IRQoffset]->ISR();
}

void IRQ::TIM20_CC_handler(void)
{
    irqRegistrationTable[IRQ::TIM20_CC_IRQoffset]->ISR();
}

void IRQ::FPU_handler(void)
{
    irqRegistrationTable[IRQ::FPU_IRQoffset]->ISR();
}

void IRQ::SPI4_handler(void)
{
    irqRegistrationTable[IRQ::SPI4_IRQoffset]->ISR();
}


// Class-wide methods: //
void IRQ::registerInterrupt(irqTableOffset irq, IRQ *thisPtr)
{
	irqRegistrationTable[irq] = thisPtr;
}

// User-defined interrupt implementation (default infinite loop to preserve system state): //
void IRQ::ISR(void)
{
	while(1);
}

void* isr_vectors[] __attribute__ ((section(".isr_vector"))) = {
	&__StackTop,
	IRQ::Reset_Handler,
	IRQ::NMI_Handler,
	IRQ::HardFault_Handler,
	IRQ::MemManage_Handler,
	IRQ::BusFault_Handler,
	IRQ::UsageFault_Handler,
	0,
	0,
	0,
	0,
	IRQ::SVC_Handler,
	IRQ::DebugMon_Handler,
	0,
	IRQ::PendSV_Handler,
	IRQ::SysTick_Handler,
	// Jump addresses for STM32F303 interrupts: //
    IRQ::WWDG_handler,
    IRQ::PVD_handler,
    IRQ::TAMP_STAMP_handler,
    IRQ::RTC_WKUP_handler,
    IRQ::FLASH_handler,
    IRQ::RCC_handler,
    IRQ::EXTI0_handler,
    IRQ::EXTI1_handler,
    IRQ::EXTI2_TSC_handler,
    IRQ::EXTI3_handler,
    IRQ::EXTI4_handler,
    IRQ::DMA1_CH1_handler,
    IRQ::DMA1_CH2_handler,
    IRQ::DMA1_CH3_handler,
    IRQ::DMA1_CH4_handler,
    IRQ::DMA1_CH5_handler,
    IRQ::DMA1_CH6_handler,
    IRQ::DMA1_CH7_handler,
    IRQ::ADC1_2_handler,
    IRQ::USB_HP_CAN_TX_handler,
    IRQ::USB_LP_CAN_RX0_handler,
    IRQ::CAN_RX1_handler,
    IRQ::CAN_SCE_handler,
    IRQ::EXTI9_5_handler,
    IRQ::TIM1_BRK_TIM15_handler,
    IRQ::TIM1_UP_TIM16_handler,
    IRQ::TIM1_TRG_COM_TIM17_handler,
    IRQ::TIM1_CC_handler,
    IRQ::TIM2_handler,
    IRQ::TIM3_handler,
    IRQ::TIM4_handler,
    IRQ::I2C1_EV_EXTI23_handler,
    IRQ::I2C1_ER_handler,
    IRQ::I2C2_EV_EXTI24_handler,
    IRQ::I2C2_ER_handler,
    IRQ::SPI1_handler,
    IRQ::SPI2_handler,
    IRQ::USART1_EXTI25_handler,
    IRQ::USART2_EXTI26_handler,
    IRQ::USART3_EXTI28_handler,
    IRQ::EXTI15_10_handler,
    IRQ::RTCAlarm_handler,
    IRQ::USB_WKUP_handler,
    IRQ::TIM8_BRK_handler,
    IRQ::TIM8_UP_handler,
    IRQ::TIM8_TRG_COM_handler,
    IRQ::TIM8_CC_handler,
    IRQ::ADC3_handler,
    IRQ::FMC_handler,
    0,
    0,
    IRQ::SPI3_handler,
    IRQ::UART4_EXTI34_handler,
    IRQ::UART5_EXTI35_handler,
    IRQ::TIM6_DACUNDER_handler,
    IRQ::TIM7_handler,
    IRQ::DMA2_CH1_handler,
    IRQ::DMA2_CH2_handler,
    IRQ::DMA2_CH3_handler,
    IRQ::DMA2_CH4_handler,
    IRQ::DMA2_CH5_handler,
    IRQ::ADC4_handler,
    0,
    0,
    IRQ::COMP123_handler,
    IRQ::COMP456_handler,
    IRQ::COMP7_handler,
    0,
    0,
    0,
    0,
    0,
    IRQ::I2C3_EV_handler,
    IRQ::I2C3_ER_handler,
    IRQ::USB_HP_handler,
    IRQ::USB_LP_handler,
    IRQ::USB_WKUP_EXTI_handler,
    IRQ::TIM20_BRK_handler,
    IRQ::TIM20_UP_handler,
    IRQ::TIM20_TRG_COM_handler,
    IRQ::TIM20_CC_handler,
    IRQ::FPU_handler,
    0,
    0,
    IRQ::SPI4_handler
};

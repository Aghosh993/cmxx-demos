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
	while(1);
}

// STM32F303 Exceptions: //
void IRQ::WWDG_handler(void)
{
    irqRegistrationTable[0]->ISR();
}

void IRQ::PVD_handler(void)
{
    irqRegistrationTable[1]->ISR();
}

void IRQ::TAMP_STAMP_handler(void)
{
    irqRegistrationTable[2]->ISR();
}

void IRQ::RTC_WKUP_handler(void)
{
    irqRegistrationTable[3]->ISR();
}

void IRQ::FLASH_handler(void)
{
    irqRegistrationTable[4]->ISR();
}

void IRQ::RCC_handler(void)
{
    irqRegistrationTable[5]->ISR();
}

void IRQ::EXTI0_handler(void)
{
    irqRegistrationTable[6]->ISR();
}

void IRQ::EXTI1_handler(void)
{
    irqRegistrationTable[7]->ISR();
}

void IRQ::EXTI2_TSC_handler(void)
{
    irqRegistrationTable[8]->ISR();
}

void IRQ::EXTI3_handler(void)
{
    irqRegistrationTable[9]->ISR();
}

void IRQ::EXTI4_handler(void)
{
    irqRegistrationTable[10]->ISR();
}

void IRQ::DMA1_CH1_handler(void)
{
    irqRegistrationTable[11]->ISR();
}

void IRQ::DMA1_CH2_handler(void)
{
    irqRegistrationTable[12]->ISR();
}

void IRQ::DMA1_CH3_handler(void)
{
    irqRegistrationTable[13]->ISR();
}

void IRQ::DMA1_CH4_handler(void)
{
    irqRegistrationTable[14]->ISR();
}

void IRQ::DMA1_CH5_handler(void)
{
    irqRegistrationTable[15]->ISR();
}

void IRQ::DMA1_CH6_handler(void)
{
    irqRegistrationTable[16]->ISR();
}

void IRQ::DMA1_CH7_handler(void)
{
    irqRegistrationTable[17]->ISR();
}

void IRQ::ADC1_2_handler(void)
{
    irqRegistrationTable[18]->ISR();
}

void IRQ::USB_HP_CAN_TX_handler(void)
{
    irqRegistrationTable[19]->ISR();
}

void IRQ::USB_LP_CAN_RX0_handler(void)
{
    irqRegistrationTable[20]->ISR();
}

void IRQ::CAN_RX1_handler(void)
{
    irqRegistrationTable[21]->ISR();
}

void IRQ::CAN_SCE_handler(void)
{
    irqRegistrationTable[22]->ISR();
}

void IRQ::EXTI9_5_handler(void)
{
    irqRegistrationTable[23]->ISR();
}

void IRQ::TIM1_BRK_TIM15_handler(void)
{
    irqRegistrationTable[24]->ISR();
}

void IRQ::TIM1_UP_TIM16_handler(void)
{
    irqRegistrationTable[25]->ISR();
}

void IRQ::TIM1_TRG_COM_TIM17_handler(void)
{
    irqRegistrationTable[26]->ISR();
}

void IRQ::TIM1_CC_handler(void)
{
    irqRegistrationTable[27]->ISR();
}

void IRQ::TIM2_handler(void)
{
    irqRegistrationTable[28]->ISR();
}

void IRQ::TIM3_handler(void)
{
    irqRegistrationTable[29]->ISR();
}

void IRQ::TIM4_handler(void)
{
    irqRegistrationTable[30]->ISR();
}

void IRQ::I2C1_EV_EXTI23_handler(void)
{
    irqRegistrationTable[31]->ISR();
}

void IRQ::I2C1_ER_handler(void)
{
    irqRegistrationTable[32]->ISR();
}

void IRQ::I2C2_EV_EXTI24_handler(void)
{
    irqRegistrationTable[33]->ISR();
}

void IRQ::I2C2_ER_handler(void)
{
    irqRegistrationTable[34]->ISR();
}

void IRQ::SPI1_handler(void)
{
    irqRegistrationTable[35]->ISR();
}

void IRQ::SPI2_handler(void)
{
    irqRegistrationTable[36]->ISR();
}

void IRQ::USART1_EXTI25_handler(void)
{
    irqRegistrationTable[37]->ISR();
}

void IRQ::USART2_EXTI26_handler(void)
{
    irqRegistrationTable[38]->ISR();
}

void IRQ::USART3_EXTI28_handler(void)
{
    irqRegistrationTable[39]->ISR();
}

void IRQ::EXTI15_10_handler(void)
{
    irqRegistrationTable[40]->ISR();
}

void IRQ::RTCAlarm_handler(void)
{
    irqRegistrationTable[41]->ISR();
}

void IRQ::USB_WKUP_handler(void)
{
    irqRegistrationTable[42]->ISR();
}

void IRQ::TIM8_BRK_handler(void)
{
    irqRegistrationTable[43]->ISR();
}

void IRQ::TIM8_UP_handler(void)
{
    irqRegistrationTable[44]->ISR();
}

void IRQ::TIM8_TRG_COM_handler(void)
{
    irqRegistrationTable[45]->ISR();
}

void IRQ::TIM8_CC_handler(void)
{
    irqRegistrationTable[46]->ISR();
}

void IRQ::ADC3_handler(void)
{
    irqRegistrationTable[47]->ISR();
}

void IRQ::FMC_handler(void)
{
    irqRegistrationTable[48]->ISR();
}

void IRQ::SPI3_handler(void)
{
    irqRegistrationTable[51]->ISR();
}

void IRQ::UART4_EXTI34_handler(void)
{
    irqRegistrationTable[52]->ISR();
}

void IRQ::UART5_EXTI35_handler(void)
{
    irqRegistrationTable[53]->ISR();
}

void IRQ::TIM6_DACUNDER_handler(void)
{
    irqRegistrationTable[54]->ISR();
}

void IRQ::TIM7_handler(void)
{
    irqRegistrationTable[55]->ISR();
}

void IRQ::DMA2_CH1_handler(void)
{
    irqRegistrationTable[56]->ISR();
}

void IRQ::DMA2_CH2_handler(void)
{
    irqRegistrationTable[57]->ISR();
}

void IRQ::DMA2_CH3_handler(void)
{
    irqRegistrationTable[58]->ISR();
}

void IRQ::DMA2_CH4_handler(void)
{
    irqRegistrationTable[59]->ISR();
}

void IRQ::DMA2_CH5_handler(void)
{
    irqRegistrationTable[60]->ISR();
}

void IRQ::ADC4_handler(void)
{
    irqRegistrationTable[61]->ISR();
}

void IRQ::COMP123_handler(void)
{
    irqRegistrationTable[64]->ISR();
}

void IRQ::COMP456_handler(void)
{
    irqRegistrationTable[65]->ISR();
}

void IRQ::COMP7_handler(void)
{
    irqRegistrationTable[66]->ISR();
}

void IRQ::I2C3_EV_handler(void)
{
    irqRegistrationTable[72]->ISR();
}

void IRQ::I2C3_ER_handler(void)
{
    irqRegistrationTable[73]->ISR();
}

void IRQ::USB_HP_handler(void)
{
    irqRegistrationTable[74]->ISR();
}

void IRQ::USB_LP_handler(void)
{
    irqRegistrationTable[75]->ISR();
}

void IRQ::USB_WKUP_EXTI_handler(void)
{
    irqRegistrationTable[76]->ISR();
}

void IRQ::TIM20_BRK_handler(void)
{
    irqRegistrationTable[77]->ISR();
}

void IRQ::TIM20_UP_handler(void)
{
    irqRegistrationTable[78]->ISR();
}

void IRQ::TIM20_TRG_COM_handler(void)
{
    irqRegistrationTable[79]->ISR();
}

void IRQ::TIM20_CC_handler(void)
{
    irqRegistrationTable[80]->ISR();
}

void IRQ::FPU_handler(void)
{
    irqRegistrationTable[81]->ISR();
}

void IRQ::SPI4_handler(void)
{
    irqRegistrationTable[84]->ISR();
}


// Class-wide methods: //
void IRQ::registerInterrupt(int nInterrupt, IRQ *thisPtr)
{
	irqRegistrationTable[nInterrupt] = thisPtr;
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

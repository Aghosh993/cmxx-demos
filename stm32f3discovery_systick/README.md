# Systick demo

This demo configures and enables the SysTick interrupt on the Cortex-M4 core, and then runs a cyclic GPIO test across the USER LEDs on the STM32F3 Discovery containing the STM32F303VCT6 microcontroller. The SysTick peripheral is configured to generate a 1 ms tick, and the relevant class contains methods to use this timebase to generate delays and keep track of system elapsed time since startup.

(c) 2018, Abhimanyu Ghosh
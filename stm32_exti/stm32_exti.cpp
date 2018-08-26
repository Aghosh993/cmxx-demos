/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 20 Hz.

	(c) Abhimanyu Ghosh, 2017
 */

#include <stdint.h>

#include <STM32F303.h>
#include <STM32F303_startup.h>
#include <gpio.h>

#define CPU_TICKS_PER_MS  72000

static void cpu_sw_delay(uint32_t ms)
{
  uint32_t i = 0U;
  uint32_t j = 0U;

  for(i = 0U; i < ms; ++i)
  {
    for(j = 0U; j < CPU_TICKS_PER_MS; ++j)
    {
      asm("nop");
    }
  }
}

class EXTIdemo : public IRQ {
public:
  EXTIdemo() : btn0(0, false), led0(8, true, true), _on(false)
  {
    /*
      Enable EXTI line 0, and enable both rising and falling edges:
     */
    STM32F303::EXTI::IMR1::MR0::write(1);
    STM32F303::EXTI::RTSR1::TR0::write(1);
    // STM32F303::EXTI::FTSR1::TR0::write(1);
    
    /*
      Enable clock to SYSCFG module, and select PA0
      as the intended source of events on EXTI0 as 
      configured in the previous step:
     */
    STM32F303::RCC::APB2ENR::SYSCFGEN::write(1);
    STM32F303::SYSCFG_COMP_OPAMP::SYSCFG_EXTICR1::EXTI0::write(0);
    
    /*
      Enable IRQ line 6 (i.e. EXTI0_IRQn) at the NVIC so that 
      it can make the MCU vector to our ISR:
     */
    STM32F303::NVIC::ISER0::SETENA::write(1<<6);

    /*
      Finally, register our class-specific interrupt handler
      within the vector table:
     */
    IRQ::registerInterrupt(6, this);
  }

  /*
    A polling-driven mock interface to test the ISR functionality:
   */
  void mock(void)
  {
    if(btn0.read())
    {
      ISR();

      /*
        Wait a bit to allow for observation of system behavior:
       */
      cpu_sw_delay(10U);
    }
  }

  bool eventOccurred(void)
  {
    bool tmp = _on;
    return tmp;
  }

  /*
    This is an overriden handler defining our intended 
    class ISR behavior:
   */
  void ISR(void)
  {
    /*
      Acknowledge and clear the requisite EXTI line:
     */
    STM32F303::EXTI::PR1::PR0::write(1);
    /*
      Toggle the internal private variable, and 
      toggle the registered LED as required:
     */
    if(_on)
    {
      _on = false;
      led0.set();
    }
    else
    {
      _on = true;
      led0.clear();
    }
  }
private:
  gpio::gpio<gpio::GPIOE> led0;
  gpio::gpio<gpio::GPIOA> btn0;
  volatile bool _on;
};

int main()
{
  EXTIdemo e;
  gpio::gpio<gpio::GPIOE> LD9 = gpio::gpio<gpio::GPIOE>(12, true, true);
  /*
    Main event loop to toggle another LED based on detected edge events coming 
    in from the EXTI configuration above:
   */
  while(1)
  {
    if(e.eventOccurred())
    {
     LD9.toggle(); 
    }
    cpu_sw_delay(5U);
  }

  return 0;
}

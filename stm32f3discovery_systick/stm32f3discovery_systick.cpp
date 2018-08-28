/*
	This is the main user software application
	In this case, we have below the code necessary to toggle a set of LEDs on a	STM32 F3 Discovery PCB at 20 Hz.

	(c) Abhimanyu Ghosh, 2017
 */

#include <cstdint>

#include <STM32F303.h>
#include <STM32F303_startup.h>
#include <gpio.h>

class SysTick : public IRQ
{
static constexpr uint32_t defaultClk = 8000000;

public:
  SysTick(void) : ms(0U)
  {
    // Register class-specific IRQ handler in the vector table:
    IRQ::registerInterrupt(IRQ::SysTick_IRQoffset, this);

    // Set Systick prescaler based on default clock out of reset, per ST docs:
    STM32F303::STK::LOAD::RELOAD::write((defaultClk/1000)-1);

    // Set CPU(core) clock as clock source:
    STM32F303::STK::CTRL::CLKSOURCE::write(1);

    // Clear Current value reg, per ARM docs
    // This also clears the COUNTFLAG bit
    STM32F303::STK::VAL::CURRENT::write(0x0); 
    
    // Enable Systick interrupt:
    STM32F303::STK::CTRL::TICKINT::write(1);

    // Enable Systick counter:
    STM32F303::STK::CTRL::ENABLE::write(1);
  }

  ~SysTick(void)
  {
    // Nothing here for now...
  }

  uint32_t getMS(void)
  {
    return ms;
  }
  
  void delay(uint32_t ms)
  {
    uint32_t endTime = this->ms + ms;
    while(this->ms < endTime);
  }
  
  void ISR(void)
  {
    ++ms;
  }

private:
  volatile uint32_t ms;
};

template<gpio::port p>
class pinPair
{
public:
  pinPair(int pin1, int pin2) : led1(pin1, true), led2(pin2, true){}
  void set(void)
  {
    led1.set();
    led2.set();
  }
  void clear(void)
  {
    led1.clear();
    led2.clear();
  }
  void toggle(void)
  {
    led1.toggle();
    led2.toggle();
  }

private:
  gpio::gpio<p> led1, led2;
};

int main()
{
  SysTick sysTimer;
  
  pinPair<gpio::GPIOE> g1 = pinPair<gpio::GPIOE>(9,13);
  pinPair<gpio::GPIOE> g2 = pinPair<gpio::GPIOE>(10,14);
  pinPair<gpio::GPIOE> g3 = pinPair<gpio::GPIOE>(11,15);
  pinPair<gpio::GPIOE> g4 = pinPair<gpio::GPIOE>(8,12);
  
  while(1)
  {
    g1.set();
    g2.clear();
    g3.clear();
    g4.clear();
    sysTimer.delay(150U);

    g1.clear();
    g2.set();
    g3.clear();
    g4.clear();
    sysTimer.delay(150U);
    
    g1.clear();
    g2.clear();
    g3.set();
    g4.clear();
    sysTimer.delay(150U);
    
    g1.clear();
    g2.clear();
    g3.clear();
    g4.set();
    sysTimer.delay(150U);
  }

  return 0;
}

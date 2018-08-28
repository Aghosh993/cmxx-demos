#pragma once

#include <STM32F303.h>

namespace gpio
{
	typedef enum {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE} port;
	template<port p>
	class gpio
	{
	public:
		gpio(int pin, bool output, bool initVal=false) : _pin(pin), _output(output)
		{
			switch(p)
			{
				case GPIOA:
					STM32F303::RCC::AHBENR::IOPAEN::write(1);
					if(output)
					{
						STM32F303::GPIOA::MODER::MODER_REG::write(
							STM32F303::GPIOA::MODER::MODER_REG::read() | (1<<pin*2));
						STM32F303::GPIOA::MODER::MODER_REG::write(
							STM32F303::GPIOA::MODER::MODER_REG::read() & ~(1<<(pin*2+1)));
					}
					else
					{
						STM32F303::GPIOA::MODER::MODER_REG::write(
							STM32F303::GPIOA::MODER::MODER_REG::read() & ~(3<<pin*2));
					}
					if(initVal)
					{
						STM32F303::GPIOA::BSRR::BSRR_REG::write(1<<pin);
					}
					else
					{
						STM32F303::GPIOA::BSRR::BSRR_REG::write(1<<(pin+15));	
					}
					break;
				case GPIOB:
					STM32F303::RCC::AHBENR::IOPBEN::write(1);
					if(output)
					{
						STM32F303::GPIOB::MODER::MODER_REG::write(
							STM32F303::GPIOB::MODER::MODER_REG::read() | (1<<pin*2));
						STM32F303::GPIOB::MODER::MODER_REG::write(
							STM32F303::GPIOB::MODER::MODER_REG::read() & ~(1<<(pin*2+1)));
					}
					else
					{
						STM32F303::GPIOB::MODER::MODER_REG::write(
							STM32F303::GPIOB::MODER::MODER_REG::read() & ~(3<<pin*2));
					}
					if(initVal)
					{
						STM32F303::GPIOB::BSRR::BSRR_REG::write(1<<pin);
					}
					else
					{
						STM32F303::GPIOB::BSRR::BSRR_REG::write(1<<(pin+15));	
					}
					break;
				case GPIOC:
					STM32F303::RCC::AHBENR::IOPCEN::write(1);
					if(output)
					{
						STM32F303::GPIOC::MODER::MODER_REG::write(
							STM32F303::GPIOC::MODER::MODER_REG::read() | (1<<pin*2));
						STM32F303::GPIOC::MODER::MODER_REG::write(
							STM32F303::GPIOC::MODER::MODER_REG::read() & ~(1<<(pin*2+1)));
					}
					else
					{
						STM32F303::GPIOC::MODER::MODER_REG::write(
							STM32F303::GPIOC::MODER::MODER_REG::read() & ~(3<<pin*2));
					}
					if(initVal)
					{
						STM32F303::GPIOC::BSRR::BSRR_REG::write(1<<pin);
					}
					else
					{
						STM32F303::GPIOC::BSRR::BSRR_REG::write(1<<(pin+15));	
					}
					break;
				case GPIOD:
					STM32F303::RCC::AHBENR::IOPDEN::write(1);
					if(output)
					{
						STM32F303::GPIOD::MODER::MODER_REG::write(
							STM32F303::GPIOD::MODER::MODER_REG::read() | (1<<pin*2));
						STM32F303::GPIOD::MODER::MODER_REG::write(
							STM32F303::GPIOD::MODER::MODER_REG::read() & ~(1<<(pin*2+1)));
					}
					else
					{
						STM32F303::GPIOD::MODER::MODER_REG::write(
							STM32F303::GPIOD::MODER::MODER_REG::read() & ~(3<<pin*2));
					}
					if(initVal)
					{
						STM32F303::GPIOD::BSRR::BSRR_REG::write(1<<pin);
					}
					else
					{
						STM32F303::GPIOD::BSRR::BSRR_REG::write(1<<(pin+15));	
					}
					break;
				case GPIOE:
					STM32F303::RCC::AHBENR::IOPEEN::write(1);
					if(output)
					{
						STM32F303::GPIOE::MODER::MODER_REG::write(
							STM32F303::GPIOE::MODER::MODER_REG::read() | (1<<pin*2));
						STM32F303::GPIOE::MODER::MODER_REG::write(
							STM32F303::GPIOE::MODER::MODER_REG::read() & ~(1<<(pin*2+1)));
					}
					else
					{
						STM32F303::GPIOE::MODER::MODER_REG::write(
							STM32F303::GPIOE::MODER::MODER_REG::read() & ~(3<<pin*2));
					}
					if(initVal)
					{
						STM32F303::GPIOE::BSRR::BSRR_REG::write(1<<pin);
					}
					else
					{
						STM32F303::GPIOE::BSRR::BSRR_REG::write(1<<(pin+15));	
					}
					break;
			}
		}
		bool read()
		{
			switch(p)
			{
				case GPIOA:
					if(STM32F303::GPIOA::IDR::IDR_REG::read() & 1<<_pin)
					{
						return true;
					}
					return false;
					break;
				case GPIOB:
					if(STM32F303::GPIOB::IDR::IDR_REG::read() & 1<<_pin)
					{
						return true;
					}
					return false;
					break;
				case GPIOC:
					if(STM32F303::GPIOC::IDR::IDR_REG::read() & 1<<_pin)
					{
						return true;
					}
					return false;
					break;
				case GPIOD:
					if(STM32F303::GPIOD::IDR::IDR_REG::read() & 1<<_pin)
					{
						return true;
					}
					return false;
					break;
				case GPIOE:
					if(STM32F303::GPIOE::IDR::IDR_REG::read() & 1<<_pin)
					{
						return true;
					}
					return false;
					break;
			}
		}
		void set()
		{
			switch(p)
			{
				case GPIOA:
					STM32F303::GPIOA::BSRR::BSRR_REG::write(1<<_pin);
					break;
				case GPIOB:
					STM32F303::GPIOB::BSRR::BSRR_REG::write(1<<_pin);
					break;
				case GPIOC:
					STM32F303::GPIOC::BSRR::BSRR_REG::write(1<<_pin);
					break;
				case GPIOD:
					STM32F303::GPIOD::BSRR::BSRR_REG::write(1<<_pin);
					break;
				case GPIOE:
					STM32F303::GPIOE::BSRR::BSRR_REG::write(1<<_pin);
					break;
			}
		}
		void clear()
		{
			switch(p)
			{
				case GPIOA:
					STM32F303::GPIOA::BSRR::BSRR_REG::write(1<<(_pin+16));
					break;
				case GPIOB:
					STM32F303::GPIOB::BSRR::BSRR_REG::write(1<<(_pin+16));
					break;
				case GPIOC:
					STM32F303::GPIOC::BSRR::BSRR_REG::write(1<<(_pin+16));
					break;
				case GPIOD:
					STM32F303::GPIOD::BSRR::BSRR_REG::write(1<<(_pin+16));
					break;
				case GPIOE:
					STM32F303::GPIOE::BSRR::BSRR_REG::write(1<<(_pin+16));
					break;
			}
		}
		void toggle()
		{
			switch(p)
			{
				case GPIOA:
					STM32F303::GPIOA::ODR::ODR_REG::write(STM32F303::GPIOA::ODR::ODR_REG::read() ^ (1<<_pin));
					break;
				case GPIOB:
					STM32F303::GPIOB::ODR::ODR_REG::write(STM32F303::GPIOB::ODR::ODR_REG::read() ^ (1<<_pin));
					break;
				case GPIOC:
					STM32F303::GPIOC::ODR::ODR_REG::write(STM32F303::GPIOC::ODR::ODR_REG::read() ^ (1<<_pin));
					break;
				case GPIOD:
					STM32F303::GPIOD::ODR::ODR_REG::write(STM32F303::GPIOD::ODR::ODR_REG::read() ^ (1<<_pin));
					break;
				case GPIOE:
					STM32F303::GPIOE::ODR::ODR_REG::write(STM32F303::GPIOE::ODR::ODR_REG::read() ^ (1<<_pin));
					break;
			}
		}
	private:
		int _pin;
		bool _output;
	};
}
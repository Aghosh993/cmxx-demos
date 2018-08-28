# cmxx-demos
Demos of the use of cmxx auto-generated projects for various MCU platforms. Currently targeting the [STM32F3 Discovery board](https://www.st.com/en/evaluation-tools/stm32f3discovery.html) ([MCU datasheet](https://www.st.com/resource/en/datasheet/stm32f303vc.pdf), [Cortex M programming manual](https://www.st.com/resource/en/programming_manual/dm00046982.pdf), [Reference Manual](https://www.st.com/resource/en/reference_manual/dm00043574.pdf), [ARM Info Center online reference](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/Cihcajhj.html))

## Purpose
This repo showcases a first-principles approach to driver development for the Cortex-M line of microcontrollers. There is absolutely no vendor code/IP utilized beyond the SVD (System View Description) XML file. The cmxx submodule contains a Python script that accepts an SVD file as an input and auto-generates a project structure containing device header and startup code, along with a functional Makefile and linker script. Practically all code that ends up on the chip at runtime is within this generated project structure, allowing for a better understanding of the exact hardware initialization process as it should occur in conjunction with the use of C++11 for better source readability and compile-time optimization.

## Quickstart
Recursively clone this repo. It is assumed a working arm-none-eabi toolchain is in your PATH. If not, head over [here](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads), download and extract the relevant package and add the binary directory to your system PATH. Alternatively, don't modify your PATH, but rather modify the TOOLCHAIN_ROOT and PREFIX in the Makefiles in this repo's demos to point to the toolchain you wish to use.

Once a recursive clone is complete, cd into any given demo, and run "make". If you have OpenOCD installed, "make load" should load the resulting binary via the STLink, assuming Udev has been configured correctly and your STM32 Discovery board is plugged in.

## Extending and adding examples
Do the following to generate a new project template for your device (assuming you have an SVD file.. check the cmxx/cmsis-svd/data directory to view pre-packaged SVD files):

```bash
cd cmxx/scripts
./mkproject.py PATH_TO_SVD ../../project_name
```

(c) 2017-2018, Abhimanyu Ghosh
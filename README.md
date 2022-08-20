# LED_Interface
LED Interface for STM32 family.


#### Iontra Embedded Software Engineer Technical Assignment

### Project Statement
Design an LED interface not specific to any one microcontroller or LED driver that provides
functions to control the state, color and brightness of an LED. Also, do one simple
implementation of the LED interface for an RGB LED on an STM32.

### Overview
Iontra may choose to use different microcontrollers in various products, but ideally a lot of the
core code should remain the same. Rather than having to modify the core code every time, we
should aim to write Iontra interfaces and be able to swap out the underlying code depending
on the hardware platform we choose.

### Interface Requirements
- Initialize the LEDs.
- Support up to 5 LEDs.
- Change the LED state: Off, Red, Green, Blue
- Change the brightness of an LED: 0 – 100%

### Implementation
We’d like to see an implementation of the LED interface written to control a single RGB LED on
an STM32 microcontroller. You are not expected to actually run this on an STM32, but the HAL
libraries provided by ST should be referenced for peripheral control. You can choose to either
integrate the HAL libraries into your code, or you can just stub out the functions needed to
make the code compile.

Assume there is a simple RGB LED (example here:
https://www.mouser.com/datasheet/2/445/150202M153130-1838938.pdf) connected to 3
pins on the STM32. Write an implementation of the LED interface that would meet all of the
functionality from the interface requirements. It is ok to assume the STM32 is initialized by the
time the LED functions are being called (system initialized and clock set).

### Delivery
Iontra uses Github for version control. If possible, please use a personal Github repository to
upload and share your code. If you wish to use a private repository, please add neileeyo (Neil
McCullough) as a collaborator to the private repository.
If you’re unable to use Github, please zip up the code and email it.

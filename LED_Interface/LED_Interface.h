#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

// Include STM32 HAL Lib
#include <stdint.h>

class LED_Interface{

    private:

        static const uint8_t arr_size = 5;

        // Holds the pin numbers for all 5 LEDs
        uint8_t led_array[arr_size];

    public:
        // Overloaded Constructors
        LED_Interface(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5);
        LED_Interface(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);
        LED_Interface(uint8_t pin1, uint8_t pin2, uint8_t pin3);
        LED_Interface(uint8_t pin1, uint8_t pin2);
        LED_Interface(uint8_t pin1);

        // Change State of LED
        void To_Red(uint8_t led);
        void To_Blue(uint8_t led);
        void To_Green(uint8_t led);
        void LED_Off(uint8_t led);
        void LED_All_Off();
        void Change_Brightness(uint8_t led, uint8_t percent_brightness);


};


#endif
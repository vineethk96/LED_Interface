#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

// Include STM32 HAL Lib
#include <stdint.h>

#define LED_COUNT   5
#define LED_PIN     3

class LED_Interface{

    private:

        static const uint8_t led_default_brightness = 100;

        uint8_t led_enabled = 0;
        uint8_t error_flags = 0;

        struct led_info{
            //bool isOff = true;
            bool isRed = false;
            bool isGreen = false;
            bool isBlue = false;
            uint8_t duty_cycle = led_default_brightness;
            uint8_t r_pin = 0;
            uint8_t g_pin = 0;
            uint8_t b_pin = 0;
        };

        led_info led_array[LED_COUNT];

    public:
    
        void Activate_LED(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin);
        uint8_t Get_LED_Count();

        // Change State of LED
        void To_Red(uint8_t led);
        void To_Blue(uint8_t led);
        void To_Green(uint8_t led);
        void LED_Off(uint8_t led);
        void LED_All_Off();
        void Change_Brightness(uint8_t led, uint8_t percent_brightness);

        // Get LED Error Flags
        uint8_t Get_Errors();

    private:
        uint8_t Map(uint8_t percent_brightness);
        void Set_PWM(uint8_t led);


};


#endif
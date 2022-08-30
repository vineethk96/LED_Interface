#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

// Include STM32 HAL Lib
#include <stdint.h>
#include <HAL_Stub.h>

/**
 * @brief 
 * STM32 MCU INFO:
 * 48MHz system clock
 * 
 */

class LED_Interface{

    /**
     * VARIABLES
     */
    private:

        static const uint8_t DEFAULT_BRIGHTNESS = 100;
        static const uint8_t LED_COUNT = 5;
        static const uint8_t DEFUALT_LED_CCR = 0;
        static const uint8_t MAX_LED_CCR = 100;

        TIM_HandleTypeDef hw_timer_1;
        TIM_HandleTypeDef hw_timer_2;
        TIM_HandleTypeDef hw_timer_3;
        TIM_HandleTypeDef hw_timer_4;
        TIM_HandleTypeDef hw_timer_5;

        uint8_t led_enabled = 0;        // Tracks up to 5 LEDs
        uint8_t error_flags = 0;        // TODO: Tracks any error status' that could occur

        typedef enum LED_States{
            OFF,
            RED,
            BLUE,
            GREEN
        };

        // Structure to track each LEDs info
        //  - Allows us to track an LED by numbers 0-4 rather than by pin number for ease of use.
        struct led_info{
            LED_States current_state = OFF;
            uint8_t brightness = DEFAULT_BRIGHTNESS;
        };

        // Contains all 5 LEDs in one location
        led_info led_array[LED_COUNT];

    /**
     * FUNCTIONS
     */
    public:
    
        LED_Interface();
        void Activate_LED();
        uint8_t Get_LED_Count();

        // Change State of LED
        void To_Red(uint8_t led);
        void To_Blue(uint8_t led);
        void To_Green(uint8_t led);
        void LED_Off(uint8_t led);
        void LED_All_Off();

        // Change LED Brightness
        void Change_Brightness(uint8_t led, uint8_t percent_brightness);

        // Get LED Error Flags
        uint8_t Get_Errors();

    private:
        // Allows for introduction of different LED duty cycles to be used in a future expansion of the current implementation
        uint8_t Map(uint8_t percent_brightness);

        // Changes the Duty Cycle of the LEDs
        void Set_PWM(uint8_t led);

        void Set_PWM(uint8_t led, TIM_HandleTypeDef* time_handle);


};


#endif
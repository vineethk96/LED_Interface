#include "LED_Interface.h"

void LED_Interface::Activate_LED(uint8_t red_pin, uint8_t green_pin, uint8_t blue_pin){

    if( Get_LED_Count() >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Too many LEDs
        return;
    }

    led_array[led_enabled].r_pin = red_pin;
    led_array[led_enabled].g_pin = green_pin;
    led_array[led_enabled].b_pin = blue_pin;

    led_enabled++;
}

uint8_t LED_Interface::Get_LED_Count(){
    return led_enabled;
}

void LED_Interface::To_Red(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].isRed = true;
}

void LED_Interface::To_Green(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].isGreen = true;
}

void LED_Interface::To_Blue(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].isBlue = true;
}

void LED_Interface::LED_Off(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    // Set to Duty Cycle of 0% to Power Off LED
    led_array[led].duty_cycle = Map(0);

    // Set PWM Value

}

void LED_Interface::LED_All_Off(){

    for(uint8_t i = 0; i < LED_COUNT; ++i){
        LED_Off(i);
    }
}

void LED_Interface::Change_Brightness(uint8_t led, uint8_t percent_brightness){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].duty_cycle = Map(percent_brightness);
    // Set PWM Value
}

uint8_t LED_Interface::Get_Errors(){
    return error_flags;
}

uint8_t LED_Interface::Map(uint8_t percent_brightness){

    // Convert from a percent between 0 and 100
    // To the duty cycle value for an LED
}

void LED_Interface::Set_PWM(uint8_t led){

    if(led_array[led].isRed){

        // Set PWM at pin:  led_array[led].r_pin
        // To:              led_array[led].duty_cycle
    }

    if(led_array[led].isGreen){

        // Set PWM at pin: led_array[led].g_pin
        // To:              led_array[led].duty_cycle
    }

    if(led_array[led].isBlue){

        // Set PWM at pin: led_array[led].b_pin
        // To:              led_array[led].duty_cycle
    }
}
#include "LED_Interface.h"

LED_Interface::LED_Interface(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4){

    led_array[0] = pin0;
    led_array[1] = pin1;
    led_array[2] = pin2;
    led_array[3] = pin3;
    led_array[4] = pin4;
}

LED_Interface::LED_Interface(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3){
    led_array[0] = pin0;
    led_array[1] = pin1;
    led_array[2] = pin2;
    led_array[3] = pin3;
}

LED_Interface::LED_Interface(uint8_t pin0, uint8_t pin1, uint8_t pin2){
    led_array[0] = pin0;
    led_array[1] = pin1;
    led_array[2] = pin2;
}

LED_Interface::LED_Interface(uint8_t pin0, uint8_t pin1){
    led_array[0] = pin0;
    led_array[1] = pin1;
}

LED_Interface::LED_Interface(uint8_t pin0){
    led_array[0] = pin0;
}

void LED_Interface::To_Red(uint8_t led){

}

void LED_Interface::To_Blue(uint8_t led){

}

void LED_Interface::To_Green(uint8_t led){

}

void LED_Interface::LED_Off(uint8_t led){

}

void LED_Interface::LED_All_Off(){

    for(uint8_t i = 0; i < arr_size; ++i){
        LED_Off(led_array[i]);
    }
}

void LED_Interface::Change_Brightness(uint8_t led, uint8_t percent_brightness){

}
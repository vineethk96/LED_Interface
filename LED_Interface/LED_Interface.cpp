#include "LED_Interface.h"

LED_Interface::LED_Interface(){

    MX_GPIO_Init();
    MX_TIM1_Init();
    MX_TIM2_Init();
    MX_TIM3_Init();
    MX_TIM4_Init();
    MX_TIM5_Init();

}

void LED_Interface::Activate_LED(){

    if( Get_LED_Count() >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Too many LEDs
        return;
    }

    // Load default values into Capture Compare Registers
    // Then begin timers in PWM mode
    switch(led_enabled){
        case 1:
            TIM1->CCR1 = DEFUALT_LED_CCR;
            HAL_TIM_PWM_Start(&hw_timer_1, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&hw_timer_1, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&hw_timer_1, TIM_CHANNEL_3);
            break;
        case 2:
            TIM2->CCR1 = DEFUALT_LED_CCR;
            HAL_TIM_PWM_Start(&hw_timer_2, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&hw_timer_2, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&hw_timer_2, TIM_CHANNEL_3);
            break;
        case 3:
            TIM3->CCR1 = DEFUALT_LED_CCR;
            HAL_TIM_PWM_Start(&hw_timer_3, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&hw_timer_3, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&hw_timer_3, TIM_CHANNEL_3);
            break;
        case 4:
            TIM4->CCR1 = DEFUALT_LED_CCR;
            HAL_TIM_PWM_Start(&hw_timer_4, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&hw_timer_4, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&hw_timer_4, TIM_CHANNEL_3);
            break;
        case 5:
            TIM5->CCR1 = DEFUALT_LED_CCR;
            HAL_TIM_PWM_Start(&hw_timer_5, TIM_CHANNEL_1);
            HAL_TIM_PWM_Start(&hw_timer_5, TIM_CHANNEL_2);
            HAL_TIM_PWM_Start(&hw_timer_5, TIM_CHANNEL_3);
            break;
    }

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

    led_array[led].current_state = RED;

    Set_PWM(led);
}

void LED_Interface::To_Green(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].current_state = GREEN;

    Set_PWM(led);
}

void LED_Interface::To_Blue(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].current_state = BLUE;

    Set_PWM(led);
}

void LED_Interface::LED_Off(uint8_t led){

    if( led >= LED_COUNT ){
        // DO SOMETHING WITH: error_flags
            // Accessing more than allowed LEDs
    }

    led_array[led].current_state = OFF;

    // Set to Duty Cycle of 0% to Power Off LED
    led_array[led].brightness = 0;

    // Set PWM Value
    Set_PWM(led);

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

    led_array[led].brightness = percent_brightness;

    // Set PWM Value
    Set_PWM(led);
}

uint8_t LED_Interface::Get_Errors(){
    return error_flags;
}

void LED_Interface::Set_PWM(uint8_t led){

    switch(led){
        case 1:
            Set_PWM(led, &hw_timer_1);
            break;
        case 2:
            Set_PWM(led, &hw_timer_2);
            break;
        case 3:
            Set_PWM(led, &hw_timer_3);
            break;
        case 4:
            Set_PWM(led, &hw_timer_4);
            break;
        case 5:
            Set_PWM(led, &hw_timer_5);
            break;
    }
}

void LED_Interface::Set_PWM(uint8_t led, TIM_HandleTypeDef* time_handle){

    switch(led_array[led].current_state){
        case LED_States::OFF:
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_1, led_array[led].brightness);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_2, led_array[led].brightness);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_3, led_array[led].brightness);
            break;
        case LED_States::RED:
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_1, led_array[led].brightness);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_2, 0);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_3, 0);
            break;
        case LED_States::GREEN:
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_1, 0);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_2, led_array[led].brightness);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_3, 0);
            break;
        case LED_States::BLUE:
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_1, 0);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_2, 0);
            _HAL_TIM_SET_COMPARE(time_handle, TIM_CHANNEL_3, led_array[led].brightness);
            break;
    }
}
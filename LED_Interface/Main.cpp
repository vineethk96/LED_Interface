#include <LED_Interface.h>

int Main(){

    LED_Interface myLEDs;

    for(uint8_t i = 0; i < 5; ++i){
        myLEDs.Activate_LED();
    }

    for(uint8_t i = 0; i < 5; ++i){
        myLEDs.To_Red(i);
    }

    for(uint8_t i = 0; i < 10; ++i){
        for(uint8_t j = 0; j < 5; ++j){
            myLEDs.Change_Brightness(j, i*10);
        }
    }

    for(uint8_t i = 0; i < 5; ++i){
        myLEDs.To_Green(i);
    }

    for(uint8_t i = 0; i < 10; ++i){
        for(uint8_t j = 0; j < 5; ++j){
            myLEDs.Change_Brightness(j, i*10);
        }
    }

    for(uint8_t i = 0; i < 5; ++i){
        myLEDs.To_Blue(i);
    }

    for(uint8_t i = 0; i < 10; ++i){
        for(uint8_t j = 0; j < 5; ++j){
            myLEDs.Change_Brightness(j, i*10);
        }
    }

    myLEDs.LED_All_Off();

    return 0;
}
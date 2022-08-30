#include <stdint.h>

void SystemClock_Config();

static void MX_GPIO_Init();

static void MX_TIM1_Init();
static void MX_TIM2_Init();
static void MX_TIM3_Init();
static void MX_TIM4_Init();
static void MX_TIM5_Init();

class TIM_HandleTypeDef{

};

static const uint8_t TIM_CHANNEL_1 = 1; // Red
static const uint8_t TIM_CHANNEL_2 = 1; // Green
static const uint8_t TIM_CHANNEL_3 = 1; // Blue

struct TIM{
    uint8_t CCR1 = 0;
};

TIM* TIM1;
TIM* TIM2;
TIM* TIM3;
TIM* TIM4;
TIM* TIM5;


void HAL_TIM_PWM_Start(TIM_HandleTypeDef* TIM_HANDLE, uint8_t TIM_CHANNEL_1);

void _HAL_TIM_SET_COMPARE(TIM_HandleTypeDef* TIM_HANDLE, uint8_t TIM_CHANNEL_1, uint8_t new_CCR);

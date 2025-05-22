#include "beep.h"

void beep_init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1, 0);
}

void beep_on(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, BEEP_ON_PULSE);
}

void beep_off(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, BEEP_OFF_PULSE);
}

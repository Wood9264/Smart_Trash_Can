#include "servo.h"

void servo_init(void)
{
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, SERVO_OFF_PULSE);
}

void servo_on(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_ON_PULSE);
}

void servo_off(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_OFF_PULSE);
}

#include "servo.h"

void servo_on(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_ON_PULSE);
}

void servo_off(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_OFF_PULSE);
}

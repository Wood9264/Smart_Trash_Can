#include "servo.h"

/**
 * @brief  初始化舵机
 */
void servo_init(void)
{
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, SERVO_OFF_PULSE);
}

/**
 * @brief  开启桶盖
 */
void servo_on(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_ON_PULSE);
}

/**
 * @brief  关闭桶盖
 */
void servo_off(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, SERVO_OFF_PULSE);
}

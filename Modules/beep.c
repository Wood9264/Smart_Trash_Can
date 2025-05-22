#include "beep.h"

/**
 * @brief  蜂鸣器初始化
 */
void beep_init(void)
{
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1, 0);
}

/**
 * @brief  蜂鸣器开启
 */
void beep_on(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, BEEP_ON_PULSE);
}

/**
 * @brief  蜂鸣器关闭
 */
void beep_off(void)
{
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, BEEP_OFF_PULSE);
}

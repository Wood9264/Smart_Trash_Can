#include "ultrasound.h"

struct ultrasound_t ultrasound;

void ultrasound_trig_start(void)
{
    HAL_TIM_Base_Start(&htim9);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_2);
}

void ultrasound_trig_stop(void)
{
    HAL_TIM_PWM_Stop(&htim9, TIM_CHANNEL_2);
    HAL_TIM_Base_Stop(&htim9);
}

void ultrasound_echo_start(void)
{
    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
}

void ultrasound_echo_stop(void)
{
    HAL_TIM_IC_Stop_IT(&htim3, TIM_CHANNEL_1);
}

float ultrasound_get_distance(void)
{
    return ultrasound.distance;
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    static uint8_t rising_flag = 1;

    if (htim->Instance == TIM3)
    {
        if (rising_flag)
        {
            ultrasound.time[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
            rising_flag = 0;
        }
        else
        {
            ultrasound.time[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            ultrasound.time_diff = ultrasound.time[1] - ultrasound.time[0];
            if (ultrasound.time_diff < 0)
            {
                ultrasound.time_diff += 0xFFFF;
            }
            ultrasound.distance = (ultrasound.time_diff * 3.4) / 2; // cm
            rising_flag = 1;
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
        }
    }
}

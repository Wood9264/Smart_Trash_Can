#include "ultrasound.h"

struct ultrasound_t ultrasound;

/**
 * @brief  超声波传感器启动触发
 */
void ultrasound_trig_start(void)
{
    HAL_TIM_Base_Start(&htim9);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_2);
}

/**
 * @brief  超声波传感器停止触发
 */
void ultrasound_trig_stop(void)
{
    HAL_TIM_PWM_Stop(&htim9, TIM_CHANNEL_2);
    HAL_TIM_Base_Stop(&htim9);
}

/**
 * @brief  超声波传感器开启读取
 */
void ultrasound_echo_start(void)
{
    HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
}

/**
 * @brief  超声波传感器停止读取
 */
void ultrasound_echo_stop(void)
{
    HAL_TIM_IC_Stop_IT(&htim3, TIM_CHANNEL_1);
}

/**
 * @brief  获取超声波传感器测量的距离
 * @retval 距离值，单位为cm
 */
float ultrasound_get_distance(void)
{
    return ultrasound.distance;
}

/**
 * @brief  超声波传感器测量回调函数
 * @param  htim: 定时器句柄
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    static uint8_t rising_flag = 1;

    if (htim->Instance == TIM3)
    {
        if (rising_flag)
        {
            // 读取上升沿时间
            ultrasound.time[0] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
            rising_flag = 0;
        }
        else
        {
            // 读取下降沿时间
            ultrasound.time[1] = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            ultrasound.time_diff = ultrasound.time[1] - ultrasound.time[0];
            // 处理时间差，避免定时器溢出产生负值
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

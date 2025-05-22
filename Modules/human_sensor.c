#include "human_sensor.h"

/**
 * @brief  读取人体传感器状态
 * @param  None
 * @retval 1: 人体传感器检测到人体
 *         0: 人体传感器未检测到人体
 */
bool_t human_sensor_read(void)
{
    return HAL_GPIO_ReadPin(HUMAN_SENSOR_GPIO_Port, HUMAN_SENSOR_Pin);
}

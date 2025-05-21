#include "human_sensor.h"

uint8_t human_sensor_read(void)
{
    return HAL_GPIO_ReadPin(HUMAN_SENSOR_GPIO_Port, HUMAN_SENSOR_Pin);
}

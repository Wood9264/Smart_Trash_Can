#include "key.h"

/**
 * @brief  读取按键状态
 * @param  key: 按键编号
 */
bool_t key_read(uint8_t key)
{
    switch (key)
    {
    case 3:
        return !HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
    case 4:
        return !HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin);
    default:
        return 0;
    }
}

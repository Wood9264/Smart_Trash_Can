#include "led_task.h"

void led_task(void)
{
    led_on(1);
    HAL_Delay(1000);
    led_off(1);
    HAL_Delay(1000);
}

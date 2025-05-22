#include "echo.h"

void echo_task(void const *pvParameters)
{
    while (1)
    {
        vTaskDelay(10);
    }
}

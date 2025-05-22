#include "echo.h"

void echo_task(void const *pvParameters)
{
    communication_init();
    vTaskDelay(100);
    while (1)
    {
        send_echo();
        vTaskDelay(500);
    }
}

void send_echo(void)
{
    printf("[human state] ");
    if (get_human_sensor_state())
    {
        printf("human detected\n");
    }
    else
    {
        printf("no human detected\n");
    }

    printf("[can state] ");
    if (get_can_full_state())
    {
        printf("can full\n");
    }
    else
    {
        printf("can not full\n");
    }

    printf("[can open state] ");
    if (get_can_open_state())
    {
        printf("can open\n");
    }
    else
    {
        printf("can not open\n");
    }

    printf("\n");
}

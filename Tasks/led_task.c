#include "led_task.h"

struct led_task_t led_task_instance;

void led_task(void const *pvParameters)
{
    led_task_init();
    while (1)
    {
        led_task_update();
        led_task_control();
        vTaskDelay(10);
    }
}

void led_task_init(void)
{
    led_task_instance.state = LED_STATE_IDLE;
    led_task_instance.idle_mode = LED_IDLE_MODE_BREATHING;
}

void led_task_update()
{
    if (get_can_full_state())
    {
        led_task_instance.state = LED_STATE_FULL;
    }
    else if (get_can_open_state())
    {
        led_task_instance.state = LED_STATE_OPEN;
    }
    else
    {
        led_task_instance.state = LED_STATE_IDLE;
    }
}

void led_task_control()
{
    switch (led_task_instance.state)
    {
    case LED_STATE_IDLE:
        led_idle_mode_control();
        break;
    case LED_STATE_OPEN:
        led_open_mode_control();
        break;
    case LED_STATE_FULL:
        led_full_mode_control();
        break;
    default:
        break;
    }
}

void led_idle_mode_control(void)
{
    switch (led_task_instance.idle_mode)
    {
    case LED_IDLE_MODE_BREATHING:
        led_breathing_mode_control();
        break;
    case LED_IDLE_MODE_RUNNING:
        led_running_mode_control();
        break;
    case LED_IDLE_MODE_WATER:
        led_water_mode_control();
        break;
    default:
        break;
    }
}

void led_breathing_mode_control(void)
{
    static uint32_t time = 0;
    static float duty_cycle = 0.0f;

    time++;
    duty_cycle = sin(time / 5.0f) / 2.0f + 0.5f;
    led_on(1);
    led_on(2);
    led_on(3);
    led_on(4);
    vTaskDelay(5 * duty_cycle);
    led_off(1);
    led_off(2);
    led_off(3);
    led_off(4);
    vTaskDelay(5 * (1 - duty_cycle));
}

void led_running_mode_control(void)
{
    led_on(1);
    led_off(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_RUNNING_MODE_TIME);
    led_off(1);
    led_on(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_RUNNING_MODE_TIME);
    led_off(1);
    led_off(2);
    led_on(3);
    led_off(4);
    vTaskDelay(LED_RUNNING_MODE_TIME);
    led_off(1);
    led_off(2);
    led_off(3);
    led_on(4);
    vTaskDelay(LED_RUNNING_MODE_TIME);
}

void led_water_mode_control(void)
{
    led_on(1);
    led_off(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_WATER_MODE_TIME);
    led_on(1);
    led_on(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_WATER_MODE_TIME);
    led_on(1);
    led_on(2);
    led_on(3);
    led_off(4);
    vTaskDelay(LED_WATER_MODE_TIME);
    led_on(1);
    led_on(2);
    led_on(3);
    led_on(4);
    vTaskDelay(LED_WATER_MODE_TIME);
}

void led_open_mode_control(void)
{
    if (get_human_sensor_state())
    {
        led_off(1);
        led_on(2);
        led_off(3);
        led_off(4);
    }
    else
    {
        led_off(1);
        led_off(2);
        led_on(3);
        led_off(4);
    }
}

void led_full_mode_control(void)
{
    led_on(1);
    led_on(2);
    led_on(3);
    led_on(4);
    vTaskDelay(LED_FULL_MODE_TIME);
    led_off(1);
    led_off(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_FULL_MODE_TIME);
}

void set_idel_mode(led_idle_mode_e mode)
{
    led_task_instance.idle_mode = mode;
}

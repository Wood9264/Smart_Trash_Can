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

/**
 * @brief  LED任务初始化
 */
void led_task_init(void)
{
    led_task_instance.state = LED_STATE_IDLE;
    led_task_instance.idle_mode = LED_IDLE_MODE_BREATHING;
}

/**
 * @brief  LED任务数据更新
 */
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

/**
 * @brief  LED任务控制
 */
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

/**
 * @brief  LED灯空闲模式控制
 */
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

/**
 * @brief  LED呼吸灯
 */
void led_breathing_mode_control(void)
{
    static uint32_t time = 0;
    static float duty_cycle = 0.0f; //占空比

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

/**
 * @brief  LED跑马灯
 */
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

/**
 * @brief  LED流水灯
 */
void led_water_mode_control(void)
{
    led_off(1);
    led_off(2);
    led_off(3);
    led_off(4);
    vTaskDelay(LED_WATER_MODE_TIME);
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

/**
 * @brief  LED灯开盖模式控制
 */
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

/**
 * @brief  LED灯满桶模式控制
 */
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

/**
 * @brief  设置LED灯的空闲模式
 * @param  mode: LED灯空闲模式
 */
void set_idel_mode(led_idle_mode_e mode)
{
    if (mode > LED_IDLE_MODE_WATER)
    {
        return;
    }
    led_task_instance.idle_mode = mode;
}

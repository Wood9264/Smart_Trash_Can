#include "trash_can_task.h"

struct trash_can_task_t trash_can_task_instance;

void trash_can_task(void const *pvParameters)
{
    trash_can_task_init();
    ultrasound_trig_start();
    ultrasound_echo_start();
    servo_init();
    beep_init();
    vTaskDelay(100);
    while (1)
    {
        trash_can_task_update();
        trash_can_task_control();
        vTaskDelay(10);
    }
}

/**
 * @brief  垃圾桶任务初始化
 */
void trash_can_task_init()
{
    trash_can_task_instance.should_can_open = 0;
    trash_can_task_instance.is_can_full = 0;
    trash_can_task_instance.if_human_detected = 0;
    trash_can_task_instance.junk_distance = 0;
}

/**
 * @brief  垃圾桶任务数据更新
 */
void trash_can_task_update()
{
    trash_can_task_instance.if_human_detected = human_sensor_read();
    trash_can_task_instance.junk_distance = ultrasound_get_distance();

    // 关盖时检测垃圾桶是否满
    if (trash_can_task_instance.junk_distance < CAN_FULL_DISTANCE && !trash_can_task_instance.should_can_open)
    {
        trash_can_task_instance.is_can_full = 1;
    }

    // 4号键清空垃圾桶
    if (key_read(4))
    {
        trash_can_task_instance.is_can_full = 0;
    }

    if (trash_can_task_instance.if_human_detected)
    {
        trash_can_task_instance.can_open_trigger_time = xTaskGetTickCount();
    }

    if (!trash_can_task_instance.is_can_full)
    {
        // 因人体传感器开盖时，延时一段时间后再关闭
        if ((xTaskGetTickCount() - trash_can_task_instance.can_open_trigger_time < CAN_OPEN_DELAY) || key_read(3))
        {
            trash_can_task_instance.should_can_open = 1;
        }
        else
        {
            trash_can_task_instance.should_can_open = 0;
        }
    }
    else
    {
        if (key_read(3))
        {
            trash_can_task_instance.should_can_open = 1;
        }
        else
        {
            trash_can_task_instance.should_can_open = 0;
        }
    }
}

/**
 * @brief  垃圾桶任务控制
 */
void trash_can_task_control()
{
    if (trash_can_task_instance.should_can_open)
    {
        servo_on();
    }
    else
    {
        servo_off();
    }

    if (trash_can_task_instance.is_can_full)
    {
        beep_on();
    }
    else
    {
        beep_off();
    }
}

/**
 * @brief  获取垃圾桶开盖状态
 * @return 1: 开盖
 *         0: 关盖
 */
bool_t get_can_open_state()
{
    return trash_can_task_instance.should_can_open;
}

/**
 * @brief  获取垃圾桶满桶状态
 * @return 1: 满桶
 *         0: 未满桶
 */
bool_t get_can_full_state()
{
    return trash_can_task_instance.is_can_full;
}

/**
 * @brief  人体传感器状态
 * @return 1: 检测到人体
 *         0: 未检测到人体
 */
bool_t get_human_sensor_state()
{
    return trash_can_task_instance.if_human_detected;
}

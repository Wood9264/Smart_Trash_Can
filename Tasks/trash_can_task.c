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

void trash_can_task_init()
{
    trash_can_task_instance.should_can_open = 0;
    trash_can_task_instance.is_can_full = 0;
    trash_can_task_instance.if_human_detected = 0;
    trash_can_task_instance.junk_distance = 0;
}

void trash_can_task_update()
{
    trash_can_task_instance.if_human_detected = human_sensor_read();
    trash_can_task_instance.junk_distance = ultrasound_get_distance();

    if (trash_can_task_instance.junk_distance < CAN_FULL_DISTANCE)
    {
        trash_can_task_instance.is_can_full = 1;
    }

    if(key_read(4))
    {
        trash_can_task_instance.is_can_full = 0;
    }

    if (!trash_can_task_instance.is_can_full)
    {
        if (trash_can_task_instance.if_human_detected || key_read(3))
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

bool_t get_can_open_state()
{
    return trash_can_task_instance.should_can_open;
}

bool_t get_can_full_state()
{
    return trash_can_task_instance.is_can_full;
}

bool_t get_human_sensor_state()
{
    return trash_can_task_instance.if_human_detected;
}

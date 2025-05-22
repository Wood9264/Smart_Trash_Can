#ifndef __TRASH_CAN_TASK_H__
#define __TRASH_CAN_TASK_H__

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "human_sensor.h"
#include "beep.h"
#include "servo.h"
#include "key.h"
#include "ultrasound.h"

#define CAN_FULL_DISTANCE 10
#define CAN_OPEN_DELAY 2000

struct trash_can_task_t
{
    bool_t should_can_open;
    bool_t is_can_full;

    bool_t if_human_detected;
    uint8_t junk_distance;

    uint32_t can_open_trigger_time;
};

void trash_can_task_update(void);
void trash_can_task_control(void);

extern struct trash_can_task_t trash_can_task_instance;
extern void trash_can_task_init(void);
extern void trash_can_task(void const *pvParameters);
extern void trash_can_task_control(void);
extern void trash_can_task_update(void);
extern bool_t get_can_full_state(void);
extern bool_t get_can_open_state(void);
extern bool_t get_human_sensor_state(void);

#endif

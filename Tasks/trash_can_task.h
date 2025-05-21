#ifndef __TRASH_CAN_TASK_H__
#define __TRASH_CAN_TASK_H__

#include "stm32f4xx.h"

#define HUMAN_SENSOR_PIN GPIO_Pin_8
#define HUMAN_SENSOR_PORT GPIOB

struct trash_can_task_t
{
    uint8_t should_can_open;
    uint8_t is_can_full;

    uint8_t if_human_detected;
    uint8_t junk_distance;
};

extern struct trash_can_task_t trash_can_task_instance;
extern void trash_can_task_init(void);
extern void trash_can_task(void);

#endif

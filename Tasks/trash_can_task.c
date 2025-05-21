#include "trash_can_task.h"

struct trash_can_task_t trash_can_task_instance;

void trash_can_task_init()
{
    trash_can_task_instance.should_can_open = 0;
    trash_can_task_instance.is_can_full = 0;
    trash_can_task_instance.if_human_detected = 0;
    trash_can_task_instance.junk_distance = 0;
}
uint8_t test = 0;
void trash_can_task()
{
    test = GPIO_ReadInputDataBit(HUMAN_SENSOR_PORT, HUMAN_SENSOR_PIN);
}

void human_sensor_init()
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStruct.GPIO_Pin = HUMAN_SENSOR_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(HUMAN_SENSOR_PORT, &GPIO_InitStruct);
}

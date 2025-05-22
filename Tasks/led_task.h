#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "trash_can_task.h"
#include <math.h>

#define LED_RUNNING_MODE_TIME 50
#define LED_WATER_MODE_TIME 50
#define LED_FULL_MODE_TIME 50

typedef enum
{
    LED_STATE_IDLE = 0,
    LED_STATE_OPEN,
    LED_STATE_FULL,
} led_state_e;

typedef enum
{
    //呼吸灯
    LED_IDLE_MODE_BREATHING = 0,
    //跑马灯
    LED_IDLE_MODE_RUNNING,
    //流水灯
    LED_IDLE_MODE_WATER,
} led_idle_mode_e;

struct led_task_t
{
    led_state_e state;
    led_idle_mode_e idle_mode;
};

extern struct led_task_t led_task_instance;
void led_task_init(void);
void led_task_update(void);
void led_task_control(void);
void led_idle_mode_control(void);
void led_open_mode_control(void);
void led_full_mode_control(void);
void led_breathing_mode_control(void);
void led_running_mode_control(void);
void led_water_mode_control(void);
extern void led_task(void const *pvParameters);
extern void led_task_update(void);

#endif

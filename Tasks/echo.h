#ifndef __ECHO_H__
#define __ECHO_H__

#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "communication.h"
#include "trash_can_task.h"

extern void echo_task(void const *pvParameters);
void send_echo(void);

#endif

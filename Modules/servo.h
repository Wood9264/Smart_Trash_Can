#ifndef __SERVO_H__
#define __SERVO_H__

#include "main.h"
#include "tim.h"

//桶盖开启的脉宽
#define SERVO_ON_PULSE 2500
//桶盖关闭的脉宽
#define SERVO_OFF_PULSE 1500

extern void servo_init(void);
extern void servo_on(void);
extern void servo_off(void);

#endif

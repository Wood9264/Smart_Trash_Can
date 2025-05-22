#ifndef __SERVO_H__
#define __SERVO_H__

#include "main.h"
#include "tim.h"

#define SERVO_ON_PULSE 2500
#define SERVO_OFF_PULSE 1500

extern void servo_init(void);
extern void servo_on(void);
extern void servo_off(void);

#endif

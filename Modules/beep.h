#ifndef __BEEP_H__
#define __BEEP_H__

#include "main.h"
#include "tim.h"

// 蜂鸣器开启的脉宽
#define BEEP_ON_PULSE 20
// 蜂鸣器关闭的脉宽
#define BEEP_OFF_PULSE 0

extern void beep_init(void);
extern void beep_on(void);
extern void beep_off(void);

#endif

#ifndef __BEEP_H__
#define __BEEP_H__

#include "main.h"
#include "tim.h"

#define BEEP_ON_PULSE 20
#define BEEP_OFF_PULSE 0

extern void beep_init(void);
extern void beep_on(void);
extern void beep_off(void);

#endif

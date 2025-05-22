#ifndef __ULTRASOUND_H__
#define __ULTRASOUND_H__

#include "main.h"
#include "tim.h"

struct ultrasound_t
{
    uint16_t time[2];
    int32_t time_diff;
    float distance;
};

extern void ultrasound_trig_start(void);
extern void ultrasound_trig_stop(void);
extern void ultrasound_echo_start(void);
extern void ultrasound_echo_stop(void);
extern float ultrasound_get_distance(void);

#endif

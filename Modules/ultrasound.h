#ifndef __ULTRASOUND_H__
#define __ULTRASOUND_H__

#include "main.h"
#include "tim.h"

struct ultrasound_t
{
    // 获取到的上升沿和下降沿时间
    uint16_t time[2];
    // 上升沿和下降沿的时间差
    int32_t time_diff;
    // 超声波传感器测量的距离
    float distance;
};

extern void ultrasound_trig_start(void);
extern void ultrasound_trig_stop(void);
extern void ultrasound_echo_start(void);
extern void ultrasound_echo_stop(void);
extern float ultrasound_get_distance(void);

#endif

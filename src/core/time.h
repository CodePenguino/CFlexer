#ifndef TIME_H
#define TIME_H

#include "../common/util.h"

extern float last_time, now_time, delta_time, FPSLimit;
extern u64 time_ticks;

void time_init();
void time_update();

#endif // TIME_H
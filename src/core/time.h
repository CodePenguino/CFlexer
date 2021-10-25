#ifndef TIME_H
#define TIME_H

extern float last_time, now_time, delta_time, FPSLimit;

void time_init();
void time_update();

#endif // TIME_H
#include "time.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

float last_time, now_time, delta_time, FPSLimit;
u64 time_ticks;

// Initializes FPSLimit
void time_init()
{
	time_ticks = 0.0f;
	FPSLimit = 120.0f;
}

// Updates time variables
void time_update()
{
	now_time = glfwGetTime();
	delta_time = now_time - last_time;

	last_time = now_time;

	time_ticks++;
}
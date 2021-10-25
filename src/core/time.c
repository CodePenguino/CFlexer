#include "time.h"
#include <GLFW/glfw3.h>

float last_time, now_time, delta_time, FPSLimit;

// Initializes FPSLimit
void time_init()
{
	FPSLimit = 120.0f;
}

// Updates time variables
void time_update()
{
	now_time = glfwGetTime();
	delta_time = now_time - last_time;

	last_time = now_time;
}
#include "time.h"
#include <GLFW/glfw3.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

float last_time, now_time, delta_time, FPSLimit;
u64 time_ticks;

// Initializes time variables
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

	// Prevents the program from freezing just in case
	if(FPSLimit != 0)
	{
		// While the FPS is larger than the FPS limit, put the thread to sleep
		while(glfwGetTime() < last_time + 1.0f / FPSLimit)
		{
			// Why is this function called different on Windows & Linux?!
			#ifdef _WIN32
			Sleep(0.005);
			#else
			sleep(0.005);
			#endif
		}
	}

	last_time = now_time;
	time_ticks++;
}

// Return the frame rate
float time_getFPS()
{
	return 1.0f / delta_time;
}
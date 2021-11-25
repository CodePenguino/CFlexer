#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include "../core/time.h"
#include "renderer.h"

// Callbackers!
static void resize_callback(GLFWwindow* winHandle, int width, int height)
{
	glViewport(0, 0, width, height);
	
	window.width = width;
	window.height = height;
	window.aspectRatio = (float)width/height;
	
	if(height < 1)
		window.aspectRatio = 0;
	
	renderer_update_camera_projection();
}

static void key_callback(GLFWwindow* winHandle, int key, int scancode, int action, int mods)
{
	if(key < 0)
	{
		return;
	}

	switch(action)
	{
		case GLFW_PRESS:
			keys[key] = true;
			break;

		case GLFW_RELEASE:
			keys[key] = false;
			break;

		default:
			break;
	}
}

static void mouse_callback(GLFWwindow* winHandle, int button, int action, int mods)
{
	if(button < 0)
	{
		return;
	}

	switch(action)
	{
		case GLFW_PRESS:
			mouseButtons[button] = true;
			break;

		case GLFW_RELEASE:
			mouseButtons[button] = false;
			break;

		default:
			break;
	}
}

void window_create(u32 width, u32 height, const char* title)
{
	window.width  = width;
	window.height = height;
	window.aspectRatio = (float)width/height;
	window.has_background_image = false;

	if(!glfwInit())
	{
		fprintf(stderr, "%s", "Error: GLFW failed to initialize!\n");
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	window.handle = glfwCreateWindow(window.width, window.height, title, NULL, NULL);
	
	if(!window.handle)
	{
		fprintf(stderr, "%s", "Error: GLFW failed to create a window!\n");
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window.handle);

	// Callback setups
	glfwSetFramebufferSizeCallback(window.handle, resize_callback);
	glfwSetKeyCallback(window.handle, key_callback);
	glfwSetMouseButtonCallback(window.handle, mouse_callback);

	window_center(window.handle);

	if(glewInit() != GLEW_OK)
	{
		fprintf(stderr, "%s", "Error: GLEW failed to initialize!\n");
		glfwDestroyWindow(window.handle);
		glfwTerminate();
		exit(1);
	}

	background_shader = shader_init("../res/shaders/background.vs", "../res/shaders/background.fs");

	time_init();
}

// Set window functions (important)
void window_setFunctions(void (*procInputs)(void), void (*upd)(void))
{
	processInputsCallback = procInputs;
	updateCallback = upd;
}

// Run the main loop for the window
void window_mainloop()
{
	// Error check. If we don't exit, we might get some "segmentation fault" errors on Linux
	if(!processInputsCallback)
	{
		fprintf(stderr, "%s", "Error: Process inputs function is invalid!\n");
		exit(1);
	}

	if(!updateCallback)
	{
		fprintf(stderr, "%s", "Error: Update function is invalid!\n");
		exit(1);
	}

	while(!glfwWindowShouldClose(window.handle))
	{
		time_update();
		processInputsCallback();
		glClear(GL_COLOR_BUFFER_BIT);

		if(window.has_background_image)
		{
			shader_use(background_shader);
			shader_set_float(background_shader, "windowAspectRatio", window.aspectRatio);
			sprite_draw(window.backgroundImage);
		}

		updateCallback();

		glfwSwapBuffers(window.handle);
		glfwPollEvents();
	}
}

// Close the window
void window_close()
{
	glfwSetWindowShouldClose(window.handle, GL_TRUE);
}

// Banish the window into the shadow realm
void window_destroy()
{
	shader_destroy(background_shader);
	if(window.has_background_image == true)
	{
		sprite_destroy(window.backgroundImage);
	}

	glfwDestroyWindow(window.handle);
	glfwTerminate();
}

// Set the background color in the RGBA format
void window_setBackgroundColorRGBA(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);
}

// Too lazy to put a 1.0f as the alpha value? Introducing this function, which does that for you!
void window_setBackgroundColorRGB(float r, float g, float b)
{
	glClearColor(r,g,b,1.0f);
}

// TODO: Make this render first without glDepthTest or something

// Set the background image
void window_setBackgroundImage(const char* filePath)
{
	window.has_background_image = true;
	window.backgroundImage = sprite_init_background(filePath);
}

// The code for this is copied from this github link: https://github.com/glfw/glfw/issues/310
void window_center(GLFWwindow* window)
{
	int window_x, window_y;
	glfwGetWindowPos(window, &window_x, &window_y);

	int window_width, window_height;
	glfwGetWindowSize(window, &window_width, &window_height);

	// Halve the window size and use it to adjust the window position to the center of the window
	window_width *= 0.5;
	window_height *= 0.5;

	window_x += window_width;
	window_y += window_height;

	// Get the list of monitors
	int monitors_length;
	GLFWmonitor **monitors = glfwGetMonitors(&monitors_length);

	if(monitors == NULL) {
		// Got no monitors back
		return;
	}

	// Figure out which monitor the window is in
	GLFWmonitor *owner = NULL;
	int owner_x, owner_y, owner_width, owner_height;

	for(int i = 0; i < monitors_length; i++) {
		// Get the monitor position
		int monitor_x, monitor_y;
		glfwGetMonitorPos(monitors[i], &monitor_x, &monitor_y);

		// Get the monitor size from its video mode
		int monitor_width, monitor_height;
		GLFWvidmode *monitor_vidmode = (GLFWvidmode*) glfwGetVideoMode(monitors[i]);

		if(monitor_vidmode == NULL) {
			// Video mode is required for width and height, so skip this monitor
			continue;

		} else {
			monitor_width = monitor_vidmode->width;
			monitor_height = monitor_vidmode->height;
		}

		// Set the owner to this monitor if the center of the window is within its bounding box
		if((window_x > monitor_x && window_x < (monitor_x + monitor_width)) && (window_y > monitor_y && window_y < (monitor_y + monitor_height))) {
			owner = monitors[i];

			owner_x = monitor_x;
			owner_y = monitor_y;

			owner_width = monitor_width;
			owner_height = monitor_height;
		}
	}

	if(owner != NULL) {
		// Set the window position to the center of the owner monitor
		glfwSetWindowPos(window, owner_x + (owner_width * 0.5) - window_width, owner_y + (owner_height * 0.5) - window_height);
	}
}

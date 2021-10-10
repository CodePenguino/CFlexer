#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include "../core/keyboard.hpp"

struct Window window;

// Callbackers!
static void resize_callback(GLFWwindow* winHandle, int width, int height)
{
	glViewport(0, 0, width, height);
	window.width = width;
	window.height = height;
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

void window_create(int width, int height, const char* title)
{
	window.width  = width;
	window.height = height;

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
		fprintf(stderr, "%s", "Error: GLFW failed to create window!\n");
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window.handle);

	// Callback setups
	glfwSetFramebufferSizeCallback(window.handle, resize_callback);
	glfwSetKeyCallback(window.handle, key_callback);

	if(glewInit() != GLEW_OK)
	{
		fprintf(stderr, "%s", "Error: GLEW failed to initialize!\n");
		glfwDestroyWindow(window.handle);
		glfwTerminate();
		exit(1);
	}
}

void window_mainloop()
{
	while(!glfwWindowShouldClose(window.handle))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);

		glfwSwapBuffers(window.handle);
		glfwPollEvents();
	}

	window_destroy();
}

float window_getAspectRatio()
{
	if(window.height <= 0)
	{
		window.height = 1;
	}

	return (float)window.width / window.height;
}

void window_close()
{
	glfwSetWindowShouldClose(window.handle, GL_TRUE);
}

void window_destroy()
{
	glfwDestroyWindow(window.handle);
	glfwTerminate();
}
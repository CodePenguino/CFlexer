#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Window
{
	GLFWwindow* handle;
	int width, height;

};

extern struct Window window;

void window_create(int width, int height, const char* title);
void window_mainloop();
float window_getAspectRatio();
void window_close();
void window_destroy();

#endif // WINDOW_H
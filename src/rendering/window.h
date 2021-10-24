#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../common/util.h"
#include "../core/keyboard.h"

typedef struct
{
	GLFWwindow* handle;
	u32 width, height;
} Window; Window window;

void window_center();
void window_create(u32 width, u32 height, const char* title);
void window_setFunctions(void (*procInputs)(void), void (*upd)(void));

void window_mainloop();
float window_getAspectRatio();
void window_close();
void window_destroy();

void window_setBackgroundColorRGBA(float r, float g, float b, float a);
void window_setBackgroundColorRGB(float r, float g, float b);

static void (*processInputsCallback)(void);
static void (*updateCallback)(void);

#endif // WINDOW_H

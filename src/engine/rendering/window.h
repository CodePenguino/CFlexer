#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../common/util.h"
#include "../ecs/components/sprite_component.h"
#include "shader.h"
#include <stdbool.h>

typedef struct
{
	GLFWwindow* handle;
	u32 width, height;
	float aspectRatio;
    
	bool has_background_image;
	SpriteComponent backgroundImage;
    
} Window; Window window;

static Shader background_shader;
static GLint winAspectRatioLocation;

void window_center();
void window_create(u16 width, u16 height, const char* title, bool isFullscreen);
void window_setFunctions(void (*procInputs)(void), void (*upd)(void));

void window_mainloop();
void window_close();
void window_destroy();

void window_setBackgroundColorRGBA(float r, float g, float b, float a);
void window_setBackgroundColorRGB(float r, float g, float b);
void window_setBackgroundImage(const char* filePath);

static void (*processInputsCallback)(void);
static void (*updateCallback)(void);

#endif // WINDOW_H

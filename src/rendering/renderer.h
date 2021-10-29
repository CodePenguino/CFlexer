#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"

typedef struct
{
	Shader shader;
} Renderer;

extern GLint transformID;

void draw_sprite(Renderer renderer, Sprite sprite);

#endif // RENDERER_H
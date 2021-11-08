#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"

static Shader render_shader;

void renderer_use_shader(Shader shader);
void draw_sprite(/*Shader shader, */Sprite sprite);

#endif // RENDERER_H
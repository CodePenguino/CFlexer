#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"

extern GLint transformID;

void draw_sprite(Shader shader, Sprite sprite);

#endif // RENDERER_H

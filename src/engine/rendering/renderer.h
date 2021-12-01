#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"
#include "../ecs/components/components.h"

extern float SPRITE_RESOLUTION;

static Shader render_shader;
// BE GONE YOU GLOBAL VARIABLE!
extern Camera2d camera;

void renderer_setup(float sprite_res);
void renderer_use_shader(Shader shader);
void draw_sprite(Sprite sprite);
void renderer_update_camera_projection();

#endif // RENDERER_H

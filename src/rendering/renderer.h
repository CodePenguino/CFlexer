#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"
#include "../ecs/components.h"

static Shader render_shader;
// BE GONE YOU GLOBAL VARIABLE!
extern Camera2d camera;

void renderer_setup();
void renderer_use_shader(Shader shader);
void draw_sprite(Sprite sprite);
void renderer_update_camera_projection();

#endif // RENDERER_H
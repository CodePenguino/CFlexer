#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "../ecs/components/sprite_component.h"
#include "../ecs/components/comp_data.h"

extern float SPRITE_RESOLUTION;

static Shader render_shader;
// BE GONE YOU GLOBAL VARIABLE!
extern Camera2dComponent camera;

void renderer_setup(float sprite_res);
void renderer_use_shader(Shader shader);
void draw_sprite(SpriteComponent* sprite, Transform2dComponent* transform);
void renderer_update_camera_projection();
#endif // RENDERER_H
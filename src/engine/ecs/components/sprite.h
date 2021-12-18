#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "../../common/util.h"
#include "transform.h"

SpriteComponent sprite_init(const char* texture_path);
SpriteComponent sprite_init_background(const char* texture_path);
void sprite_draw(SpriteComponent* self);
void sprite_destroy(SpriteComponent self);
void ecs_sprite_destroy(SpriteComponent* self);

#endif
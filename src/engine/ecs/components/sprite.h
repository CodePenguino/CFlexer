#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "../../common/util.h"
#include "transform.h"

SpriteComponent spriteComponent_init(const char* texture_path);
SpriteComponent spriteComponent_init_background(const char* texture_path);
void spriteComponent_draw(SpriteComponent* self);
// void sprite_destroy(SpriteComponent self);
void spriteComponent_destroy(SpriteComponent* self);

#endif
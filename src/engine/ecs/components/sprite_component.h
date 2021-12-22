#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "../../common/util.h"
#include "transform_component.h"

SpriteComponent spriteComponent_init(const char* texture_path);
SpriteComponent spriteComponent_init_background(const char* texture_path);
void spriteComponent_draw(SpriteComponent* self);
void spriteComponent_destroy(SpriteComponent* self);

#endif // SPRITE_COMPONENT_H
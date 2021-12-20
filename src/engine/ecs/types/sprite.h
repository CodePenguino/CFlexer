#ifndef SPRITE_H
#define SPRITE_H

#include "../../ecs/ecs.h"

Entity sprite_init(Entity ent, const char* image_path);
void sprite_destroy(Entity ent);
void sprite_draw(Entity ent);

#endif // SPRITE_H
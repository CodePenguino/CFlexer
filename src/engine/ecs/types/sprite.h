#ifndef SPRITE_H
#define SPRITE_H

#include "../../ecs/ecs.h"
#include "../components/comp_data.h"

typedef struct
{
    Entity entity;
    Transform2dComponent transform;
    SpriteComponent sprite;
} SpriteEntity;

SpriteEntity sprite_init(SpriteEntity ent, const char* image_path);
void sprite_destroy(SpriteEntity* ent);
void sprite_draw(SpriteEntity ent);
void sprite_draw_id(u32 ent_id);

#endif // SPRITE_H
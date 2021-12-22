#include "sprite.h"
#include "../components.h"
#include "../../rendering/renderer.h"

SpriteEntity sprite_init(SpriteEntity ent, const char* image_path)
{
	ent.entity = ecs_create();
    
    ent.transform = transform2d_init();
    ent.sprite    = spriteComponent_init(image_path);
    
	ecs_add(ent.entity.id, 0, &ent.transform);
	ecs_add(ent.entity.id, 1, &ent.sprite);
    
	return ent;
}

void sprite_destroy(SpriteEntity* ent)
{
	spriteComponent_destroy((SpriteComponent*)ecs_get(ent->entity.id, 1));
	ecs_kill(ent->entity.id);
}

void sprite_draw(SpriteEntity ent)
{
    // NOTE: The name of this function is not confusing at all ;)
	draw_sprite(&ent.sprite, &ent.transform);
}

void sprite_draw_id(u32 ent_id)
{
    // draw_sprite();
}
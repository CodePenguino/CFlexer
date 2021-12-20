#include "sprite.h"
#include "../components/comp_data.h"
#include "../components.h"
#include "../../rendering/renderer.h"
// #include <stdio.h>

Entity sprite_init(Entity ent, const char* image_path)
{
	ent = ecs_create();

	Transform2dComponent trans = transform2d_init();
	SpriteComponent      spr   = spriteComponent_init(image_path);

	ecs_add(ent, 0, &trans);
	ecs_add(ent, 1, &spr);

	return ent;
}

void sprite_destroy(Entity ent)
{
	spriteComponent_destroy((SpriteComponent*)ecs_get(ent, 1));
	ecs_kill(ent);
}

void sprite_draw(Entity ent)
{
	// Transform2dComponent* trans = (Transform2dComponent*)ecs_get(ent, 0);
	// SpriteComponent*      spr = (SpriteComponent*)ecs_get(ent, 1);

	Transform2dComponent* trans = (Transform2dComponent*)ecs_get(ent, 0);
	SpriteComponent*      spr   = (SpriteComponent*)ecs_get(ent, 1);

	draw_sprite(spr, trans);
}

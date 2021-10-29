#include "renderer.h"

GLint transformID;

void draw_sprite(Renderer renderer, Sprite sprite)
{
	shader_set_m4_wID(renderer.shader, transformID, transform2d_get_ortho(&sprite.transform));
	
	sprite_draw(sprite);
}
#include "renderer.h"
#include "../core/transform.h"

GLint transformID;

void draw_sprite(Shader shader, Sprite sprite)
{
	shader_set_m4_wID(shader, transformID, transform2d_get_ortho(&sprite.transform));
	
	sprite_draw(sprite);
}
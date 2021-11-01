#include "renderer.h"
#include "../core/transform.h"

void draw_sprite(Shader shader, Sprite sprite)
{
	shader_set_m4(shader, "transform", transform2d_get_ortho(&sprite.transform));

	sprite_draw(sprite);
}
#include "renderer.h"
#include "../core/transform.h"

void renderer_use_shader(Shader shader)
{
	render_shader = shader;
}

void draw_sprite(/*Shader shader,*/ Sprite sprite)
{
	shader_set_m4(render_shader, "transform", transform2d_get_ortho(&sprite.transform));

	sprite_draw(sprite);
}
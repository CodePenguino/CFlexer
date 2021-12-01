#include "game.h"
#include "../engine/core/time.h"
#include "../engine/core/math.h"
#include "../engine/core/keyboard.h"

f32 temp = 0;
f32 sinTemp;
f32 cosTemp;

static void processInputs()
{
	if(isKeyPressed(GLFW_KEY_W))
	{
		camera.transform.position.y += 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_S))
	{
		camera.transform.position.y -= 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_A))
	{
		camera.transform.position.x -= 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_D))
	{
		camera.transform.position.x += 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_LEFT))
	{
		camera.transform.rotation -= 40.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_RIGHT))
	{
		camera.transform.rotation += 40.0f * delta_time;
	}
}

static void update()
{
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	renderer_use_shader(spriteShader);

	spr1.transform.position = (v2) { cosTemp, sinTemp/2.5f };
	spr1.transform.scale = (v2) { 0.5f, 0.5f };

	spr2.transform.rotation = transform2d_rotate_to_point(spr1.transform.position);

	draw_sprite(spr1);
	draw_sprite(spr2);
}

void game_start()
{
	window_create(1024, 768, "It's a window!", false);
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);

	renderer_setup(360);

	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");
	spr1 = sprite_init("../res/images/Placeholder.png");
	spr2 = sprite_init("../res/images/Cross.png");

	game_loop();
	game_stop();
}

void game_stop()
{
	shader_destroy(spriteShader);
	sprite_destroy(spr1);
	sprite_destroy(spr2);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}

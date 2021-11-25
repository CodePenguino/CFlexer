#include "game.h"
#include "../engine/core/time.h"
#include "../engine/core/math.h"

f32 temp = 0;
f32 sinTemp;
f32 cosTemp;

static void processInputs()
{
	if(isKeyPressed(GLFW_KEY_UP) || isKeyPressed(GLFW_KEY_W))
	{
		camera.transform.position.y += 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_DOWN) || isKeyPressed(GLFW_KEY_S))
	{
		camera.transform.position.y -= 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_LEFT) || isKeyPressed(GLFW_KEY_A))
	{
		camera.transform.position.x -= 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_RIGHT) || isKeyPressed(GLFW_KEY_D))
	{
		camera.transform.position.x += 1.0f * delta_time;
	}
}

static void update()
{
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	renderer_use_shader(spriteShader);

	spr1.transform.position = (v2) { sinTemp, cosTemp };
	spr2.transform.rotation = sinTemp * 90.0f;
	spr2.transform.scale = (v2) { cosTemp, cosTemp };

	draw_sprite(spr1);
	draw_sprite(spr2);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);

	renderer_setup();

	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");
	spr1 = sprite_init("../res/images/Placeholder.png");
	spr2 = sprite_init("../res/images/workInProgress.png");

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

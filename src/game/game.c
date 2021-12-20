#include "game.h"
#include "../engine/core/time.h"
#include "../engine/core/math.h"
#include "../engine/core/keyboard.h"
#include "../engine/ecs/types/sprite.h"
#include <stdlib.h>

void system_draw();

f32 temp = 0;
f32 sinTemp;
f32 cosTemp;

static void processInputs()
{
	// ALL HAIL IF STATEMENTS!
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

	/*if(isKeyPressed(GLFW_KEY_LEFT))
	{
		camera.transform.rotation -= 40.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_RIGHT))
	{
		camera.transform.rotation += 40.0f * delta_time;
	}*/	
}

static void update()
{
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	renderer_use_shader(spriteShader);

	system_draw();
}

void system_draw()
{
	sprite_draw(ent1);
	sprite_draw(ent2);
}

void game_start()
{
	window_create(1024, 768, "It's a window!", false);
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);

	renderer_setup(360);

	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");

	ecs_init(4, sizeof(Transform2dComponent), sizeof(Transform3dComponent), 
	sizeof(Camera2dComponent), sizeof(SpriteComponent));

	ent1 = sprite_init(ent1, "../res/images/Placeholder.png");
	ent2 = sprite_init(ent2, "../res/images/Cross.png");

	game_loop();
	game_stop();
}

void game_stop()
{
	sprite_destroy(ent1);
	sprite_destroy(ent2);

	ecs_free();

	shader_destroy(spriteShader);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}

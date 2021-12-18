#include "game.h"
#include "../engine/core/time.h"
#include "../engine/core/math.h"
#include "../engine/core/keyboard.h"
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

	// spr1.transform.position = (v2) { cosTemp, sinTemp };
	// spr1.transform.scale = (v2) { 0.5f, 0.5f };

	// spr2.transform.rotation = transform2d_rotate_to_point(spr1.transform.position);

	// draw_sprite(&spr1, &spr1_trans);
	// draw_sprite(&spr2, &spr2_trans);
}

void system_draw()
{
	// printf("%d\n", ent1.id);
	Transform2dComponent* pos = (Transform2dComponent*)ecs_get(0, 0);
	SpriteComponent*      spr = (SpriteComponent*)ecs_get(0, 1);

	draw_sprite(spr, pos);
}

void game_start()
{
	window_create(1024, 768, "It's a window!", false);
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);

	renderer_setup(360);

	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");

	// spr1 = sprite_init("../res/images/Placeholder.png");
	// spr2 = sprite_init("../res/images/Cross.png");

	ecs_init(4, sizeof(Transform2dComponent), sizeof(Transform3dComponent), 
	sizeof(Camera2dComponent), sizeof(SpriteComponent));

	ent1 = ecs_create();

	Transform2dComponent trans;

	// FIXME: Reset the transform automatically
	trans.position.x = 0.0f;
	trans.position.y = 0.0f;
	trans.rotation = 0.0f;
	trans.scale.x = 1.0f;
	trans.scale.y = 1.0f;

	SpriteComponent spr = sprite_init("../res/images/Placeholder.png");

	ecs_add(ent1.id, 0, &trans);
	ecs_add(ent1.id, 1, &spr);

	game_loop();
	game_stop();
}

void game_stop()
{
	ecs_kill(ent1.id);
	ecs_sprite_destroy(ecs_get(ent1.id, 3));

	ecs_free();

	// sprite_destroy(spr1); 
	// sprite_destroy(spr2); 

	shader_destroy(spriteShader);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}
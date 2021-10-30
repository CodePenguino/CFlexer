#include "game.h"
#include "../core/time.h"
#include "../core/math.h"

float temp = 0.0f;

float sinTemp;
float cosTemp;

static void processInputs()
{
	if(isKeyPressed(GLFW_KEY_UP))
	{
		sprite.transform.scale.y += 1.0f * delta_time;
	}

	if(isKeyPressed(GLFW_KEY_DOWN))
	{
		sprite.transform.scale.y -= 1.0f * delta_time;
	}
}

static void update()
{
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	sprite.transform.position.x = sinTemp;
	sprite.transform.rotation = -sinTemp * 180;

	sprite2.transform.position.y = -cosTemp;
	sprite2.transform.rotation = temp * 90;

	draw_sprite(shader, sprite);
	draw_sprite(shader, sprite2);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);
	window_setFunctions(processInputs, update);

	shader = shader_init("../res/shader.vs", "../res/shader.fs");
	sprite = sprite_init("../res/Placeholder.png");
	sprite2 = sprite_init("../res/workInProgress.png");

	shader_bind(shader);

	game_loop();
	game_stop();
}

void game_stop()
{
	shader_destroy(shader);
	sprite_destroy(sprite);
	sprite_destroy(sprite2);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}
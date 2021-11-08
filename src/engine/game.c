#include "game.h"
#include "../core/time.h"
#include "../core/math.h"

float temp = 0.0f;
float sinTemp;
float cosTemp;

static void processInputs()
{

}

static void update()
{
	// Set up temporary variables
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	shader_use(spriteShader);

	sprite.transform.position.x = sinTemp;
	sprite.transform.rotation = -sinTemp * 180;

	sprite2.transform.position.y = -cosTemp;
	sprite2.transform.rotation = temp * 90;

	draw_sprite(sprite);
	draw_sprite(sprite2);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);

	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");
	sprite = sprite_init("../res/images/Placeholder.png");
	sprite2 = sprite_init("../res/images/workInProgress.png");

	renderer_use_shader(spriteShader);

	game_loop();
	game_stop();
}

void game_stop()
{
	shader_destroy(spriteShader);
	sprite_destroy(sprite);
	sprite_destroy(sprite2);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}

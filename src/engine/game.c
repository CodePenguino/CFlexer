#include "game.h"
#include <cglm/cglm.h>
#include <time.h>
#include <math.h>

vec3 test = {0.0f, 0.15f, 1.0f};

static void processInputs()
{

}

static void update()
{
	print_vec3(test);

	sprite_drawP(&sprite);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);
	shader = shader_init("../res/shader.vs", "../res/shader.fs");

	sprite = sprite_init("../res/imgTest.png");

	// IMPORTANT! Sets input and update functions
	window_setFunctions(processInputs, update);

	shader_bind(shader);

	game_loop();
	game_stop();
}

void game_stop()
{
	shader_destroy(shader);
	sprite_destroy(sprite);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}
#include "game.h"
#include "../core/time.h"

// GLint MatrixID;

v2 vector = {0.0f, 1.0f};

static void processInputs()
{

}

static void update()
{
	// Calculate and print the FPS
	
	// printf("FPS: %f\n", 1.0f / delta_time);

	// This is boring.
	// TODO: Add transforms and MVPs so this is not boring.

	sprite_draw(sprite);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);
	shader = shader_init("../res/shader.vs", "../res/shader.fs");

	sprite = sprite_init("../res/workInProgress.png");

	// IMPORTANT! Sets input and update functions
	window_setFunctions(processInputs, update);

	shader_bind(shader);

	// MatrixID = glGetUniformLocation(shader.id, "MVP");

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
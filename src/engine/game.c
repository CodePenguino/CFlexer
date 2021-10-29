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
	temp += delta_time;
	sinTemp = sinf(temp);
	cosTemp = cosf(temp);

	transform.position = (v2){ sinTemp, 0.0f };
	transform.scale = (v2){ cosTemp, cosTemp };

	shader_set_m4(shader, "transform", transform2d_get_ortho(transform));

	sprite_draw(sprite);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);
	// IMPORTANT! Sets input and update functions
	window_setFunctions(processInputs, update);
	shader = shader_init("../res/shader.vs", "../res/shader.fs");
	sprite = sprite_init(/*NULL*/"../res/workInProgress.png");
	
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

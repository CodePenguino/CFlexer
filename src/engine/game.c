#include "game.h"
/*#include <cglm/cglm.h>
#include <cglm/struct.h>
#include <time.h>*/

GLuint MatrixID;

v2 vector = {0.0f, 1.0f};

static void processInputs()
{

}

static void update()
{
	/*mat4s Projection = glms_perspective(glm_rad(45.0f), window_getAspectRatio(), 0.1f, 100.0f);
	mat4s View = glms_lookat((vec3s){4,3,3}, (vec3s){0,0,0}, (vec3s){0,1,0});
	mat4s Model = (mat4s){1.0f};

	mat4s mvp = glms_mat4_mul(Projection, View);
	mvp = glms_mat4_mul(mvp, Model);

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);*/

	// benchmark_func(vec2_printBP(&vector));

	sprite_drawP(&sprite);
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

	MatrixID = glGetUniformLocation(shader.id, "MVP");

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
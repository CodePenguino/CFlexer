#include "game.h"
#include <stdio.h>

static void processInputs()
{

}

static void update()
{
	/*glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
*/
	sprite_draw(&sprite);
}

void game_start()
{
	window_create(1024, 768, "It's a window!");
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);

	GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};
	GLuint indices[] = {
		0, 1, 2
	};
	
	sprite_init(&sprite, vertices, sizeof(vertices));

	// IMPORTANT! Sets input and update functions
	window_setFunctions(processInputs, update);

	game_loop();
	game_stop();
}

void game_stop()
{
	/*glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);*/

	sprite_destroy(&sprite);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}

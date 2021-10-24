#include "game.hpp"

static void processInputs()
{

}

static void update()
{
	
}

void startGame()
{
	window_create(1024, 768, "It's a window!");
	window_setFunctions(processInputs, update);
	window_setBackgroundColorRGB(0.0f, 0.15f, 0.3f);

	loopGame();
	stopGame();
}

void loopGame()
{
	window_mainloop();
}

void stopGame()
{
	window_destroy();
}
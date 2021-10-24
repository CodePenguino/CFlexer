#include "keyboard.h"

bool isKeyPressed(int keyCode)
{
	if(keyCode > MAX_KEYS)
	{
		fprintf(stderr, "Keyboard error: keyCode is %d, which is higher than maximum! Increase MAX_KEYS maybe?\n",
				keyCode);
	}

	if(Input.keys[keyCode])
	{
		return true;
	}

	return false;
}

bool isMouseButtonPressed(int button)
{
	if(button > MAX_BUTTONS)
	{
		fprintf(stderr, "Mouse input error: button is %d, which is higher than maximum! Increase MAX_BUTTONS maybe?\n",
				button);
	}

	if(Input.mouseButtons[button])
	{
		return true;
	}

	return false;
}

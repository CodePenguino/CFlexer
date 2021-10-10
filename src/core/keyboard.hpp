#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_KEYS	512
#define MAX_BUTTONS 32

bool keys[MAX_KEYS] = { false };
bool mouseButtons[MAX_BUTTONS] = { false };
double mousePosX, mousePosY;

bool isKeyPressed(int keyCode)
{
	if(keyCode > MAX_KEYS)
	{
		fprintf(stderr, "%s", "Keyboard error: keyCode is %d, which is higher than maximum! Increase MAX_KEYS maybe?\n",
				keyCode);
	}

	if(keys[keyCode])
	{
		return true;
	}

	return false;
}

bool isMouseButtonPressed(int button)
{
	
}

#endif
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_KEYS	512
#define MAX_BUTTONS 20

/*struct InputControl
{
	bool keys[MAX_KEYS];
	bool mouseButtons[MAX_BUTTONS];
	double mousePosX, mousePosY;
}; struct InputControl Input;*/

extern bool keys[MAX_KEYS];
extern bool mouseButtons[MAX_BUTTONS];

bool isKeyPressed(int keyCode);
bool isMouseButtonPressed(int button);

#endif

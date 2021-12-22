#include "keyboard.h"

bool keys[MAX_KEYS];
bool mouseButtons[MAX_BUTTONS];
v2 mouse_position;
v2 mouse_delta;

void keyboard_init()
{
    mouse_position = (v2) { 0.0f, 0.0f };
    mouse_delta = (v2) { 0.0f, 0.0f };
}

bool isKeyPressed(int keyCode)
{
	if(keyCode > MAX_KEYS)
	{
		fprintf(stderr, "Keyboard error: keyCode is %d, which is higher than maximum! Increase MAX_KEYS maybe?\n",
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
	if(button > MAX_BUTTONS)
	{
		fprintf(stderr, "Mouse input error: button is %d, which is higher than maximum! Increase MAX_BUTTONS maybe?\n",
				button);
	}
    
	if(mouseButtons[button])
	{
		return true;
	}
    
	return false;
}
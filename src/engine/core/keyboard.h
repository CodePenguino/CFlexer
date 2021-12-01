#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <stdio.h>
#include "math.h"

#define MAX_KEYS	512
#define MAX_BUTTONS 20

extern bool keys[MAX_KEYS];
extern bool mouseButtons[MAX_BUTTONS];
extern v2 mouse_position;
extern v2 mouse_delta;

bool isKeyPressed(int keyCode);
bool isMouseButtonPressed(int button);

#endif

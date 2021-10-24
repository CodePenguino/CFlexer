#ifndef GAME_H
#define GAME_H

#include "../rendering/window.h"
#include "../rendering/mesh.h"
#include "../rendering/shader.h"

void game_start();
void game_stop();
void game_loop();

Shader shader;
Sprite sprite;

#endif

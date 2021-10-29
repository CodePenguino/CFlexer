#ifndef GAME_H
#define GAME_H

#include "../rendering/window.h"
#include "../rendering/mesh.h"
#include "../rendering/shader.h"
#include "../rendering/renderer.h"
#include "../core/transform.h"

void game_start();
void game_stop();
void game_loop();

Renderer renderer;
Sprite sprite;
Sprite sprite2;

#endif
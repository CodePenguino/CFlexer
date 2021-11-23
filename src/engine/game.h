#ifndef GAME_H
#define GAME_H

#include "../rendering/window.h"
#include "../rendering/renderer.h"
#include "../ecs/transform.h"
#include "../ecs/camera.h"

void game_start();
void game_stop();
void game_loop();

Shader spriteShader;
Sprite sprite;
Sprite sprite2;

#endif
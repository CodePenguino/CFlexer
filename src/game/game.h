#ifndef GAME_H
#define GAME_H

#include "../engine/rendering/window.h"
#include "../engine/rendering/renderer.h"
#include "../engine/ecs/transform.h"
#include "../engine/ecs/camera.h"

void game_start();
void game_stop();
void game_loop();

Shader spriteShader;
Sprite spr1;
Sprite spr2;

#endif
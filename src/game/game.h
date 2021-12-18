#ifndef GAME_H
#define GAME_H

#include "../engine/rendering/window.h"
#include "../engine/rendering/renderer.h"
#include "../engine/ecs/components.h"
#include "../engine/ecs/ecs.h"

#define MAX_ENTITIES 32

void game_start();
void game_stop();
void game_loop();

Shader spriteShader;

// Sprite spr1;
// Sprite spr2;

Entity ent1;
// Entity ent2;
// , spr2_trans;

// Entity ent1;
// Entity ent2;

#endif
#ifndef GAME_H
#define GAME_H

#include "../engine/rendering/window.h"
#include "../engine/rendering/renderer.h"
#include "../engine/ecs/components.h"
#include "../engine/ecs/ecs.h"

#define MAX_ENTITIES 2

void game_start();
void game_stop();
void game_loop();

Shader spriteShader;
Entity ent1;
Entity ent2;
// Entity* entities;

#endif // GAME_H
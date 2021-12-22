#ifndef GAME_H
#define GAME_H

#include "../engine/rendering/window.h"
#include "../engine/rendering/renderer.h"
#include "../engine/ecs/components.h"
#include "../engine/ecs/ecs.h"
#include "../engine/core/time.h"
#include "../engine/core/math.h"
#include "../engine/core/keyboard.h"
#include "../engine/ecs/types/sprite.h"

#define MAX_ENTITIES 2

void game_start();
void game_stop();
void game_loop();

Shader spriteShader;
SpriteEntity* entities;

#endif // GAME_H
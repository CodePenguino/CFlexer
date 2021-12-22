#include "game.h"
#include <stdlib.h>

f32 temp = 0;
f32 sinTemp;
f32 cosTemp;

static void processInputs()
{
	// ALL HAIL IF STATEMENTS!
	if(isKeyPressed(GLFW_KEY_W))
	{
		camera.transform.position.y += 1.0f * delta_time;
	}
    
	if(isKeyPressed(GLFW_KEY_S))
	{
		camera.transform.position.y -= 1.0f * delta_time;
	}
    
	if(isKeyPressed(GLFW_KEY_A))
	{
		camera.transform.position.x -= 1.0f * delta_time;
	}
    
	if(isKeyPressed(GLFW_KEY_D))
	{
		camera.transform.position.x += 1.0f * delta_time;
	}
    
	if(isKeyPressed(GLFW_KEY_LEFT))
	{
		camera.transform.rotation -= 40.0f * delta_time;
	}
    
	if(isKeyPressed(GLFW_KEY_RIGHT))
	{
		camera.transform.rotation += 40.0f * delta_time;
	}
}

static void update()
{
	temp += delta_time;
    
	renderer_use_shader(spriteShader);
    
    entities[0].transform.position = (v2) { cosf(temp), sinf(temp) };
    entities[1].transform.rotation = transform2d_rotate_to_point(v2_screen_to_view_space(mouse_position, &camera));
    
    sprite_draw(entities[0]);
    sprite_draw(entities[1]);
}

void game_start()
{
	window_create(1024, 768, "It's a window!", false);
	window_setBackgroundImage("../res/images/clouds.png");
	window_setFunctions(processInputs, update);
    keyboard_init();
    
	renderer_setup(360);
    
	spriteShader = shader_init("../res/shaders/sprite.vs", "../res/shaders/sprite.fs");
    
    entities = malloc(MAX_ENTITIES * sizeof(*entities));
    
	ecs_init(4, sizeof(Transform2dComponent), sizeof(Transform3dComponent), 
             sizeof(Camera2dComponent), sizeof(SpriteComponent));
    
    entities[0] = sprite_init(entities[0], "../res/images/Placeholder.png");
    entities[1] = sprite_init(entities[1], "../res/images/Cross.png");
    
    game_loop();
    game_stop();
}

void game_stop()
{
	sprite_destroy(&entities[0]);
	sprite_destroy(&entities[1]);
    
	ecs_free();
    
	shader_destroy(spriteShader);
	window_destroy();
}

void game_loop()
{
	window_mainloop();
}
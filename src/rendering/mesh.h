#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "../common/util.h"
#include "texture.h"
#include "../ecs/transform.h"

typedef struct
{	
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	Transform2d transform;
	Texture texture;
} Sprite;

Sprite sprite_init(const char* texture_path);
Sprite sprite_init_background(const char* texture_path);
void sprite_draw(Sprite self);
void sprite_destroy(Sprite self);

#endif

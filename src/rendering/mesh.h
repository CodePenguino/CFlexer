#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "../common/types.h"

struct Sprite
{	
	GLuint VAO;
	GLuint VBO;

	unsigned int drawCount;
};

void sprite_init(struct Sprite* self, GLfloat* vertices, unsigned int numVertices);
void sprite_draw(struct Sprite* self);
void sprite_destroy(struct Sprite* self);

struct Sprite sprite;

#endif

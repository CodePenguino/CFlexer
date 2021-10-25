#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include "../common/util.h"

typedef struct
{
	GLuint id;

	u16 width;
	u16 height;
} Texture;

void texture_init(Texture* self, const char* fileName);
void texture_bind(Texture* self, GLuint unit);
void texture_destroy(Texture* self);

#endif

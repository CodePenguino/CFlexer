#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

typedef struct
{
	GLuint id;
} Shader;

Shader shader_init(char* vertexFilePath, char* fragmentFilePath);
void shader_bind(Shader self);
void shader_destroy(Shader self);

#endif

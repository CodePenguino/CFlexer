#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <stdbool.h>
#include "../core/math.h"

/*typedef struct
{
	GLuint id;
} Shader;*/

typedef GLuint Shader;

// Shader shader_init(char* vertexFilePath, char* fragmentFilePath);
Shader shader_init(char* vertexFilePath, char* fragmentFilePath);
void shader_use(Shader self);
void shader_destroy(Shader self);

// Set functions for uniform variables
void shader_set_bool(Shader shader, const char* name, bool value);
void shader_set_int(Shader shader, const char* name, int value);
void shader_set_float(Shader shader, const char* name, float value);
void shader_set_v2(Shader shader, const char* name, v2 value);
void shader_set_v3(Shader shader, const char* name, v3 value);
void shader_set_v4(Shader shader, const char* name, v4 value);
void shader_set_m3(Shader shader, const char* name, m3 mat);
void shader_set_m4_wID(Shader shader, GLint ID, m4 mat);
void shader_set_m4(Shader shader, const char* name, m4 mat);

#endif

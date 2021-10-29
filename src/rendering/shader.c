#include "shader.h"
#include <stdio.h>
#include <stdbool.h>
#include "../common/util.h"
#include <stdlib.h>

static void shader_check_error(GLuint shader, GLuint flag, bool isProgram, const char* error_message);
static GLuint shader_create(char* text, GLenum shaderType);

Shader shader_init(char* vertexFilePath, char* fragmentFilePath)
{
	Shader self;

	self = glCreateProgram();

	GLuint vertexShader = shader_create(read_file(vertexFilePath), GL_VERTEX_SHADER);
	GLuint fragmentShader = shader_create(read_file(fragmentFilePath), GL_FRAGMENT_SHADER);

	glAttachShader(self, vertexShader);
	glAttachShader(self, fragmentShader);

	glLinkProgram(self);
	shader_check_error(self, GL_LINK_STATUS, true, "Error: Shader program linking failed");

	glValidateProgram(self);
	shader_check_error(self, GL_VALIDATE_STATUS, true, "Error: Shader program is invalid");

	glDetachShader(self, vertexShader);
	glDeleteShader(vertexShader);

	glDetachShader(self, fragmentShader);
	glDeleteShader(fragmentShader);

	return self;
}

void shader_destroy(Shader self)
{
	glDeleteProgram(self);
}

void shader_bind(Shader self)
{
	glUseProgram(self);
}

static GLuint shader_create(char* text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if(shader == GL_FALSE)
	{
		fprintf(stderr, "Error: Shader creation failed!\n");
	}

	const char* constText = (const char*)text;
	glShaderSource(shader, 1, &constText, NULL);
	glCompileShader(shader);
	
	shader_check_error(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	free(text);

	return shader;
}

static void shader_check_error(GLuint shader, GLuint flag, bool isProgram, const char* error_message)
{
	GLint success = 0;
	GLchar error[512] = { 0 };

	if(isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if(success == GL_FALSE)
	{
		if(isProgram)
			glGetProgramInfoLog(shader, 512, NULL, error);
		else
			glGetShaderInfoLog(shader, 512, NULL, error);

		fprintf(stderr, "%s: '%s'\n", error_message, error);
	}
}






void shader_set_bool(Shader shader, const char* name, bool value)
{
	glUniform1i(glGetUniformLocation(shader, name), (int)value);
}

void shader_set_int(Shader shader, const char* name, int value)
{
	glUniform1i(glGetUniformLocation(shader, name), value);
}

void shader_set_float(Shader shader, const char* name, float value)
{
	glUniform1f(glGetUniformLocation(shader, name), value);
}

void shader_set_v2(Shader shader, const char* name, v2 value)
{
	float vector2[2] = { value.x, value.y };

	glUniform2fv(glGetUniformLocation(shader, name), 1, &vector2[0]);
}

void shader_set_v3(Shader shader, const char* name, v3 value)
{
	float vector3[3] = { value.x, value.y, value.z };

	glUniform3fv(glGetUniformLocation(shader, name), 1, &vector3[0]);
}

void shader_set_v4(Shader shader, const char* name, v4 value)
{
	float vector4[4] = { value.x, value.y, value.z, value.w };

	glUniform4fv(glGetUniformLocation(shader, name), 1, &vector4[0]);
}

void shader_set_m3(Shader shader, const char* name, mat3s mat)
{
	glUniformMatrix3fv(glGetUniformLocation(shader, name), 1, GL_FALSE, &mat.raw[0][0]);
}

void shader_set_m4(Shader shader, const char* name, mat4s mat)
{
	glUniformMatrix4fv(glGetUniformLocation(shader, name), 1, GL_FALSE, &mat.raw[0][0]);
}
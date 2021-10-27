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

	self.id = glCreateProgram();

	GLuint vertexShader = shader_create(read_file(vertexFilePath), GL_VERTEX_SHADER);
	GLuint fragmentShader = shader_create(read_file(fragmentFilePath), GL_FRAGMENT_SHADER);

	glAttachShader(self.id, vertexShader);
	glAttachShader(self.id, fragmentShader);

	glLinkProgram(self.id);
	shader_check_error(self.id, GL_LINK_STATUS, true, "Error: Shader program linking failed");

	glValidateProgram(self.id);
	shader_check_error(self.id, GL_VALIDATE_STATUS, true, "Error: Shader program is invalid");

	glDetachShader(self.id, vertexShader);
	glDeleteShader(vertexShader);

	glDetachShader(self.id, fragmentShader);
	glDeleteShader(fragmentShader);

	return self;
}

void shader_destroy(Shader self)
{
	glDeleteProgram(self.id);
}

void shader_bind(Shader self)
{
	glUseProgram(self.id);
}

static GLuint shader_create(char* text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if(shader == GL_FALSE)
	{
		fprintf(stderr, "Error: Shader creation failed!");
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

		fprintf(stderr, "%s: '%s'", error_message, error);
	}
}

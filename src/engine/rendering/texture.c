#include "texture.h"
#include <stdio.h>
#include <assert.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Loads a texture in either RGB or RGBA format
void texture_init(Texture* self, const char* fileName)
{
	if(fileName == NULL) { fileName = "../res/Flexer_MISSING_TEXTURE.png"; }

	// OpenGL, why are you like this?!
	stbi_set_flip_vertically_on_load(true);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);

	if(!data) { fprintf(stderr, "Error: Failed to load image: %s\n", fileName); }

	self->width = width;
	self->height = height;

	glGenTextures(1, &self->id);
	glBindTexture(GL_TEXTURE_2D, self->id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);

	stbi_image_free(data);
}

// Binds/uses a texture with unit "unit"
void texture_bind(Texture* self, GLuint unit)
{
	assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, self->id);
}

// Banishes a texture to the shadow realm
void texture_destroy(Texture* self)
{
	glDeleteTextures(1, &self->id);
}

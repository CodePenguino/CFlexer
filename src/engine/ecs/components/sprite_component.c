#include "sprite_component.h"
#include <GL/glew.h>
#include "../../rendering/shader.h"
#include <stdio.h>
#include "../../rendering/renderer.h"
#include <assert.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../rendering/stb_image.h"

SpriteComponent spriteComponent_init(const char* texture_path)
{
	SpriteComponent self;

	// ------------------------------------------------------------
	// Load the sprite's texture
	if(texture_path == NULL) { texture_path = "../res/Flexer_MISSING_TEXTURE.png"; }

	stbi_set_flip_vertically_on_load(true);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);

	if(!data)
	{
		fprintf(stderr, "Error: Failed to load image: %s\n", texture_path);
		texture_path = "../res/Flexer_MISSING_TEXTURE.png";
		data = stbi_load("../res/Flexer_MISSING_TEXTURE.png", &width, &height, &nrChannels, 0);
	}

	// self.texture_width = width;
	// self.texture_height = height;

	glGenTextures(1, &self.texture_id);
	glBindTexture(GL_TEXTURE_2D, self.texture_id);

	// The image will wrap around repeating
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// No filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Tells OpenGL this is a 2d image, and also figures out whether this is in RGB or RGBA format
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);

	// Frees the image data
	stbi_image_free(data);
	// --------------------------------------------------------------

	// self.transform.position.x = 0.0f;
	// self.transform.position.y = 0.0f;

	// self.transform.rotation = 0.0f;

	// self.transform.scale.x = 1.0f;
	// self.transform.scale.y = 1.0f;

	// Figures out how big the sprite should show up relative to its size
	float scalerX = SPRITE_RESOLUTION * width;
	float scalerY = SPRITE_RESOLUTION * height;

	const GLfloat sprite_default_vertices[16] = {
		 scalerX,  scalerY,    1.0f, 1.0f,
		 scalerX, -scalerY,    1.0f, 0.0f,
		-scalerX, -scalerY,    0.0f, 0.0f,
		-scalerX,  scalerY,    0.0f, 1.0f
	};

	// Generate the buffers and the vertex array
	glGenVertexArrays(1, &self.VAO);
	glGenBuffers(1, &self.VBO);
	glGenBuffers(1, &self.EBO);

	// Bind dat VAO!
	glBindVertexArray(self.VAO);

	// Setup for VBO
	glBindBuffer(GL_ARRAY_BUFFER, self.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_default_vertices), sprite_default_vertices, GL_STATIC_DRAW);

	// Setup for EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sprite_default_indices), sprite_default_indices, GL_STATIC_DRAW);

	// Position attribute setup
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Texture attribute setup
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return self;
}

SpriteComponent spriteComponent_init_background(const char* texture_path)
{
	SpriteComponent self;

	// Load up a texture
	// texture_init(&self.texture, texture_path);

	// ------------------------------------------------------------
	if(texture_path == NULL) { texture_path = "../res/Flexer_MISSING_TEXTURE.png"; }

	stbi_set_flip_vertically_on_load(true);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);

	if(!data) { fprintf(stderr, "Error: Failed to load image: %s\n", texture_path); }

	// self.texture_width = width;
	// self.texture_height = height;

	glGenTextures(1, &self.texture_id);
	glBindTexture(GL_TEXTURE_2D, self.texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);

	stbi_image_free(data);
	// --------------------------------------------------------------

	// self.transform.position.x = 0.0f;
	// self.transform.position.y = 0.0f;
	// self.transform.scale.x = 1.0f;
	// self.transform.scale.y = 1.0f;

	const GLfloat sprite_verts[16] = {
		1.0f,  1.0f,     1.0f, 1.0f,
		1.0f, -1.0f,     1.0f, 0.0f,
	   -1.0f, -1.0f,     0.0f, 0.0f,
	   -1.0f,  1.0f,     0.0f, 1.0f
	};

	// Generate the buffers and the vertex array
	glGenVertexArrays(1, &self.VAO);
	glGenBuffers(1, &self.VBO);
	glGenBuffers(1, &self.EBO);
	
	// Bind that VAO!
	glBindVertexArray(self.VAO);

	// Setup for VBO
	glBindBuffer(GL_ARRAY_BUFFER, self.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_verts), sprite_verts, GL_STATIC_DRAW);
	
	// Setup for EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sprite_default_indices), sprite_default_indices, GL_STATIC_DRAW);

	// Position attribute setup
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Texture attribute setup
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return self;
}

void spriteComponent_draw(SpriteComponent* self)
{
	// assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, self->texture_id);

	glBindVertexArray(self->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

// Destroy a normal sprite
/*void sprite_destroy(SpriteComponent self)
{
	glDeleteTextures(1, &self.texture_id);

	glDeleteVertexArrays(1, &self.VAO);
	glDeleteBuffers(1, &self.VBO);
	glDeleteBuffers(1, &self.EBO);
}*/

/* NOTE: My microphone sucks pretty bad */

// Destroy a sprite with the ECS
void spriteComponent_destroy(SpriteComponent* self)
{
	glDeleteTextures(1, &self->texture_id);

	glDeleteVertexArrays(1, &self->VAO);
	glDeleteBuffers(1, &self->VBO);
	glDeleteBuffers(1, &self->EBO);
}
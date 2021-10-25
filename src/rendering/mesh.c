#include "mesh.h"

Sprite sprite_init(const char* texture_path)
{
	Sprite self;

	// Load up a texture
	texture_init(&self.texture, texture_path);

	// Calculate the number of indices
	// self->drawCount = sizeof(sprite_default_indices) / sizeof(GLuint);

	// Generate the buffers and the vertex array
	glGenVertexArrays(1, &self.VAO);
	glGenBuffers(1, &self.VBO);
	glGenBuffers(1, &self.EBO);
	
	// Bind that VAO!
	glBindVertexArray(self.VAO);

	// Setup for VBO
	glBindBuffer(GL_ARRAY_BUFFER, self.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_default_vertices), sprite_default_vertices, GL_STATIC_DRAW);
	
	// Setup for EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sprite_default_indices), sprite_default_indices, GL_STATIC_DRAW);

	// Position attribute setup
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Texture attribute setup
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return self;
}

/*void sprite_draw(Sprite* self)
{
	texture_bind(&self->texture, 0);

	glBindVertexArray(self->VAO);
	glDrawElements(GL_TRIANGLES, self->drawCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}*/

void sprite_draw(Sprite self)
{
	texture_bind(&self.texture, 0);

	glBindVertexArray(self.VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void sprite_drawP(Sprite* self)
{
	texture_bind(&self->texture, 0);

	glBindVertexArray(self->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void sprite_destroy(Sprite self)
{
	texture_destroy(&self.texture);

	glDeleteVertexArrays(1, &self.VAO);
	glDeleteBuffers(1, &self.VBO);
	glDeleteBuffers(1, &self.EBO);
}
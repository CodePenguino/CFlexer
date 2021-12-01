#include "mesh.h"
#include "shader.h"
#include <stdio.h>
#include "renderer.h"

Sprite sprite_init(const char* texture_path)
{
	Sprite self;

	// Load up a texture
	texture_init(&self.texture, texture_path);

	self.transform.position.x = 0.0f;
	self.transform.position.y = 0.0f;

	self.transform.rotation = 0.0f;

	self.transform.scale.x = 1.0f; // 0.0028f * self.texture.width;
	self.transform.scale.y = 1.0f; // 0.0028f * self.texture.height;

	float scalerX = SPRITE_RESOLUTION * self.texture.width;
	float scalerY = SPRITE_RESOLUTION * self.texture.height;

	const GLfloat sprite_default_vertices[16] = {
		 scalerX,  scalerY,    1.0f, 1.0f,
		 scalerX, -scalerY,    1.0f, 0.0f,
		-scalerX, -scalerY,    0.0f, 0.0f,
		-scalerX,  scalerY,    0.0f, 1.0f
	};

	// printf("%d, %d\n", self.texture.width, self.texture.height);

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

Sprite sprite_init_background(const char* texture_path)
{
	Sprite self;

	// Load up a texture
	texture_init(&self.texture, texture_path);

	self.transform.position.x = 0.0f;
	self.transform.position.y = 0.0f;
	self.transform.scale.x = 1.0f;
	self.transform.scale.y = 1.0f;

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

void sprite_draw(Sprite self)
{
	texture_bind(&self.texture, 0);

	glBindVertexArray(self.VAO);
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

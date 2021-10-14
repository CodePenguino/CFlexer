#include "mesh.h"
#include <stdio.h>

void sprite_init(struct Sprite* self, GLfloat* vertices, unsigned int numVertices)
{
	self->drawCount = numVertices / sizeof(GLfloat);

	glGenVertexArrays(1, &self->VAO);
	glGenBuffers(1, &self->VBO);
	
	glBindVertexArray(self->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
	glBufferData(GL_ARRAY_BUFFER, numVertices, vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void sprite_draw(struct Sprite* self)
{
	glBindVertexArray(self->VAO);

	glDrawArrays(GL_TRIANGLES, 0, self->drawCount);

	glBindVertexArray(0);
}

void sprite_destroy(struct Sprite* self)
{
	glDeleteVertexArrays(1, &self->VAO);
	glDeleteBuffers(1, &self->VBO);
}

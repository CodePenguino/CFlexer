#ifndef ECSCOMPONENTS_H
#define ECSCOMPONENTS_H

#include "../../common/util.h"
#include "../../core/math.h"

typedef struct
{
	v2 position;
	f32 rotation;
	v2 scale;
} Transform2dComponent;

typedef struct
{
	v3 position;
	// TODO: Implement quaternion based rotations, etc.
	v3 scale;
} Transform3dComponent;

typedef struct
{
	m4 projMat, viewMat;
	Transform2dComponent transform;
} Camera2dComponent;

typedef struct
{	
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint texture_id;
} SpriteComponent;

#endif // ECSCOMPONENTS_H
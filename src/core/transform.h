#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "math.h"
#include <cglm/struct.h>

#define TRANSFORM_WIDTH 10;
#define TRANSFORM_HEIGHT 10;

typedef struct
{
	v2 position;
	v2 scale;

	m4 modelMatrix;
} Transform2d;

m4 transform2d_get_mat(Transform2d transform);
m4 transform2d_get_ortho(Transform2d transform);
m4 transform2d_get_perspective(Transform2d transform);

typedef struct
{
	v3 position;
	v3 scale;
} Transform3d;

mat4s transform3d_get_mat(Transform3d transform);

#endif // TRANSFORM_H

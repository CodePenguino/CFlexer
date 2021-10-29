#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "math.h"

typedef struct
{
	v2 position;
	float rotation;
	v2 scale;

	m4 modelMatrix;
} Transform2d;

m4 transform2d_get_mat(Transform2d* transform);
m4 transform2d_get_ortho(Transform2d* transform);
m4 transform2d_get_perspective(Transform2d* transform);

typedef struct
{
	v3 position;
	v3 scale;
} Transform3d;

m4 transform3d_get_mat(Transform3d transform);

#endif // TRANSFORM_H

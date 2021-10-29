#ifndef M4_H
#define M4_H

// typedef float m4[4][4];

#include <cglm/struct.h>

/*typedef struct
{
	float m[4][4];
} m4;*/

typedef mat4s m4;

m4 m4_init_identity();
m4 m4_mul(m4 first, m4 second);
m4 m4_init_translation(float x, float y, float z);
m4 m4_init_scale(float x, float y, float z);

m4 m4_init_ortho(float left, float right, float bottom, float top, float zNear, float zFar);
m4 m4_init_perspective(float fov, float aspect, float zNear, float zFar);

#endif // M4_H

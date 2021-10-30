#ifndef M4_H
#define M4_H

#include "m3.h"

typedef struct
{
	float data[4][4];
} m4;

m4 m4_init_identity();
m4 m4_mul(m4 first, m4 second);
m4 m4_init_translation(m4 transMat, float x, float y, float z);
m4 m4_init_rotation(m4 transMat, float rot);
m4 m4_init_scale(m4 transMat, float x, float y, float z);

m4 m4_init_ortho(float left, float right, float bottom, float top, float zNear, float zFar);
m4 m4_init_perspective(float fov, float aspect, float zNear, float zFar);

m4 m3_to_m4(m3 tmat);

#endif // M4_H

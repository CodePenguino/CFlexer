#ifndef M4_H
#define M4_H

#include "m3.h"

typedef float mat4x4[4][4];

typedef struct m4
{
	mat4x4 data;
} m4;

#define m4_identity_const {{1.0f, 0.0f, 0.0f, 0.0f},\
                           {0.0f, 1.0f, 0.0f, 0.0f},\
                           {0.0f, 0.0f, 1.0f, 0.0f},\
                           {0.0f, 0.0f, 0.0f, 1.0f}}

#define m4_zero_const    {{0.0f, 0.0f, 0.0f, 0.0f},\
                          {0.0f, 0.0f, 0.0f, 0.0f},\
                          {0.0f, 0.0f, 0.0f, 0.0f},\
                          {0.0f, 0.0f, 0.0f, 0.0f}}

// #define m4_identity ((mat4x4)m4_identity_const)
// #define m4_zero (m4_init_zero)

m4 m4_set_identity();
m4 m4_mul(m4 first, m4 second);
m4 m4_translate(m4 transMat, float x, float y, float z);
m4 m4_rotate(m4 transMat, float rot);
m4 m4_scale(m4 transMat, float x, float y, float z);

m4 m4_ortho(float l, float r, float b, float t, float n, float f);
m4 m4_perspective(float fov, float aspect, float zNear, float zFar);

m4 m3_to_m4(m3 tmat);

#endif // M4_H

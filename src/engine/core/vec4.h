#ifndef VEC4_H
#define VEC4_H

#include "vec3.h"

typedef struct
{
	float x, y, z, w;
} v4;

float v4_length(v4 vec4);
v4 v4_normalize(v4 vec4);
v4 v4_conjugate(v4 vec4);
v4 v4_mul(v4 first, v4 second);
v4 v4_mul_v3(v4 vec4, v3 vec3);

v4 v4_add(v4 first, v4 second);
v4 v4_sub(v4 first, v4 second);
v4 v4_mulNum(v4 vec4, float number);

#endif // VEC4_H
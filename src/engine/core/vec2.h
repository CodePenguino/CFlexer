#ifndef VEC2_H
#define VEC2_H

#include "../common/util.h"
#include "m4.h"

typedef struct
{
	float x, y;
} v2;

// typedef float v2[2];

// v2 v2(float x, float y);

f32 v2_length(v2 vec2);
f32 v2_dot(v2 first, v2 second);
v2 v2_normalize(v2 dest);
v2 v2_rotate(v2 vec2, float angle);

v2 v2_add(v2 first, v2 second);
v2 v2_add_f32(v2 vec2, f32 number);
v2 v2_sub(v2 first, v2 second);
v2 v2_sub_f32(v2 vec2, f32 number);
v2 v2_mul(v2 first, v2 second);
v2 v2_mul_f32(v2 vec2, f32 number);
v2 v2_div(v2 first, v2 second);
v2 v2_div_f32(v2 vec2, f32 number);

v2 v2_inverse(v2 vec2);

#endif // VEC2_H
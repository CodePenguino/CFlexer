#ifndef VEC2_H
#define VEC2_H

#include "../common/util.h"

typedef struct
{
	float x, y;
} v2;

float v2_length(v2 vec2);
float v2_dot(v2 first, v2 second);
v2 v2_normalize(v2 vec2);
v2 v2_rotate(v2 vec2, float angle);

v2 v2_add(v2 first, v2 second);
v2 v2_add_f32(v2 vec2, f32 number);
v2 v2_sub(v2 first, v2 second);
v2 v2_sub_f32(v2 vec3, f32 number);
v2 v2_mul(v2 first, v2 second);
v2 v2_mul_f32(v2 vec3, f32 number);
v2 v2_div(v2 first, v2 second);
v2 v2_div_f32(v2 vec3, f32 number);

#endif // VEC2_H

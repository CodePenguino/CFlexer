#ifndef VEC2_H
#define VEC2_H

typedef struct
{
	float x, y;
} v2;

float v2_length(v2 vec2);
float v2_dot(v2 first, v2 second);
v2 v2_normalize(v2 vec2);
v2 v2_rotate(v2 vec2, float angle);

v2 v2_add(v2 first, v2 second);
v2 v2_addNum(v2 vec2, float number);
v2 v2_sub(v2 first, v2 second);
v2 v2_subNum(v2 vec3, float number);
v2 v2_mul(v2 first, v2 second);
v2 v2_mulNum(v2 vec3, float number);
v2 v2_div(v2 first, v2 second);
v2 v2_divNum(v2 vec3, float number);

#endif // VEC2_H
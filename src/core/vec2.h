#ifndef VEC2_H
#define VEC2_H

typedef struct
{
	float x, y;
} v2;

float vec2_length(v2 vec2);
float vec2_dot(v2 first, v2 second);
v2 vec2_normalize(v2 vec2);
v2 vec2_rotate(v2 vec2, float angle);

v2 vec2_add(v2 first, v2 second);
v2 vec2_addNum(float number);
v2 vec2_sub(v2 first, v2 second);
v2 vec2_subNum(float number);
v2 vec2_mul(v2 first, v2 second);
v2 vec2_mulNum(float number);
v2 vec2_div(v2 first, v2 second);
v2 vec2_divNum(float number);

#endif // VEC2_H
#ifndef VEC3_H
#define VEC3_H

// Guess what this does!
typedef struct
{
	float x, y, z;
} v3;

float v3_length(v3 vec3);
float v3_dot(v3 first, v3 second);
v3 v3_cross(v3 first, v3 second);
v3 v3_normalize(v3 vec3);
void v3_rotate(v3 vec3);

v3 v3_add(v3 first, v3 second);
v3 v3_addNum(v3 vec3, float number);
v3 v3_sub(v3 first, v3 second);
v3 v3_subNum(v3 vec3, float number);
v3 v3_mul(v3 first, v3 second);
v3 v3_mulNum(v3 vec3, float number);
v3 v3_div(v3 first, v3 second);
v3 v3_divNum(v3 vec3, float number);

#endif // VEC3_H
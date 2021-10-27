#ifndef VEC3_H
#define VEC3_H

// Guess what this does!
typedef struct
{
	float x, y, z;
} v3;

float vec3_length(v3 vec3);
float vec3_dot(v3 first, v3 second);
v3 vec3_cross(v3 first, v3 second);
v3 vec3_normalize(v3 vec3);
void vec3_rotate(v3 vec3);

v3 vec3_add(v3 first, v3 second);
v3 vec3_addNum(float number);
v3 vec3_sub(v3 first, v3 second);
v3 vec3_subNum(float number);
v3 vec3_mul(v3 first, v3 second);
v3 vec3_mulNum(float number);
v3 vec3_div(v3 first, v3 second);
v3 vec3_divNum(float number);

#endif // VEC3_H
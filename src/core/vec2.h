#ifndef VEC2_H
#define VEC2_H

typedef struct
{
	float x, y;
} v2;

float vec2_length(v2 vec2);
float vec2_dot(v2 first, v2 second);
v2 vec2_normalize(v2 vec2);
void vec2_rotate(v2 vec2);

/*v2 vec2_add(v2 first, v2 second);
v2 vec2_add(float number);*/

#endif // VEC2_H
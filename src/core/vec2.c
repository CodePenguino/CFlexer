#include "vec2.h"

#include <math.h>
#include <stdio.h>

float vec2_length(v2 vec2)
{
	return sqrtf(vec2.x*vec2.x + vec2.y*vec2.y);
}

float vec2_dot(v2 first, v2 second)
{
	return first.x * second.x + first.y * second.y;
}

v2 vec2_normalize(v2 vec2)
{
	float length = vec2_length(vec2);

	vec2.x /= length;
	vec2.y /= length;

	return vec2;
}

void vec2_rotate(v2 vec2)
{
	return;
}

// ---------------------------------

/*v2 vec2_add(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x + second.x;
	vec.y = first.y + second.y;

	return vec;
}

v2 vec2_add(float number)
{
	v2 vec;

	vec.x += number;
	vec.y += number;

	return vec;
}*/
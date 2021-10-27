#include "vec2.h"

#include "../common/util.h"
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

v2 vec2_rotate(v2 vec2, float angle)
{
	v2 vec;

	float radianValue = degrees_to_radians(angle);
	float cosine = cosf(radianValue);
	float sine = sinf(radianValue);

	vec.x = vec.x * cosine - vec.y * sine;
	vec.y = vec.x * sine + vec.y * cosine;

	return vec;
}

// ---------------------------------

v2 vec2_add(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x + second.x;
	vec.y = first.y + second.y;

	return vec;
}

v2 vec2_addNum(float number)
{
	v2 vec;

	vec.x += number;
	vec.y += number;

	return vec;
}

v2 vec2_sub(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x - second.x;
	vec.y = first.y - second.y;

	return vec;
}

v2 vec2_subNum(float number)
{
	v2 vec;

	vec.x -= number;
	vec.y -= number;

	return vec;
}

v2 vec2_mul(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x * second.x;
	vec.y = first.y * second.y;

	return vec;
}

v2 vec2_mulNum(float number)
{
	v2 vec;

	vec.x *= number;
	vec.y *= number;

	return vec;
}

v2 vec2_div(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x / second.x;
	vec.y = first.y / second.y;

	return vec;
}

v2 vec2_divNum(float number)
{
	v2 vec;

	vec.x /= number;
	vec.y /= number;

	return vec;
}
#include "vec2.h"

#include "../common/util.h"
#include <math.h>
#include <stdio.h>
#include "../rendering/window.h"

f32 v2_length(v2 vec2)
{
	return sqrtf(vec2.x*vec2.x + vec2.y*vec2.y);
}

f32 v2_dot(v2 first, v2 second)
{
	return first.x * second.x + first.y * second.y;
}

v2 v2_normalize(v2 vec2)
{
	float length = v2_length(vec2);

	vec2.x /= length;
	vec2.y /= length;

	return vec2;
}

v2 v2_rotate(v2 vec2, float angle)
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

v2 v2_add(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x + second.x;
	vec.y = first.y + second.y;

	return vec;
}

v2 v2_add_f32(v2 vec2, f32 number)
{
	vec2.x = vec2.x + number;
	vec2.y = vec2.y + number;

	return vec2;
}

v2 v2_sub(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x - second.x;
	vec.y = first.y - second.y;

	return vec;
}

v2 v2_sub_f32(v2 vec2, f32 number)
{
	vec2.x = vec2.x - number;
	vec2.y = vec2.y - number;

	return vec2;
}

v2 v2_mul(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x * second.x;
	vec.y = first.y * second.y;

	return vec;
}

v2 v2_mul_f32(v2 vec2, f32 number)
{
	vec2.x = vec2.x * number;
	vec2.y = vec2.y * number;

	return vec2;
}

v2 v2_div(v2 first, v2 second)
{
	v2 vec;

	vec.x = first.x / second.x;
	vec.y = first.y / second.y;

	return vec;
}

v2 v2_div_f32(v2 vec2, f32 number)
{
	vec2.x = vec2.x / number;
	vec2.y = vec2.y / number;

	return vec2;
}

v2 v2_inverse(v2 vec2)
{
	v2 v;

	v.x = -vec2.x;
	v.y = -vec2.y;

	return v;
}
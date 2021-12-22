#include "vec4.h"

#include <math.h>

float v4_length(v4 vec4)
{
	return sqrtf(vec4.x*vec4.x + vec4.y*vec4.y + vec4.z*vec4.z + vec4.w*vec4.w);
}

v4 v4_normalize(v4 vec4)
{
	float length = v4_length(vec4);

	vec4.x /= length;
	vec4.y /= length;
	vec4.z /= length;
	vec4.w /= length;

	return vec4;
}

v4 v4_conjugate(v4 vec4)
{
	vec4.x = -vec4.x;
	vec4.y = -vec4.y;
	vec4.z = -vec4.z;

	return vec4;
}

v4 v4_mul(v4 first, v4 second)
{
	v4 res;

	// wtf
	res.w = first.w * second.w - first.x * second.x - first.y * second.y - first.z * second.z;
	res.x = first.x * second.w - first.w * second.x + first.y * second.z - first.z * second.y;
	res.y = first.y * second.w + first.w * second.y + first.z * second.x - first.x * second.z;
	res.z = first.z * second.w + first.w * second.z + first.x * second.y - first.y * second.x;

	return res;
}

v4 v4_mul_v3(v4 vec4, v3 vec3)
{
	v4 res;

	res.w = -vec4.x * vec3.x - vec4.y * vec3.y - vec4.z * vec3.z;
	res.x =  vec4.w * vec3.x + vec4.y * vec3.z - vec4.z * vec3.y;
	res.y =  vec4.w * vec3.y + vec4.z * vec3.x - vec4.x * vec3.z;
	res.z =  vec4.w * vec3.z + vec4.x * vec3.y - vec4.y * vec3.x;

	return res;
}



v4 v4_add(v4 first, v4 second)
{
	v4 res;

	res.w = first.w + second.w;
	res.x = first.x + second.x;
	res.y = first.y + second.y;
	res.z = first.z + second.z;

	return res;
}

v4 v4_sub(v4 first, v4 second)
{
	v4 res;

	res.w = first.w - second.w;
	res.x = first.x - second.x;
	res.y = first.y - second.y;
	res.z = first.z - second.z;

	return res;
}

v4 v4_mulNum(v4 vec4, float number)
{
	v4 res;

	res.w = vec4.w * number;
	res.x = vec4.x * number;
	res.y = vec4.y * number;
	res.z = vec4.z * number;

	return res;
}
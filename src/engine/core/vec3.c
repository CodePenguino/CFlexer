#include "vec3.h"
#include <stdio.h>
#include <math.h>

float v3_length(v3 vec3)
{
	return sqrtf(vec3.x*vec3.x + vec3.y*vec3.y + vec3.z*vec3.z);
}

float v3_dot(v3 first, v3 second)
{
	return first.x * second.x + first.y * second.y + first.z * second.z;
}

v3 v3_cross(v3 first, v3 second)
{
	v3 vec;
    
	vec.x = first.y * second.z - first.z * second.y;
	vec.y = first.z * second.x - first.x * second.z;
	vec.z = first.x * second.y - first.y * second.x;
    
	return vec;
}

v3 v3_normalize(v3 vec3)
{
	float length = v3_length(vec3);
    
	vec3.x /= length;
	vec3.y /= length;
    vec3.z /= length;
    
	return vec3;
}

void v3_rotate(v3 vec3)
{
	fprintf(stderr, "Still have to implement the rotation function for vec3s!\n");
}



v3 v3_add(v3 first, v3 second)
{
	v3 vec;
    
	vec.x = first.x + second.x;
	vec.y = first.y + second.y;
	vec.z = first.z + second.z;
    
	return vec;
}

v3 v3_addNum(v3 vec3, float number)
{
	vec3.x = vec3.x + number;
	vec3.y = vec3.y + number;
	vec3.z = vec3.z + number;
    
	return vec3;
}

v3 v3_sub(v3 first, v3 second)
{
	v3 vec;
    
	vec.x = first.x - second.x;
	vec.y = first.y - second.y;
	vec.z = first.z - second.z;
    
	return vec;
}

v3 v3_subNum(v3 vec3, float number)
{
	vec3.x = vec3.x - number;
	vec3.y = vec3.y - number;
	vec3.z = vec3.z - number;
    
	return vec3;
}

v3 v3_mul(v3 first, v3 second)
{
	v3 vec;
    
	vec.x = first.x * second.x;
	vec.y = first.y * second.y;
	vec.z = first.z * second.z;
    
	return vec;
}

v3 v3_mulNum(v3 vec3, float number)
{
	vec3.x = vec3.x * number;
	vec3.y = vec3.y * number;
	vec3.z = vec3.z * number;
    
	return vec3;
}

v3 v3_div(v3 first, v3 second)
{
	v3 vec;
    
	vec.x = first.x / second.x;
	vec.y = first.y / second.y;
	vec.z = first.z / second.z;
    
	return vec;
}

v3 v3_divNum(v3 vec3, float number)
{
	vec3.x = vec3.x / number;
	vec3.y = vec3.y / number;
	vec3.z = vec3.z / number;
    
	return vec3;
}
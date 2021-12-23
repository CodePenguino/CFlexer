#include "m4.h"

#include <math.h>
#include "vec2.h"
#include <stdio.h>

// Basic initialization for a 4x4 matrix
m4 m4_set_identity()
{
	m4 m;
    
	m.data[0][0] = 1;	m.data[0][1] = 0;	m.data[0][2] = 0;	m.data[0][3] = 0;
	m.data[1][0] = 0;	m.data[1][1] = 1;	m.data[1][2] = 0;	m.data[1][3] = 0;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;	m.data[2][3] = 0;
	m.data[3][0] = 0;	m.data[3][1] = 0;	m.data[3][2] = 0;	m.data[3][3] = 1;
    
    
	// m.data = (mat4x4)m4_identity_const;
    
	return m;
}

// Multiplies two 4x4 matrices into one
m4 m4_mul(m4 first, m4 second)
{
	m4 m;
    
	for(u8 y = 0; y < 4; y++)
	{
		for(u8 x = 0; x < 4; x++)
		{
			m.data[y][x] = first.data[y][0] * second.data[0][x] +
                first.data[y][1] * second.data[1][x] +
                first.data[y][2] * second.data[2][x] +
                first.data[y][3] * second.data[3][x];
		}
	}
    
	return m;
}

m4 m4_mul_f32(m4 first, f32 second)
{
	m4 m;
    
	for(u8 y = 0; y < 4; y++)
	{
		for(u8 x = 0; x < 4; x++)
		{
			m.data[y][x] = first.data[y][0] * second +
                first.data[y][1] * second +
                first.data[y][2] * second +
                first.data[y][3] * second;
		}
	}
    
	return m;
}

m4 m4_mul_v4(m4 first, v4 second)
{
	m4 m;
    
	m.data[0][0] = second.x * first.data[0][0];
	m.data[0][1] = second.y * first.data[0][1];
	m.data[0][2] = second.z * first.data[0][2];
	m.data[0][3] = second.w * first.data[0][3];
    
	m.data[1][0] = second.x * first.data[1][0];
	m.data[1][1] = second.y * first.data[1][1];
	m.data[1][2] = second.z * first.data[1][2];
	m.data[1][3] = second.w * first.data[1][3];
    
	m.data[2][0] = second.x * first.data[2][0];
	m.data[2][1] = second.y * first.data[2][1];
	m.data[2][2] = second.z * first.data[2][2];
	m.data[2][3] = second.w * first.data[2][3];
    
	m.data[3][0] = second.x * first.data[3][0];
	m.data[3][1] = second.y * first.data[3][1];
	m.data[3][2] = second.z * first.data[3][2];
	m.data[3][3] = second.w * first.data[3][3];
    
	return m;
}

v4 v4_mul_m4(v4 second, m4 first)
{
	v4 res;
	
	res.x = first.data[0][0] * second.x + first.data[1][0] * second.y + first.data[2][0] * second.z + first.data[3][0] * second.w;
	res.y = first.data[0][1] * second.x + first.data[1][1] * second.y + first.data[2][1] * second.z + first.data[3][1] * second.w;
	res.z = first.data[0][2] * second.x + first.data[1][2] * second.y + first.data[2][2] * second.z + first.data[3][2] * second.w;
	res.w = first.data[0][3] * second.x + first.data[1][3] * second.y + first.data[2][3] * second.z + first.data[3][3] * second.w;
    
	return res;
}

// Translates a 4x4 matrix by x, y, and z
m4 m4_translate(m4 transMat, float x, float y, float z)
{
	m4 m;
    
	m.data[0][0] = 1;	m.data[0][1] = 0;	m.data[0][2] = 0;	m.data[0][3] = x;
	m.data[1][0] = 0;	m.data[1][1] = 1;	m.data[1][2] = 0;	m.data[1][3] = y;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;	m.data[2][3] = z;
	m.data[3][0] = 0;	m.data[3][1] = 0;	m.data[3][2] = 0;	m.data[3][3] = 1;
    
	return m4_mul(transMat, m);
}

// Rotates a 4x4 matrix in 2D
m4 m4_rotate(m4 transMat, float rot)
{
	m4 m;
    
	rot = degrees_to_radians(rot);
    
	m.data[0][0] = cosf(rot);		m.data[0][1] = -sinf(rot);		m.data[0][2] = 0;		m.data[0][3] = 0;
	m.data[1][0] = sinf(rot);		m.data[1][1] = cosf(rot);		m.data[1][2] = 0;		m.data[1][3] = 0;
	m.data[2][0] = 0;				m.data[2][1] = 0;				m.data[2][2] = 1;		m.data[2][3] = 0;
	m.data[3][0] = 0;				m.data[3][1] = 0;				m.data[3][2] = 0;		m.data[3][3] = 1;
    
	return m4_mul(transMat, m);
}

// Scales a 4x4 matrix by x, y, and z
m4 m4_scale(m4 transMat, float x, float y, float z)
{
	m4 m;
    
	m.data[0][0] = x;	m.data[0][1] = 0;	m.data[0][2] = 0;	m.data[0][3] = 0;
	m.data[1][0] = 0;	m.data[1][1] = y;	m.data[1][2] = 0;	m.data[1][3] = 0;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = z;	m.data[2][3] = 0;
	m.data[3][0] = 0;	m.data[3][1] = 0;	m.data[3][2] = 0;	m.data[3][3] = 1;
    
	return m4_mul(transMat, m);
}

// Sets an orthographic view projection
m4 m4_ortho(float l, float r, float b, float t, float n, float f)
{
	m4 m;
    
	m.data[0][0] = 2 / (r - l);        m.data[0][1] = 0;                  m.data[0][2] = 0;                  m.data[0][3] = 0;
	m.data[1][0] = 0;                  m.data[1][1] = 2 / (t - b);        m.data[1][2] = 0;                  m.data[1][3] = 0;
	m.data[2][0] = 0;                  m.data[2][1] = 0;                  m.data[2][2] = -2 / (f - n);       m.data[2][3] = 0;
	m.data[3][0] = -(r + l) / (r - l); m.data[3][1] = -(t + b) / (t - b); m.data[3][2] = -(f + n) / (f - n); m.data[3][3] = 1;
    
	return m;
}

/*m4 m3_to_m4(m3 tmat)
{
	m4 m;

	// Set the first 9 elements in the matrix through a simple for loop
	for(u8 i = 0; i < 3; i++)
	{
		for(u8 j = 0; j < 3; j++)
		{
			m.data[i][j] = tmat.data[i][j];
		}
	}

	// This might be wrong, but I just set the rest of these to pretty common values
	m.data[0][3] = 0;
	m.data[1][3] = 0;
	m.data[2][3] = 0;
	m.data[3][3] = 1;

	m.data[3][0] = 0;
	m.data[3][1] = 0;
	m.data[3][2] = 0;

	return m;
}*/

// TODO: Implement perspective
m4 m4_perspective(float fov, float aspect, float zNear, float zFar)
{
	fprintf(stderr, "%s", "CodePenguin (CodePingu), the creator of this project, forgot to implement perspective. Sorry about that!\n");
}

// No idea what this does lol
m4 m4_inverse(m4 mat)
{
	m4 dest;
    
	float t[6];
	float det;
	float a = mat.data[0][0], b = mat.data[0][1], c = mat.data[0][2], d = mat.data[0][3],
    e = mat.data[1][0], f = mat.data[1][1], g = mat.data[1][2], h = mat.data[1][3],
    i = mat.data[2][0], j = mat.data[2][1], k = mat.data[2][2], l = mat.data[2][3],
    m = mat.data[3][0], n = mat.data[3][1], o = mat.data[3][2], p = mat.data[3][3];
    
	t[0] = k * p - o * l; t[1] = j * p - n * l; t[2] = j * o - n * k;
	t[3] = i * p - m * l; t[4] = i * o - m * k; t[5] = i * n - m * j;
    
	dest.data[0][0] =  f * t[0] - g * t[1] + h * t[2];
	dest.data[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
	dest.data[2][0] =  e * t[1] - f * t[3] + h * t[5];
	dest.data[3][0] =-(e * t[2] - f * t[4] + g * t[5]);
    
	dest.data[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
	dest.data[1][1] =  a * t[0] - c * t[3] + d * t[4];
	dest.data[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
	dest.data[3][1] =  a * t[2] - b * t[4] + c * t[5];
    
	t[0] = g * p - o * h; t[1] = f * p - n * h; t[2] = f * o - n * g;
	t[3] = e * p - m * h; t[4] = e * o - m * g; t[5] = e * n - m * f;
    
	dest.data[0][2] =  b * t[0] - c * t[1] + d * t[2];
	dest.data[1][2] =-(a * t[0] - c * t[3] + d * t[4]);
	dest.data[2][2] =  a * t[1] - b * t[3] + d * t[5];
	dest.data[3][2] =-(a * t[2] - b * t[4] + c * t[5]);
    
	t[0] = g * l - k * h; t[1] = f * l - j * h; t[2] = f * k - j * g;
	t[3] = e * l - i * h; t[4] = e * k - i * g; t[5] = e * j - i * f;
    
	dest.data[0][3] =-(b * t[0] - c * t[1] + d * t[2]);
	dest.data[1][3] =  a * t[0] - c * t[3] + d * t[4];
	dest.data[2][3] =-(a * t[1] - b * t[3] + d * t[5]);
	dest.data[3][3] =  a * t[2] - b * t[4] + c * t[5];
    
	det = 1.0f / (a * dest.data[0][0] + b * dest.data[1][0]
                  + c * dest.data[2][0] + d * dest.data[3][0]);
    
	return dest;
}
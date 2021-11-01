#include "m4.h"

#include "../common/util.h"
#include <math.h>
#include "vec2.h"
#include <stdio.h>

// Basic initialization for a 4x4 matrix
m4 m4_init_identity()
{
	m4 m;

	m.data[0][0] = 1;	m.data[0][1] = 0;	m.data[0][2] = 0;	m.data[0][3] = 0;
	m.data[1][0] = 0;	m.data[1][1] = 1;	m.data[1][2] = 0;	m.data[1][3] = 0;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;	m.data[2][3] = 0;
	m.data[3][0] = 0;	m.data[3][1] = 0;	m.data[3][2] = 0;	m.data[3][3] = 1;

	return m;
}

// Multiplies two 4x4 matrices into one
m4 m4_mul(m4 first, m4 second)
{
	m4 m;

	for(u8 i = 0; i < 4; i++)
	{
		for(u8 j = 0; j < 4; j++)
		{
			m.data[i][j] = first.data[i][0] * second.data[0][j] +
						  first.data[i][1] * second.data[1][j] +
						  first.data[i][2] * second.data[2][j] +
						  first.data[i][3] * second.data[3][j];
		}
	}

	return m;
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

	m.data[0][0] = 2 / (r - l);			m.data[0][1] = 0;					m.data[0][2] = 0;					m.data[0][3] = 0;
	m.data[1][0] = 0;					m.data[1][1] = 2 / (t - b);			m.data[1][2] = 0;					m.data[1][3] = 0;
	m.data[2][0] = 0;					m.data[2][1] = 0;					m.data[2][2] = -2 / (f - n);		m.data[2][3] = 0;
	m.data[3][0] = -(r + l) / (r - l);	m.data[3][1] = -(t + b) / (t - b); 	m.data[3][2] = -(f + n) / (f - n); 	m.data[3][3] = 1;

	return m;
}

m4 m3_to_m4(m3 tmat)
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
}

// TODO: Implement perspective
m4 m4_perspective(float fov, float aspect, float zNear, float zFar)
{
	printf("CodePingu, the creator of this project, forgot to implement perspective. Sorry about that!\n");

	// m4 m;

	// float tanHalfFOV = tanf(fov / 2);
	// float zRange = zNear - zFar;

	// m.m[0][0] = 1.0f / (tanHalfFOV * aspect);	m.m[0][1] = 0;					m.m[0][2] = 0;						m.m[0][3] = 0;
	// m.m[1][0] = 0;								m.m[1][1] = 1.0f / tanHalfFOV;	m.m[1][2] = 0;						m.m[1][3] = 0;
	// m.m[2][0] = 0;								m.m[2][1] = 0;					m.m[2][2] = (-zNear -zFar)/zRange;	m.m[2][3] = 2 * zFar * zNear / zRange;
	// m.m[3][0] = 0;								m.m[3][1] = 0;					m.m[3][2] = 1;						m.m[3][3] = 0;

	// return m;
}
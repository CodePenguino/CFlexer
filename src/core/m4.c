#include "m4.h"

#include "../common/util.h"
#include <math.h>

m4 m4_init_identity()
{
	m4 m;

	m.raw[0][0] = 1;	m.raw[0][1] = 0;	m.raw[0][2] = 0;	m.raw[0][3] = 0;
	m.raw[1][0] = 0;	m.raw[1][1] = 1;	m.raw[1][2] = 0;	m.raw[1][3] = 0;
	m.raw[2][0] = 0;	m.raw[2][1] = 0;	m.raw[2][2] = 1;	m.raw[2][3] = 0;
	m.raw[3][0] = 0;	m.raw[3][1] = 0;	m.raw[3][2] = 0;	m.raw[3][3] = 1;

	return m;
}

m4 m4_mul(m4 first, m4 second)
{
	m4 m;

	for(u8 i = 0; i < 4; i++)
	{
		for(u8 j = 0; j < 4; j++)
		{
			m.raw[i][j] = first.raw[i][0] * second.raw[0][j] +
						  first.raw[i][1] * second.raw[1][j] +
						  first.raw[i][2] * second.raw[2][j] +
						  first.raw[i][3] * second.raw[3][j];
		}
	}

	return m;
}

m4 m4_init_translation(m4 transMat, float x, float y, float z)
{
	m4 m;

	m.raw[0][0] = 1;	m.raw[0][1] = 0;	m.raw[0][2] = 0;	m.raw[0][3] = x;
	m.raw[1][0] = 0;	m.raw[1][1] = 1;	m.raw[1][2] = 0;	m.raw[1][3] = y;
	m.raw[2][0] = 0;	m.raw[2][1] = 0;	m.raw[2][2] = 1;	m.raw[2][3] = z;
	m.raw[3][0] = 0;	m.raw[3][1] = 0;	m.raw[3][2] = 0;	m.raw[3][3] = 1;

	return m4_mul(transMat, m);
}

m4 m4_init_scale(m4 transMat, float x, float y, float z)
{
	m4 m;

	m.raw[0][0] = x;	m.raw[0][1] = 0;	m.raw[0][2] = 0;	m.raw[0][3] = 0;
	m.raw[1][0] = 0;	m.raw[1][1] = y;	m.raw[1][2] = 0;	m.raw[1][3] = 0;
	m.raw[2][0] = 0;	m.raw[2][1] = 0;	m.raw[2][2] = z;	m.raw[2][3] = 0;
	m.raw[3][0] = 0;	m.raw[3][1] = 0;	m.raw[3][2] = 0;	m.raw[3][3] = 1;

	return m4_mul(transMat, m);
}

m4 m4_init_ortho(float l, float r, float b, float t, float n, float f)
{
	m4 m;

	m.raw[0][0] = 2 / (r - l);
	m.raw[0][1] = 0;
	m.raw[0][2] = 0;
	m.raw[0][3] = 0;

	m.raw[1][0] = 0;
	m.raw[1][1] = 2 / (t - b);
	m.raw[1][2] = 0;
	m.raw[1][3] = 0;

	m.raw[2][0] = 0;
	m.raw[2][1] = 0;
	m.raw[2][2] = -2 / (f - n);
	m.raw[2][3] = 0;

	m.raw[3][0] = -(r + l) / (r - l);
	m.raw[3][1] = -(t + b) / (t - b); 
	m.raw[3][2] = -(f + n) / (f - n); 
	m.raw[3][3] = 1;

	return m;
}

m4 m4_init_perspective(float fov, float aspect, float zNear, float zFar)
{
	/*m4 m;

	float tanHalfFOV = tanf(fov / 2);
	float zRange = zNear - zFar;

	m.m[0][0] = 1.0f / (tanHalfFOV * aspect);	m.m[0][1] = 0;					m.m[0][2] = 0;						m.m[0][3] = 0;
	m.m[1][0] = 0;								m.m[1][1] = 1.0f / tanHalfFOV;	m.m[1][2] = 0;						m.m[1][3] = 0;
	m.m[2][0] = 0;								m.m[2][1] = 0;					m.m[2][2] = (-zNear -zFar)/zRange;	m.m[2][3] = 2 * zFar * zNear / zRange;
	m.m[3][0] = 0;								m.m[3][1] = 0;					m.m[3][2] = 1;						m.m[3][3] = 0;

	return m;*/
}

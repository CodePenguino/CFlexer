#include "m3.h"
#include "../common/util.h"

m3 m3_init_identity()
{
	m3 m;

	m.m[0][0] = 1;	m.m[0][1] = 0;	m.m[0][2] = 0;
	m.m[1][0] = 0;	m.m[1][1] = 1;	m.m[1][2] = 0;
	m.m[2][0] = 0;	m.m[2][1] = 0;	m.m[2][2] = 1;

	return m;
}

m3 m3_mul(m3 first, m3 second)
{
	m3 m;

	for(u8 i = 0; i < 3; i++)
	{
		for(u8 j = 0; j < 3; j++)
		{
			m.m[i][j] = first.m[i][0] * second.m[0][j] +
						first.m[i][1] * second.m[1][j] +
						first.m[i][2] * second.m[2][j];
		}
	}

	return m;
}

m3 m3_init_translation(float x, float y)
{
	m3 m;

	m.m[0][0] = 1;	m.m[0][1] = 0;	m.m[0][2] = x;
	m.m[1][0] = 0;	m.m[1][1] = 1;	m.m[1][2] = y;
	m.m[2][0] = 0;	m.m[2][1] = 0;	m.m[2][2] = 1;

	return m;
}

m3 m3_init_scale(float x, float y)
{
	m3 m;

	m.m[0][0] = x;	m.m[0][1] = 0;	m.m[0][2] = 0;
	m.m[1][0] = 0;	m.m[1][1] = y;	m.m[1][2] = 0;
	m.m[2][0] = 0;	m.m[2][1] = 0;	m.m[2][2] = 1;

	return m;
}
#include "m3.h"
#include "../common/util.h"

m3 m3_init_identity()
{
	m3 m;

	m.data[0][0] = 1;	m.data[0][1] = 0;	m.data[0][2] = 0;
	m.data[1][0] = 0;	m.data[1][1] = 1;	m.data[1][2] = 0;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;

	return m;
}

m3 m3_mul(m3 first, m3 second)
{
	m3 m;

	for(u8 i = 0; i < 3; i++)
	{
		for(u8 j = 0; j < 3; j++)
		{
			m.data[i][j] = first.data[i][0] * second.data[0][j] +
						first.data[i][1] * second.data[1][j] +
						first.data[i][2] * second.data[2][j];
		}
	}

	return m;
}

m3 m3_translate(m3 transMat, v2 v)
{
	m3 m;

	m.data[0][0] = 1;	m.data[0][1] = 0;	m.data[0][2] = v.x;
	m.data[1][0] = 0;	m.data[1][1] = 1;	m.data[1][2] = v.y;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;
	
	return m3_mul(transMat, m);

	/*m3 m;

	m.data[2][0] = m.data[0][0] * v.x + m.data[1][0] * v.y + m.data[2][0];
	m.data[2][1] = m.data[0][1] * v.x + m.data[1][1] * v.y + m.data[2][1];
	m.data[2][2] = m.data[0][2] * v.x + m.data[1][2] * v.y + m.data[2][2];

	return m3_mul(transMat, m);*/
}

m3 m3_rotate(m3 transMat, float angle)
{
	m3 m;

	angle = degrees_to_radians(angle);

	m.data[0][0] = cosf(angle);		m.data[0][1] = -sinf(angle);	m.data[0][2] = 0;
	m.data[1][0] = sinf(angle);		m.data[1][1] = cosf(angle);		m.data[1][2] = 0;
	m.data[2][0] = 0;				m.data[2][1] = 0;				m.data[2][2] = 1;

	return m3_mul(transMat, m);

	/*m3 m;

	float m00 = m.data[0][0],  m10 = m.data[1][0],
    m01 = m.data[0][1],  m11 = m.data[1][1],
    m02 = m.data[0][2],  m12 = m.data[1][2];

	float sine   = sinf(angle);
	float cosine = cosf(angle);

	m.data[0][0] = m00 * cosine + m10 * sine;
	m.data[0][1] = m01 * cosine + m11 * sine;
	m.data[0][2] = m02 * cosine + m12 * sine;

	m.data[1][0] = m00 * -sine + m10 * cosine;
	m.data[1][1] = m01 * -sine + m11 * cosine;
	m.data[1][2] = m02 * -sine + m12 * cosine;

	return m3_mul(transMat, m);*/
}

m3 m3_scale(m3 transMat, v2 v)
{
	m3 m;

	m.data[0][0] = v.x;	m.data[0][1] = 0;	m.data[0][2] = 0;
	m.data[1][0] = 0;	m.data[1][1] = v.y;	m.data[1][2] = 0;
	m.data[2][0] = 0;	m.data[2][1] = 0;	m.data[2][2] = 1;

	return m3_mul(transMat, m);

	/*m3 m;

	m.data[0][0] = m.data[0][0] * v.x;
	m.data[0][1] = m.data[0][1] * v.x;
	m.data[0][2] = m.data[0][2] * v.x;

	m.data[1][0] = m.data[1][0] * v.y;
	m.data[1][1] = m.data[1][1] * v.y;
	m.data[1][2] = m.data[1][2] * v.y;

	return m3_mul(transMat, m);*/
}

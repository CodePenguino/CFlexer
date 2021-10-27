#include "m4.h"

#include "../common/util.h"

m4* m4_init_identity()
{
	m4* m;

	*m[0][0] = 1;	*m[0][1] = 0;	*m[0][2] = 0;	*m[0][3] = 0;
	*m[1][0] = 0;	*m[1][1] = 1;	*m[1][2] = 0;	*m[1][3] = 0;
	*m[2][0] = 0;	*m[2][1] = 0;	*m[2][2] = 1;	*m[2][3] = 0;
	*m[3][0] = 0;	*m[3][1] = 0;	*m[3][2] = 0;	*m[3][3] = 1;

	return m;
}

m4* m4_mul(m4 first, m4 second)
{
	m4* m;

	for(u8 i = 0; i < 4; i++)
	{
		for(u8 j = 0; j < 4; j++)
		{
			*m[i][j] = first[i][0] * second[0][j] +
						first[i][1] * second[1][j] +
						first[i][2] * second[2][j] +
						first[i][3] * second[3][j];
		}
	}

	return m;
}
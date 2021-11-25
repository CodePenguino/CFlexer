#include "m2.h"

m2 m2_init_identity()
{
	m2 m;

	m.data[0][0] = 1;	m.data[0][1] = 0;
	m.data[1][0] = 0;	m.data[1][1] = 1;

	return m;
}
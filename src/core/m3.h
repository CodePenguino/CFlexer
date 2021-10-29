#ifndef M3_H
#define M3_H

#include "vec2.h"

typedef struct
{
	float data[3][3];
} m3;

m3 m3_init_identity();
m3 m3_mul(m3 first, m3 second);
m3 m3_translate(m3 m, v2 v);
void m3_rotate(m3 m, float angle);
m3 m3_scale(m3 m, v2 v);

#endif // M3_H
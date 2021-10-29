#ifndef M3_H
#define M3_H

typedef struct
{
	float m[3][3];
} m3;

m3 m3_init_identity();
m3 m3_mul(m3 first, m3 second);
m3 m3_init_translation(float x, float y);
m3 m3_init_scale(float x, float y);

#endif // M3_H
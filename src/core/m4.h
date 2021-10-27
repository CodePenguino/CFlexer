#ifndef M4_H
#define M4_H

typedef float m4[4][4];

/*typedef struct
{
	float m[4][4];
} m4;*/

m4* m4_init_identity();
m4* m4_mul(m4 first, m4 second);

#endif // M4_H
#ifndef M2_H
#define M2_H

typedef struct
{
	float data[2][2];
} m2;

m2 m2_init_identity();

#endif // M2_H
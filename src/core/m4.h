#ifndef M4_H
#define M4_H

typedef struct
{
	float raw[4][4];
} m4;

m4 m4_init_identity();
m4 m4_mul(m4 first, m4 second);
m4 m4_init_translation(m4 transMat, float x, float y, float z);
m4 m4_init_scale(m4 transMat, float x, float y, float z);

m4 m4_init_ortho(float left, float right, float bottom, float top, float zNear, float zFar);
m4 m4_init_perspective(float fov, float aspect, float zNear, float zFar);

#endif // M4_H

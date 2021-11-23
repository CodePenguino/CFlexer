#include "camera.h"
#include "../rendering/window.h"

void camera2d_init(Camera2d* camera, v2 pos, float rot)
{
	camera->transform.position = pos;
	camera->transform.rotation = rot;
	camera->transform.scale    = (v2){ 1.0f,1.0f };

	camera->projMat = m4_ortho(-window.aspectRatio, window.aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
	camera->viewMat = m4_set_identity();
}

void camera2d_setViewMat(Camera2d* camera)
{
	camera->viewMat = m4_set_identity();

	m4 pos = m4_translate(camera->viewMat, -camera->transform.position.x, -camera->transform.position.y, 0.0f);
	m4 rot = m4_rotate(camera->viewMat, camera->transform.rotation);

	camera->viewMat = m4_mul(rot, pos);
}

m4 camera2d_getViewProj(Camera2d* camera)
{
	camera2d_setViewMat(camera);

	return m4_mul(camera->projMat, camera->viewMat);
}
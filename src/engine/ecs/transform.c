#include "transform.h"
#include "../rendering/window.h"

m4 transform2d_get_mat(Transform2d* transform)
{
	m4 modelMat = m4_set_identity();

	m4 posMatrix = m4_translate(modelMat, transform->position.x, transform->position.y, 1.0f);
	m4 rotMatrix = m4_rotate(modelMat, transform->rotation);
	m4 sclMatrix = m4_scale(modelMat, transform->scale.x, transform->scale.y, 1.0f);

	modelMat = m4_mul(posMatrix, m4_mul(rotMatrix, sclMatrix));
	
	return modelMat;
}

m4 transform2d_get_ortho(Camera2d* camera, Transform2d* transform)
{
	// m4 modelMat = transform2d_get_mat(transform);
	/*m4 projMat = m4_ortho(-window.aspectRatio, window.aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
	m4 viewMat = m4_set_identity();

	m4 pos = m4_translate(viewMat, 0.0f, 0.0f, 0.0f);
	m4 rot = m4_rotate(viewMat, 0.0f);

	viewMat = m4_mul(rot, pos);*/

	return m4_mul(camera2d_getViewProj(camera), transform2d_get_mat(transform));
}

// -------------------------------------------------------

m4 transform3d_get_mat(Transform3d* transform)
{
	// TODO: Just IMPLEMENT ME ALREADY!
}
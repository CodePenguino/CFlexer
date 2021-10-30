#include "transform.h"
#include "../rendering/window.h"

/*m4 transform2d_get_mat(Transform2d* transform)
{
	m4 modelMat = m4_init_identity();

	m4 posMatrix = m4_init_translation(modelMat, transform->position.x, transform->position.y, 1.0f);
	m4 rotMatrix = m4_init_rotation(modelMat, transform->rotation);
	m4 sclMatrix = m4_init_scale(modelMat, transform->scale.x, transform->scale.y, 1.0f);

	modelMat = m4_mul(posMatrix, m4_mul(rotMatrix, sclMatrix));

	return modelMat;
}

m4 transform2d_get_ortho(Transform2d* transform)
{
	m4 transMatrix = transform2d_get_mat(transform);
	m4 orthoMatrix = m4_init_ortho(-window_getAspectRatio(), window_getAspectRatio(), -1.0f, 1.0f, -1.0f, 1.0f);

	return m4_mul(orthoMatrix, transMatrix);
}*/

m4 transform2d_get_mat(Transform2d* transform)
{
	m4 modelMat = m4_init_identity();

	m4 posMatrix = m4_init_translation(modelMat, transform->position.x, transform->position.y, 1.0f);
	m4 rotMatrix = m4_init_rotation(modelMat, transform->rotation);
	m4 sclMatrix = m4_init_scale(modelMat, transform->scale.x, transform->scale.y, 1.0f);

	modelMat = m4_mul(posMatrix, m4_mul(rotMatrix, sclMatrix));

	return modelMat;
}

m4 transform2d_get_ortho(Transform2d* transform)
{
	m4 transMatrix = transform2d_get_mat(transform);
	m4 orthoMatrix = m4_init_ortho(-window_getAspectRatio(), window_getAspectRatio(), -1.0f, 1.0f, -1.0f, 1.0f);

	return m4_mul(orthoMatrix, transMatrix);
}

// -------------------------------------------------------

m4 transform3d_get_mat(Transform3d* transform)
{
	m4 modelMat;

	m4 posMatrix = m4_init_translation(modelMat, transform->position.x, transform->position.y, transform->position.z);
	m4 sclMatrix = m4_init_scale(modelMat, transform->scale.x, transform->scale.y, transform->scale.z);

	modelMat = m4_mul(posMatrix, sclMatrix);

	return modelMat;
}

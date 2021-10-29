#include "transform.h"

m4 transform2d_get_mat(Transform2d transform)
{
	m4 modelMat = m4_init_identity();

	// m4 posMatrix = glms_translate(modelMat, (vec3s) { transform.position.x, transform.position.y, 1.0f });
	// m4 sclMatrix = glms_scale(modelMat, (vec3s) { transform.scale.x, transform.scale.y, 1.0f });

	m4 posMatrix = m4_init_translation(modelMat, transform.position.x, transform.position.y, 1.0f);
	m4 sclMatrix = m4_init_scale(modelMat, transform.scale.x, transform.scale.y, 1.0f);

	modelMat = m4_mul(posMatrix, sclMatrix);

	return modelMat;
}

m4 transform2d_get_ortho(Transform2d transform)
{
	m4 transMatrix = transform2d_get_mat(transform);
	m4 orthoMatrix = m4_init_ortho(-2, 2, -1.5f, 1.5f, -1.0f, 1.0f);

	return m4_mul(transMatrix, orthoMatrix);
}

m4 transform3d_get_mat(Transform3d transform)
{
	/*m4 posMatrix = m4_init_translation(transform.position.x, transform.position.y, transform.position.z);
	m4 sclMatrix = m4_init_scale(transform.scale.x, transform.scale.y, transform.scale.z);

	return m4_mul(posMatrix, sclMatrix);*/
}
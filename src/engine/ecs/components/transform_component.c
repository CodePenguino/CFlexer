#include "transform_component.h"
#include "../../rendering/window.h"

Transform2dComponent transform2d_init()
{
	Transform2dComponent trans;
    
	trans.position.x = 0.0f;
	trans.position.y = 0.0f;
	trans.rotation = 0.0f;
	trans.scale.x = 1.0f;
	trans.scale.y = 1.0f;
    
	return trans;
}

m4 transform2d_get_mat(Transform2dComponent* transform)
{
	m4 modelMat = m4_set_identity();
    
	m4 posMatrix = m4_translate(modelMat, transform->position.x, transform->position.y, 1.0f);
	m4 rotMatrix = m4_rotate(modelMat, transform->rotation);
	m4 sclMatrix = m4_scale(modelMat, transform->scale.x, transform->scale.y, 1.0f);
    
	modelMat = m4_mul(posMatrix, m4_mul(rotMatrix, sclMatrix));
	
	return modelMat;
}

m4 transform2d_get_ortho(Camera2dComponent* camera, Transform2dComponent* transform)
{
	return m4_mul(camera2d_getViewProj(camera), transform2d_get_mat(transform));
}

float transform2d_rotate_to_point(v2 point)
{
	return radians_to_degrees(atan2f(point.y, point.x));
}

// -------------------------------------------------------

m4 transform3d_get_mat(Transform3dComponent* transform)
{
	// TODO: Just IMPLEMENT ME ALREADY!
}

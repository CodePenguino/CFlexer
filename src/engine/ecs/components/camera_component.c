#include "camera_component.h"
#include "../../rendering/window.h"
#include <stdio.h>

void camera2d_init(Camera2dComponent* camera, v2 pos, float rot)
{
	camera->transform.position = pos;
	camera->transform.rotation = rot;
	camera->transform.scale    = (v2){ 1.0f,1.0f };
    
	// camera->projMat = m4_ortho(-window.aspectRatio, window.aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
	camera->projMat = m4_ortho(-window.aspectRatio, window.aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
	camera->viewMat = m4_set_identity();
}

void camera2d_setViewMat(Camera2dComponent* camera)
{
	camera->viewMat = m4_set_identity();
    
	m4 pos = m4_translate(camera->viewMat, -camera->transform.position.x, -camera->transform.position.y, 0.0f);
	m4 rot = m4_rotate(camera->viewMat, camera->transform.rotation);
    
	camera->viewMat = m4_mul(rot, pos);
}

m4 camera2d_getViewProj(Camera2dComponent* camera)
{
	camera2d_setViewMat(camera);
    
	return m4_mul(camera->projMat, camera->viewMat);
}

// Turn a screen space coordinate to a view space coordinate
v2 v2_screen_to_view_space(v2 vector, Camera2dComponent* camera)
{
	// Normalized Device Space
	float x = 2.0f * vector.x / window.width  - 1;
	float y = 2.0f * vector.y / window.height - 1;
    
	// No multiplication function for v2s, so v4s it is!
	v4 screenPos = (v4) { x, y, -1.0f, 1.0f };
	// wtf is this
	v4 viewPos = v4_mul_m4(screenPos, m4_inverse(m4_mul(camera->viewMat, camera->projMat)));
    
	// Multiply the final view position with the aspect ratio, and add the camera's position to that
	return (v2) { (-viewPos.x * window.aspectRatio) + camera->transform.position.x,
        (viewPos.y * window.aspectRatio) + camera->transform.position.y };
}

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "comp_data.h"
#include "camera.h"

m4 transform2d_get_mat(Transform2dComponent* transform);
m4 transform2d_get_ortho(Camera2dComponent* camera, Transform2dComponent* transform);

float transform2d_rotate_to_point(v2 point);

// TODO: Create quaternion (v4) rotation
// TODO: Finish 3d transformations as a whole

m4 transform3d_get_mat(Transform3dComponent* transform);

#endif // TRANSFORM_H

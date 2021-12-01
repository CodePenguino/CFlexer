#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "components.h"
#include "camera.h"

m4 transform2d_get_mat(Transform2d* transform);
m4 transform2d_get_ortho(Camera2d* camera, Transform2d* transform);

float transform2d_rotate_to_point(v2 point);

// TODO: Create quaternion (v4) rotation
// TODO: Finish 3d transformations as a whole

m4 transform3d_get_mat(Transform3d* transform);

#endif // TRANSFORM_H

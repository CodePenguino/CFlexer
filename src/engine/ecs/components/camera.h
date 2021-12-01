#ifndef CAMERA_H
#define CAMERA_H

#include "components.h"

void camera2d_init(Camera2d* camera, v2 pos, float rot);
void camera2d_setViewMat(Camera2d* camera);
m4 camera2d_getViewProj(Camera2d* camera);

v2 v2_screen_to_view_space(v2 vector, Camera2d* camera);

#endif // CAMERA_H
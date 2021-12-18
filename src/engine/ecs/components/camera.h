#ifndef CAMERA_H
#define CAMERA_H

#include "comp_data.h"

void camera2d_init(Camera2dComponent* camera, v2 pos, float rot);
void camera2d_setViewMat(Camera2dComponent* camera);
m4 camera2d_getViewProj(Camera2dComponent* camera);

v2 v2_screen_to_view_space(v2 vector, Camera2dComponent* camera);

#endif // CAMERA_H
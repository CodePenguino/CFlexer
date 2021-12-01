#ifndef ECSCOMPONENTS_H
#define ECSCOMPONENTS_H

#include "../../common/util.h"
#include "../../core/math.h"

// TODO: Make the ECS actually have entities and systems

typedef struct
{
	u32 entity_id;
	u32 uid;

	v2 position;
	f32 rotation;
	v2 scale;
} Transform2d;

typedef struct
{
	u32 entity_id;
	u32 uid;

	v3 position;
	v3 scale;
} Transform3d;

typedef struct
{
	u32 entity_id;
	u32 uid;
	m4 projMat, viewMat;

	Transform2d transform;
} Camera2d;

#endif // ECSCOMPONENTS_H
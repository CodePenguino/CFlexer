#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "../common/util.h"
#include "../core/math.h"

// TODO: Make the ECS actually have entities and systems too

typedef struct Transform2d
{
	u32 entity_id;
	
	v2 position;
	f32 rotation;
	v2 scale;
} Transform2d;

typedef struct
{
	u32 entity_id;

	v3 position;
	v3 scale;
} Transform3d;

typedef struct
{
	m4 projMat, viewMat;

	Transform2d transform;
} Camera2d;

#endif // COMPONENTS_H

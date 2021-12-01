#include "components.h"

u64 ecs_component_get_uID()
{
	static u64 lastID = 0u;
	return lastID++;
}
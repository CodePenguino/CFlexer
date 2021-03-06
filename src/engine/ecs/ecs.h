#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <inttypes.h>
#include <stddef.h>
#include "../common/util.h"

#define ENTITY_FLAG_ALIVE 1

// Macros for different ECS systems
#define EcsOnStart  0
#define EcsOnUpdate 1

/*typedef struct
{
    void* components;
    size_t component_size;
} ComponentList;*/

typedef struct
{
    u32 id;
    u8 tag;
} Entity;

// typedef uint32_t Entity;

typedef struct {
	uint32_t count;
	uint32_t cap;
	uint32_t *list;
} QueryResult;

/* NOTE: The following code is from Falconerd, which wrote this in
 * the following link: https://gitlab.com/Falconerd/ember-ecs.
 * He actually knows what he's doing.
 */

/**
 * Initialise the ECS module with the component sizes.
 * 
 * Must pass in the size of each component type in the order you want
 * to store them. The maximum number of component types is 32, though
 * this could be extended by adding another bitmask and a bit switch.
 */
void ecs_init(uint32_t component_count, ...);

/**
 * Create an entity. Returns a handle which contains the id.
 */
Entity ecs_create();

/**
 * Get component data from an entity.
 */
void *ecs_get(uint32_t entity_id, uint32_t component_id);

/**
 * Add a component with data to an entity.
 */
void ecs_add(uint32_t entity_id, uint32_t component_id, void *data);

/**
 * Remove a component from an entity.
 */
void ecs_remove(uint32_t entity_id, uint32_t component_id);

/**
 * Returns true if entity has component.
 */
uint32_t ecs_has(uint32_t entity_id, uint32_t component_id);

/**
 * Kill an entity.
 */
void ecs_kill(uint32_t entity_id);

/**
 * Find all entities which have components with IDs.
 */
QueryResult *ecs_query(uint32_t component_count, ...);

void ecs_free();

#endif

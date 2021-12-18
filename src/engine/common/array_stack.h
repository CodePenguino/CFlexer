#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "util.h"

typedef struct
{
	size_t size;
	u32 count;
	u32 cap;
	void* data;
} ArrayStack;

ArrayStack* as_create(size_t size);
void as_destroy(ArrayStack* as);
void* as_pop(ArrayStack* as);
void as_push(ArrayStack* as, void* data);

#endif // ARRAY_STACK_H

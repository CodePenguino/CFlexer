#include "array_stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayStack* as_create(size_t size)
{
	ArrayStack* as = (ArrayStack*)malloc(sizeof(ArrayStack));

	as->size = size;
	as->data = malloc(size);
	as->cap = 1;
	as->count = 0;

	return as;
}

void as_destroy(ArrayStack* as)
{
	free(as->data);
	free(as);
}

void* as_pop(ArrayStack* as)
{
	u8* result = (u8*)as->data;
	result += (--as->count) * as->size;
	return result;
}

void as_push(ArrayStack* as, void* data)
{

	uint8_t *ptr;

	if (as->count == as->cap) {
		void *data = realloc(as->data, as->cap * 2 * as->size);
		if (NULL == data) {
			printf("Failed to reallocate memory %s:%d\n", __FILE__, __LINE__);
			exit(1);
		} else {
			as->data = data;
			as->cap *= 2;
		}
	}

	ptr = (uint8_t*)as->data;
	ptr += (as->count++) * as->size;
	memcpy(ptr, data, as->size);
}

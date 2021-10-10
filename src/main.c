#include <stdio.h>
#include "rendering/window.h"

int main()
{
	window_create(1024, 768, "It's a window!");
	window_mainloop();
	
	return 0;
}

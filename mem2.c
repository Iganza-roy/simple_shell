#include "shell.h"

/**
 * freePointers - ...
 * @Pointer: ...
 */
int freePointers(void **Pointer)
{
	if (Pointer && *Pointer)
	{
		free(*Pointer);
		*Pointer = NULL;
		return (1);
	}
	return (0);
}

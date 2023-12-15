#include "shell.h"

/**
 * freePointers - ...
 * @Pointer: ...
 * Return: 0 on success
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

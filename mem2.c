#include "shell.h"

/**
 * free_ptrs - ...
 * @Pointer: ...
 * Return: 0 on success
 */
int free_ptrs(void **Pointer)
{
	if (Pointer && *Pointer)
	{
		free(*Pointer);
		*Pointer = NULL;
		return (1);
	}
	return (0);
}

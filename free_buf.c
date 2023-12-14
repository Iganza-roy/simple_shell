#include "shell.h"

/**
 * free_me - frees buffers
 * @buffer: to be freed
 */
void free_me(char **buffer)
{
	int x = 0;

	if (!buffer || buffer == NULL)
		return;

	while (buffer[x] == NULL)
	{
		free(buffer[x]);
		x++;
	}
	free(buffer);
}

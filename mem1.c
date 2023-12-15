#include "shell.h"

/**
 * fillMemoryWith - fill memory
 * @a: ...
 * @s: ....
 * @x: ...
 * Return: filled space
 */
char *fillMemoryWith(char *a, char s, unsigned int x)
{
	unsigned int y;

	for (y = 0; y < x; y++)
		a[y] = s;
	return (a);
}

/**
 * free_func - ...
 * @ss: ...
 */
void free_func(char **ss)
{
	char **x = ss;

	if (!ss)
		return;

	while (*ss)
		free(*ss++);

	free(x);
}

/**
 * reAllocat - ...
 * @pointer: ...
 * @oldsize: ...
 * @newsize: ...
 * Return: nothing
 */
void *reAllocat(void *pointer, unsigned int oldsize, unsigned int newsize)
{
	char *x;

	if (!pointer)
		return (malloc(newsize));

	if (!newsize)
		return (free(pointer), NULL);

	if (newsize == oldsize)
		return (pointer);

	x = malloc(newsize);
	if (!x)
		return (NULL);

	oldsize = oldsize < newsize ? oldsize : newsize;
	while (oldsize--)
		x[oldsize] = ((char *)pointer)[oldsize];

	free(pointer);
	return (x);
}

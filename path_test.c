#include "shell.h"

/**
 * path_test - tests existing path
 * @p: path
 * @cmd: command
 * Return: added path
 */
char *path_test(char **p, char *cmd)
{
	char *result;
	int x = 0;

	while (p[x])
	{
		result = add_path(p[x], cmd);

		if (access(result, F_OK | X_OK) == 0)
			return (result);
		free(result);
		x++;
	}
	return (NULL);
}

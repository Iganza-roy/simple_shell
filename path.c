#include "shell.h"

/**
 * path_finder - finds path
 * Return: NULL if path not found
 */
char *path_finder(void)
{
	int count = 0;
	char **env = environ, *p = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			p = *env;
			while (*p && count < 5)
			{
				p++;
				count++;
			}
			return (p);
		}
		env++;
	}
	return (NULL);
}

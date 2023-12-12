#include "shell.h"

/**
 * print_env - ...
 */
void print_env(void)
{
	extern char **environ;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		_printme("%s\n", *env);
	}
}

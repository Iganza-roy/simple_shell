#include "shell.h"

/**
 * print_env - ...
 */
void print_env(void)
{
	extern char **environ;
	for (char **env = environ; *env != NULL; env++)
	{
		_printme("%s\n", *env);
	}
}

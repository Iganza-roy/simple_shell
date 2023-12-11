#include "shell.h"

/**
 * print_env - ...
 */
void print_env(void)
{
	extern char **environment;
	for (char **env = environment; *env != NULL; env++)
	{
		_printme("%s\n", *env);
	}
}

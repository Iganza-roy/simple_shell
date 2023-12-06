#include "shell.h"

/**
 * print_env - ...
 */
void print_env(void)
{
	extern char **env_one;
	char **env_two;

	for (env_two = env_one; *env_two != NULL; env_two++)
	{
		printf("%s\n", *env_two);
	}
}

#include "shell.h"

/**
 * unset_env - ....
 * @var: ...
 * Return: ...
 */

int unset_env(const char *var)
{
	if (var == NULL)
	{
		fprintf(stderr, "Invalid\n");
		return (-1);
	}

	if (getenv(var) == NULL)
	{
		fprintf(stderr, "var %s not found\n", var);
		return (-1);
	}

	if (unsetenv(var) != 0)
	{
		fprintf(stderr, "Falied to unset %s\n", var);
		return (-1);
	}

	return (0);
}

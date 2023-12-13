#include "shell.h"

/**
 * set_env - ...
 * @var: ...
 * @val: ...
 * @owr: ...
 * Return: ...
 */

int set_env(const char *var, const char *val, int owr)
{
	if (var == NULL || val == NULL)
	{
		fprintf(stderr, "Invalid\n");
		return (-1);
	}

	if (getenv(var) != NULL && !owr)
	{
		fprintf(stderr, "Var %s already exists\n", var);
		return (-1);
	}

	if (setenv(var, val, 1) != 0)
	{
		fprintf(stderr, "Falied to set %s", var);
		return (-1);
	}

	return (0);
}

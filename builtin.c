#include "shell.h"

/**
 * _builtin - executes builtin funcs
 * @cmd: command
 * @l: read input
 * Return: 1 on success
 */
int _builtin(char **cmd, char *l)
{
	struct y y = {"exit", "env"};

	if (_strcmp(*cmd, y.env) == 0)
	{
		_env();
		return (1);
	}
	else if (_strcmp(*cmd, y.exit) == 0)
	{
		exit_me(cmd, l);
		return (1);
	}
	return (0);
}

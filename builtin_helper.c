#include "shell.h"

/**
 * b_helper - helps builtin func
 * @cmd: command
 * @s: line from getline
 * Return: 1 on success
 */
int b_helper(char **cmd, char *s)
{
	if (_builtin(cmd, s))
		return (1);
	else if (**cmd == '/')
	{
		_exe(cmd[0], cmd);
		return (1);
	}
	return (0);
}

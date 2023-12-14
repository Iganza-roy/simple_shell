#include "shell.h"

/**
 * _env - prints string environment
 * Return: Always 0 on success
 */
void _env(void)
{
	int y = 0;
	char **env = environ;

	while (env[y])
	{
		write(STDOUT_FILENO, (const void *)env[y], _strlen(env[y]));
		write(STDOUT_FILENO, "\n", 1);
		y++;
	}
}

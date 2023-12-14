#include "shell.h"

/**
 * add_path - adds path
 * @p: path of cmd
 * @cmd: command
 * Return: path on success;
 */
char *add_path(char *p, char *cmd)
{
	size_t x = 0, y = 0;
	char *bf;

	if (cmd == 0)
		cmd = "";

	if (p == 0)
		p = "";

	bf = malloc(sizeof(char) * (_strlen(p) + _strlen(cmd) + 2));
	if (!bf)
		return (NULL);

	while (p[x])
	{
		bf[x] = p[x];
		x++;
	}

	if (p[x - 1] != '/')
	{
		bf[x] = '/';
		x++;
	}
	while (cmd[y])
	{
		bf[x + y] = cmd[y];
		y++;
	}
	bf[x + y] = '\0';
	free(bf);
	return (bf);
}


#include "shell.h"

/**
 * read_cmd - reads input
 * @cmd: command
 * @size: size of input
 */
void read_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_printme("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	cmd[_strcspn(cmd, "\n")] = '\0';
}

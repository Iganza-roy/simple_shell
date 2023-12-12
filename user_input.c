#include "shell.h"

/**
 * _strcspn - ...
 * @s: ...
 * @reject: ...
 * Return: ..
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t i, len = 0;

	while (s[len] != '\0')
	{
		int x = 0;

		for (i = 0; reject[i] != '\0'; i++)
		{
			if (s[len] == reject[i])
			{
				x = 1;
				break;
			}
		}

		if (x)
		{
			return (len);
		}
		len++;
	}
	return (len);
}

/**
 * read_cmd - receives a command
 * @cmd: command received
 * @size: size of the command
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
			_printme("Error while reading\n");
			exit(EXIT_FAILURE);
		}
	}

	cmd[_strcspn(cmd, "\n")] = '\0';
}

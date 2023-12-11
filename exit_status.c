#include "shell.h"

/**
 * exit_status - handles arguments for the built-in exit
 */
void exit_status(char *cmd)
{
	if (strncmp(cmd, "exit", 4) == 0)
	{
		char *a = cmd + 4;

		while (*a != '0' && (*a == '\t' || *a == ' '))
		{
			a++;
		}

		if (*a == '\0')
		{
			exit_me(0);
		}
		else
		{
			int state;

			if (sscanf(a, "%d", &state) == 1)
			{
				exit_me(state);
			}
			else
			{
				_printme("Invalid exit:%s\n", a);
			}
		}
	}
	else if (strcmp(cmd, "exit") == 0)
	{
		exit_me(0);
	}
}


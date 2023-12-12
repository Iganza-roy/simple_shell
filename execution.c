#include "shell.h"

/**
 * execute_cmd - ...
 * @cmd: ...
 */
pid_t execute_cmd(char *cmd)
{
	pid_t c_pid = fork();

	if (c_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (c_pid == 0)
	{
		char **a = malloc(2 * sizeof(char *));

		if (a == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		a[0] = cmd;
		a[1] = NULL;

		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		int state;
		waitpid(c_pid, &state, 0);

		if (WIFEXITED(state))
		{
			return (WEXITSTATUS(state));
		}
		else
		{
			return (-1);
		}
	}
}

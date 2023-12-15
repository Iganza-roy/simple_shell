#include "shell.h"

/**
 * execute_cmd - executes process
 * @cmd: command
 */
void execute_cmd(const char *cmd)
{
	pid_t c_pid = fork();

	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

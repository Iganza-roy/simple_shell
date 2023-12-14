#include "shell.h"

/**
 * _exe - executes commands
 * @cmd: command
 * @cmds: array that points to commands
 * Return: Always 0 (Success)
 */
void _exe(char *cmd, char **cmds)
{
	pid_t c_pid;
	int state;
	char **env = environ;

	c_pid = fork();

	if (c_pid < 0)
		perror(cmd);

	if (c_pid == 0)
	{
		execve(cmd, cmds, env);
		perror(cmd);
		free(cmd);
		free_me(cmds);
		exit(98);
	}
	else
	{
		wait(&state);
	}
}

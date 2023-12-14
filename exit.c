#include "shell.h"

/**
 * exit_me - exits cmd
 * @cmd: command
 * @l: read line
 */
void exit_me(char **cmd, char *l)
{
	free(l);
	free_me(cmd);
	exit(0);
}

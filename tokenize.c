#include "shell.h"

/**
 * tokenize_cmd - ....
 * @cmd_line: ...
 */

void tokenize_cmd(char *cmd_line)
{
	char *arguments[MAX_TOKEN_SIZE], *tkn;
	int ac = 0;

	tkn = strtok(cmd_line, " ");

	while (tkn != NULL)
	{
		arguments[ac++] = tkn;
		tkn = strtok(NULL, " ");
	}
	arguments[ac] = NULL;

	pid_t c_pid = fork();

	if (c_pid == 0)
	{
		execvp(arguments[0], arguments);
		perror("erroe");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

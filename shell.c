#include "shell.h"

/**
 * @main: ...
 * Return: ...
 */
int main(void)
{
	char *got_line;
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		user_prompt();
		read_cmd(cmd, sizeof(cmd));
		tokenize_cmd(cmd);
		exit_status(cmd);
		/*Handle cd*/
		if (strncmp(cmd, "cd", 2) == 0)
		{
			char *arg = strtok(cmd + 2, " \t");
			_cd(arg);
		}
	}
	/* implement getline function*/
	do {
		got_line = get_line();
		if (got_line != NULL)
		{
			write(STDOUT_FILENO, got_line, strlen(got_line));
			free(got_line);
		}
	} while (got_line != NULL);

	return (0);
}

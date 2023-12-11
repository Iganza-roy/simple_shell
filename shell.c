#include "shell.h"

/**
 * @main: ...
 * Return: ...
 */
int main(void)
{
	char *got_line;
	char *args;
	char cmd[MAX_CMD_LEN];
	char cmd_line[MAX_TOKEN_SIZE];
	//char *args[MAX_TOKEN_SIZE];
	//int argc;

	while (1)
	{
		user_prompt();
		read_cmd(cmd, sizeof(cmd));
		tokenize_cmd(cmd);
		exit_status(cmd);
	//	execute_cmd(cmd);
		/*Handle cd*/
		if (strncmp(cmd, "cd", 2) == 0)
		{
			args = strtok(cmd + 2, " \t");
			_cd(args);
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

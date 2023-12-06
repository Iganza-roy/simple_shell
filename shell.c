#include "shell.h"

/**
 * @main: ...
 * Return: ...
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char cmd_line[MAX_TOKEN_SIZE];

	while (1)
	{
		user_prompt();
		read_cmd(cmd, sizeof(cmd));
		tokenize_cmd(cmd);
		//execute_cmd(cmd);
		if (strcmp(cmd, "exit") == 0)
		{
			exit_me();
		}
		else if (strcmp(cmd, "env") == 0)
		{
			print_env();
		}

	}

	return (0);
}

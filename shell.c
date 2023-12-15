#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		_promptme();
		read_cmd(cmd, sizeof(cmd));
		execute_cmd(cmd);
	}
	return (0);
}

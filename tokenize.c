#include "shell.h"

/**
 * tokenize_cmd - splits  a string into tockens
 * @cmd_line: command inputed
 */

void tokenize_cmd(char *cmd_line)
{
	char *args[MAX_TOKEN_SIZE];
	int argc = 0;
	int fr;

	char *token = cmd_line;

	while (*token != '\0')
	{
		while (*token == ' ' || *token == '\n' || *token == '\t')
		{
			token++;
		}

		if (*token == '\0')
		{
			break;
		}

		char *last = token;

		while (*last != '\0' && *last != ' ' && *last != '\n' && *last != '\t')
		{
			last++;
		}

		size_t tkn_len = last - token;
		args[argc] = malloc(tkn_len + 1);
		strncpy(args[argc], token, tkn_len);
		args[argc][tkn_len] = '\0';
		argc++;

		token = last;
	}
	args[argc] = NULL;

	pid_t c_pid = fork();

	if (c_pid == 0)
	{
		execvp(args[0], args);
		/*perror("error");*/
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	for (fr = 0; fr < argc; fr++)
	{
		free(args[fr]);
	}
}

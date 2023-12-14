#include "shell.h"

/**
 * main - entry point for main logic
 * @argc: argument counter
 * @argv: argument vector
 * @envv: env vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv, char *envv[])
{
<<<<<<< HEAD
	char *l = NULL, *p_cmd = NULL, *p = NULL;
	size_t bf_size = 0;
	ssize_t l_size = 0;
	char **cmd = NULL, **ps = NULL;
	(void)envv, (void)argv;

	if (argc < 1)
		return (-1);
	signal(SIGINT, signal_me);
	while (1)
	{
		free_me(cmd);
		free_me(ps);
		free(p_cmd);
		_prompt();
		l_size = getline(&l, &bf_size, stdin);
		if (l_size < 0)
			break;
		x.lc++;
		if (l[l_size - 1] == '\n')
			l[l_size] = '\0';
		cmd = tokenize_me(l);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (b_helper(cmd, l))
			continue;
		p = path_finder();
		ps = tokenize_me(p);
		p_cmd = path_test(ps, cmd[0]);
		if (!p_cmd)
			perror(argv[0]);
		else
			_exe(p_cmd, cmd);
=======
	char *got_line;
	char cmd[MAX_CMD_LEN];
	in inf;
	inf.is_itrv = isatty(STDIN_FILENO) &&isatty(STDOUT_FILENO);
	while (1)
	{
		user_prompt(&inf);
		read_cmd(cmd, sizeof(cmd));
		tokenize_cmd(cmd);
		exit_status(cmd);
		execute_cmd(cmd);
		/*Handle cd*/
		if (_strncmp(cmd, "cd", 2) == 0)
		{
			char *arg = strtok(cmd + 2, " \t");
			_cd(arg);
		}
>>>>>>> 7e25e2440cf36957b79543d742ce79dfb9c8e29a
	}
	if (l_size < 0 && fg.interact)
		write(STDERR_FILENO, "\n", 1);
	free(l);

	return (0);
}

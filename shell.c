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
	}
	if (l_size < 0 && fg.interact)
		write(STDERR_FILENO, "\n", 1);
	free(l);

	return (0);
}

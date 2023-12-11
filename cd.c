#include "shell.h"

/**
 * _cd - ...
 * @dir: ...
 */
void _cd(const char *dir)
{
	char *n_dir;

	if (dir == NULL)
	{
		n_dir = getenv("HOME");

		if (n_dir == NULL)
		{
			return;
		}
	}
	else if (strcmp(dir, "-") == 0)
	{
		n_dir = getenv("OLDPWD");

		if (n_dir == NULL)
		{
			return;
		}
		_printme("%s\n", n_dir);
		return;
	}
	else
	{
		n_dir = (char *)dir;
	}
	char curr_dir[MAX_CMD_LEN];
	getcwd(curr_dir, sizeof(curr_dir));
	setenv("OLDPWD", curr_dir, 1);

	if (chdir(n_dir) != 0)
	{
		perror("cd");
	}
	else
	{
		setenv("PWD", n_dir, 1);
	}
}

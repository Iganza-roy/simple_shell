#include "shell.h"

/**
 * SL - loops main function
 * @infolist: ....
 * @argument_v: ..
 * Return: ...
 */
int SL(infolist_t *infolist, char **argument_v)
{
	ssize_t x = 0;
	int result = 0;

	while (x != -1 && result != -2)
	{
		info_clear(infolist);

		if (IsInteractive(infolist))
			pts("$ ");
		erprchar(bufferFlush);
		x = _get_in(infolist);
		if (x != -1)
		{
			info_set(infolist, argument_v);

			result = findBuiltinCom(infolist);

			if (result == -1)
				chkps(infolist);
		}
		else if (IsInteractive(infolist))
			ptchr('\n');
		info_free(infolist, 0);
	}
	his_wr(infolist);
	info_free(infolist, 1);
	if (!IsInteractive(infolist) && infolist->my_status)
		exit(infolist->my_status);
	if (result == -2)
	{
		if (infolist->err_code == -1)
			exit(infolist->my_status);
		exit(infolist->err_code);
	}
	return (result);
}

/**
 * findBuiltinCom -  ...
 * @infolist: ...
 * Return: ...
 */
int findBuiltinCom(infolist_t *infolist)
{
	int x, builtInRet = -1;

	stracOfBuildIn builtInTabl[] = {
		{"exit", ex_eml},
		{"env", _env_mine},
		{"help", h_eml},
		{"history", his_eml},
		{"setenv", _set_env},
		{"unsetenv", _unset_env},
		{"cd", cd_eml},
		{"alias", al_eml},
		{NULL, NULL}
	};

	for (x = 0; builtInTabl[x].flag; x++)
		if (cmpstr(infolist->argument_v[0], builtInTabl[x].flag) == 0)
		{
			infolist->err_line_num++;
			builtInRet = builtInTabl[x].function(infolist);
			break;
		}
	return (builtInRet);
}

/**
 * chkps - ...
 * @infolist: ...
 */
void chkps(infolist_t *infolist)
{
	char *str_path = NULL;
	int x, y;

	infolist->str_path = infolist->argument_v[0];

	if (infolist->linenumflag == 1)
	{
		infolist->err_line_num++;
		infolist->linenumflag = 0;
	}
	for (x = 0, y = 0; infolist->argument[x]; x++)
		if (!IsDelimeter(infolist->argument[x], " \t\n"))
			y++;
	if (!y)
		return;

	str_path = fpth(infolist, getEnv(infolist, "PATH="),
	infolist->argument_v[0]);
	if (str_path)
	{
		infolist->str_path = str_path;
		fkthrd(infolist);
	}
	else
	{
		if ((IsInteractive(infolist) || getEnv(infolist, "PATH=")
			|| infolist->argument_v[0][0] == '/') &&
			iscommand(infolist, infolist->argument_v[0]))
			fkthrd(infolist);
		else if (*(infolist->argument) != '\n')
		{
			infolist->my_status = 127;
			PrintError(infolist, "not found\n");
		}
	}
}

/**
 * fkthrd - new process
 * @infolist: ...
 */
void fkthrd(infolist_t *infolist)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infolist->str_path, infolist->argument_v,
		our_environ(infolist)) == -1)
		{
			info_free(infolist, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(infolist->my_status));

		if (WIFEXITED(infolist->my_status))
		{
			infolist->my_status = WEXITSTATUS(infolist->my_status);

			if (infolist->my_status == 126)
				PrintError(infolist, "Permission denied\n");
		}
	}
}

#include "shell.h"

/**
 * ex_eml - ...
 * @infolist: ...
 * Return: ...
 */
int ex_eml(infolist_t *infolist)
{
	int checkExit;

	if (infolist->argument_v[1])
	{
		checkExit = StringToInteger(infolist->argument_v[1]);

		if (checkExit == -1)
		{
			infolist->my_status = 2;
			PrintError(infolist, "Illegal number: ");
			Printstrer(infolist->argument_v[1]);
			erprchar('\n');
			return (1);
		}
		infolist->err_code = StringToInteger(infolist->argument_v[1]);
		return (-2);
	}

	infolist->err_code = -1;
	return (-2);
}

/**
 * cd_eml - ...
 * @infolist: ...
 *  Return: ...
 */
int cd_eml(infolist_t *infolist)
{
char *str, *directory, myBuff[1024];
int ret_dir;

str = getcwd(myBuff, 1024);/*get current working directory.*/
if (!str)
	pts("TODO: >>getcwd failure emsg here<<\n");
if (!infolist->argument_v[1])
{
	directory = getEnv(infolist, "HOME=");
	if (!directory)
		ret_dir =
		chdir((directory = getEnv(infolist, "PWD=")) ? directory : "/");
	else
	ret_dir = chdir(directory);
}
else if (cmpstr(infolist->argument_v[1], "-") == 0)
{
	if (!getEnv(infolist, "OLDPWD="))
	{
		pts(str);
		ptchr('\n');
		return (1);
	}
	pts(getEnv(infolist, "OLDPWD=")), ptchr('\n');
	ret_dir =
		chdir((directory = getEnv(infolist, "OLDPWD=")) ? directory : "/");
}
else
	ret_dir = chdir(infolist->argument_v[1]);
if (ret_dir == -1)
{
	PrintError(infolist, "can't cd to ");
	Printstrer(infolist->argument_v[1]), erprchar('\n');
}
else
{
	_envvarinit(infolist, "OLDPWD", getEnv(infolist, "PWD="));
	_envvarinit(infolist, "PWD", getcwd(myBuff, 1024));
}
return (0);
}

/**
 * h_eml - ...
 * @infolist: ...
 * Return: ...
 */
int h_eml(infolist_t *infolist)
{
	char **arrayArgument;

	arrayArgument = infolist->argument_v;
pts("This is for the help command.but Functionality not implemented yet.\n");

	if (0)
		pts(*arrayArgument);
	return (0);
}

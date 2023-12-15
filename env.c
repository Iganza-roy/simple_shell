#include "shell.h"

/**
 * _env_mine - ...
 * @infolist: ...
 * Return: ...
 */
int _env_mine(infolist_t *infolist)
{
	_strlistpr(infolist->envir);
	return (0);
}

/**
 * getEnv - ...
 * @infolist: ...
 * @var_name: ...
 * Return: ...
 */
char *getEnv(infolist_t *infolist, const char *var_name)
{
	stringlist_t *my_node = infolist->envir;
	char *ptr;

	while (my_node)
	{
		ptr = startsWith(my_node->string, var_name);
		if (ptr && *ptr)
			return (ptr);

		my_node = my_node->next_node;
	}
	return (NULL);
}

/**
 * _set_env - ...
 * @infolist: ...
 * Return: ...
 */
int _set_env(infolist_t *infolist)
{
	if (infolist->argument_c != 3)
	{
		errPrintStr("Few args\n");
		return (1);
	}
	if (_envvarinit(infolist, infolist->argument_v[1],
	infolist->argument_v[2]))
		return (0);
	return (1);
}

/**
 * _unset_env - ...
 * @infolist: ...
 * Return: ...
 */
int _unset_env(infolist_t *infolist)
{
	int x;

	if (infolist->argument_c == 1)
	{
		errPrintStr("one arg\n");
		return (1);
	}

	for (x = 1; x <= infolist->argument_c; x++)
		_environ_rem(infolist, infolist->argument_v[x]);

	return (0);
}

/**
 * _envlist_pop - ...
 * @infolist: ...
 * Return: ...
 */
int _envlist_pop(infolist_t *infolist)
{
	stringlist_t *my_node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		ADDnodeEn(&my_node, environ[x], 0);
	infolist->envir = my_node;

	return (0);
}

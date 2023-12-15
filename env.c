#include "shell.h"

/**
 * my_env - ...
 * @infolist: ...
 * Return: ...
 */
int my_env(infolist_t *infolist)
{
	printListString(infolist->envir);
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
 * mySetEnv - ...
 * @infolist: ...
 * Return: ...
 */
int mySetEnv(infolist_t *infolist)
{
	if (infolist->argument_c != 3)
	{
		errPrintStr("Few args\n");
		return (1);
	}
	if (init_env_var(infolist, infolist->argument_v[1],
	infolist->argument_v[2]))
		return (0);
	return (1);
}

/**
 * unSetEnv - ...
 * @infolist: ...
 * Return: ...
 */
int unSetEnv(infolist_t *infolist)
{
	int x;

	if (infolist->argument_c == 1)
	{
		errPrintStr("one arg\n");
		return (1);
	}

	for (x = 1; x <= infolist->argument_c; x++)
		remov_environ(infolist, infolist->argument_v[x]);

	return (0);
}

/**
 * populateEnvList - ...
 * @infolist: ...
 * Return: ...
 */
int populateEnvList(infolist_t *infolist)
{
	stringlist_t *my_node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		ADDnodeEn(&my_node, environ[x], 0);
	infolist->envir = my_node;

	return (0);
}

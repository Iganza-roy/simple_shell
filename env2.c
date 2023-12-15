#include "shell.h"


/**
 * our_environ - ...
 * @infolist: ...
 * Return: ...
 */
char **our_environ(infolist_t *infolist)
{
	if (!infolist->environ || infolist->isenvchange)
	{
		infolist->environ = listToStrings(infolist->envir);
		infolist->isenvchange = 0;
	}
	return (infolist->environ);
}

/**
 * remov_environ - ...
 * @infolist: ...
 * @var_prop: ...
 * Return: ...
 */
int remov_environ(infolist_t *infolist, char *var_prop)
{
	stringlist_t *my_node = infolist->envir;
	size_t x = 0;
	char *ptr;

	if (!my_node || !var_prop)
		return (0);

	while (my_node)
	{
		ptr = startsWith(my_node->string, var_prop);
		if (ptr && *ptr == '=')
		{
			infolist->isenvchange = deletNode(&(infolist->envir), x);
			x = 0;
			my_node = infolist->envir;
			continue;
		}
		my_node = my_node->next_node;
		x++;
	}
	return (infolist->isenvchange);
}

/**
 * init_env_var - ...
 * @infolist: ...
 * @var_prop: ...
 * @var_value: ...
 * Return: ...
 */
int init_env_var(infolist_t *infolist, char *var_prop, char *var_value)
{
	char *ptr;
	char *mybuff = NULL;
	stringlist_t *my_node;

	if (!var_prop || !var_value)
		return (0);

	mybuff = malloc(getStringLength(var_prop) + getStringLength(var_value) + 2);
	if (!mybuff)
		return (1);

	copyStrings(mybuff, var_prop);
	concatenetStrings(mybuff, "=");
	concatenetStrings(mybuff, var_value);
	my_node = infolist->envir;
	while (my_node)
	{
		ptr = startsWith(my_node->string, var_prop);
		if (ptr && *ptr == '=')
		{
			free(my_node->string);
			my_node->string = mybuff;
			infolist->isenvchange = 1;
			return (0);
		}
		my_node = my_node->next_node;
	}
	ADDnodeEn(&(infolist->envir), mybuff, 0);
	free(mybuff);
	infolist->isenvchange = 1;
	return (0);
}

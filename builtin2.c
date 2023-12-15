#include "shell.h"

/**
 * historyEmulator - ...
 * @infolist: ...
 * Return: ...
 */
int historyEmulator(infolist_t *infolist)
{
	elementList(infolist->my_history);
	return (0);
}

/**
 * removeAlias - ...
 * @infolist: ...
 * @string: ...
 * Return: ...
 */
int removeAlias(infolist_t *infolist, char *string)
{
	int restr;
	char *ptr, chr;

	ptr = locateChar(string, '=');
	if (!ptr)
		return (1);

	chr = *ptr;
	*ptr = 0;

	restr = deletNode(&(infolist->my_alias),
		nodeIndex(infolist->my_alias,
		nodeStartWith(infolist->my_alias, string, -1)));

	*ptr = chr;
	return (restr);
}

/**
 * defineAlias - ...
 * @infolist: ...
 * @string: ...
 * Return: ...
 */
int defineAlias(infolist_t *infolist, char *string)
{
	char *ptr;

	ptr = locateChar(string, '=');
	if (!ptr)
		return (1);

	if (!*++ptr)
		return (removeAlias(infolist, string));

	removeAlias(infolist, string);
	return (ADDnodeEn(&(infolist->my_alias), string, 0) == NULL);
}

/**
 * prtAlias - ...
 * @my_node: ...
 * Return: ...
 */
int prtAlias(stringlist_t *my_node)
{
	char *ptr = NULL, *m = NULL;

	if (my_node)
	{
		ptr = locateChar(my_node->string, '=');

		for (m = my_node->string; m <= ptr; m++)
			PutCharacter(*m);

		PutCharacter('\'');
		Puts(ptr + 1);
		Puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * aliasEmulator - ...
 * @infolist: ...
 * Return: ...
 */
int aliasEmulator(infolist_t *infolist)
{
	char *ptr = NULL;
	int x = 0;
	stringlist_t *my_node = NULL;

	if (infolist->argument_c == 1)
	{
		my_node = infolist->my_alias;
		while (my_node)
		{
			prtAlias(my_node);
			my_node = my_node->next_node;
		}
		return (0);
	}

	for (x = 1; infolist->argument_v[x]; x++)
	{
		ptr = locateChar(infolist->argument_v[x], '=');

		if (ptr)
			defineAlias(infolist, infolist->argument_v[x]);
		else
			prtAlias(nodeStartWith(infolist->my_alias,
		infolist->argument_v[x], '='));
	}
	return (0);
}

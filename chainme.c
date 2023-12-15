#include "shell.h"

/**
 * isChain - ...
 * @infolist: ...
 * @mybuff: ...
 * @ptr: ...
 * Return: ...
 */
int isChain(infolist_t *infolist, char *mybuff, size_t *ptr)
{
	size_t z = *ptr;

	if (mybuff[z] == '|' && mybuff[z + 1] == '|')
	{
		mybuff[z] = 0;
		z++;
		infolist->cmdBufferTybe = orChain;
	}
	else if (mybuff[z] == '&' && mybuff[z + 1] == '&')
	{
		mybuff[z] = 0;
		z++;
		infolist->cmdBufferTybe = andChain;
	}
	else if (mybuff[z] == ';')
	{
		mybuff[z] = 0;
		infolist->cmdBufferTybe = cmdChain;
	}
	else
		return (0);

	*ptr = z;

	return (1);
}

/**
 * checkChain - ...
 * @infolist: ...
 * @mybuff: ...
 * @ptr: ...
 * @x: ...
 * @mylen: ...
 */
void checkChain(infolist_t *infolist, char *mybuff, size_t *ptr, size_t x,
size_t mylen)
{
	size_t z = *ptr;

	if (infolist->cmdBufferTybe == andChain)
	{
		if (infolist->my_status)
		{
			mybuff[x] = 0;
			z = mylen;
		}
	}

	if (infolist->cmdBufferTybe == orChain)
	{
		if (!infolist->my_status)
		{

			mybuff[x] = 0;
			z = mylen;
		}
	}

	*ptr = z;
}

/**
 * replaceAlies - ...
 * @infolist: ...
 * Return: ...
 */
int replaceAlies(infolist_t *infolist)
{
	int x;
	stringlist_t *my_node;
	char *ptr;

	for (x = 0; x < 10; x++)
	{

	my_node = nodeStartWith(infolist->my_alias, infolist->argument_v[0], '=');
	if (!my_node)
		return (0);

	free(infolist->argument_v[0]);

	ptr = locateChar(my_node->string, '=');
	if (!ptr)
		return (0);

	ptr = duplcatString(ptr + 1);
	if (!ptr)
		return (0);
	infolist->argument_v[0] = ptr;
	}

	return (1);
}

/**
 * replaVars - ...
 * @infolist: ...
 * Return: ...
 */
int replaVars(infolist_t *infolist)
{
	int x = 0;
	stringlist_t *my_node;

	for (x = 0; infolist->argument_v[x]; x++)
	{

	if (infolist->argument_v[x][0] != '$' || !infolist->argument_v[x][1])
		continue;

	if (!compareStrings(infolist->argument_v[x], "$?"))
	{
		replaStr(&(infolist->argument_v[x]),
			duplcatString(convert_number(infolist->my_status, 10, 0)));
		continue;
	}

	if (!compareStrings(infolist->argument_v[x], "$$"))
	{
		replaStr(&(infolist->argument_v[x]),
			duplcatString(convert_number(getpid(), 10, 0)));
		continue;
	}

	my_node = nodeStartWith(infolist->envir, &infolist->argument_v[x][1], '=');
	if (my_node)
	{
		replaStr(&(infolist->argument_v[x]),
			duplcatString(locateChar(my_node->string, '=') + 1));
		continue;
	}

	replaStr(&infolist->argument_v[x], duplcatString(""));

	}
	return (0);
}

/**
 * replaStr - ...
 * @_old_str: ...
 * @new_str: ...
 * Return: ...
 */
int replaStr(char **_old_str, char *new_str)
{
	free(*_old_str);
	*_old_str = new_str;
	return (1);
}


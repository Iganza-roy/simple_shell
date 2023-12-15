#include "shell.h"


/**
 * clearInformation - ...
 * @infolist: ...
 */
void clearInformation(infolist_t *infolist)
{
	infolist->argument = NULL;
	infolist->argument_v = NULL;
	infolist->str_path = NULL;
	infolist->argument_c = 0;
}

/**
 * setInformation - ...
 * @infolist: ...
 * @arg_vec: ...
 */
void setInformation(infolist_t *infolist, char **arg_vec)
{
	int x = 0;

	infolist->filename = arg_vec[0];

	if (infolist->argument)
	{
		infolist->argument_v = SplitString(infolist->argument, " \t");

		if (!infolist->argument_v)
		{
			infolist->argument_v = malloc(sizeof(char *) * 2);
			if (infolist->argument_v)
			{
				infolist->argument_v[0] = duplcatString(infolist->argument);
				infolist->argument_v[1] = NULL;
			}
		}
		for (x = 0; infolist->argument_v && infolist->argument_v[x]; x++)
			;
		infolist->argument_c = x;

		replaceAlies(infolist);
		replaVars(infolist);
	}
}

/**
 * freeInformation - ...
 * @infolist: ...
 * @alllist: ...
 */
void freeInformation(infolist_t *infolist, int alllist)
{
	freeFun(infolist->argument_v);
	infolist->argument_v = NULL;

	infolist->str_path = NULL;

	if (alllist)
	{
		if (!infolist->cmdBuffer)
			free(infolist->argument);

		if (infolist->envir)
			freeList(&(infolist->envir));

		if (infolist->my_history)
			freeList(&(infolist->my_history));

		if (infolist->my_alias)
			freeList(&(infolist->my_alias));

		freeFun(infolist->environ);
			infolist->environ = NULL;

		freePointers((void **)infolist->cmdBuffer);
		if (infolist->rfd > 2)
			close(infolist->rfd);

		PutCharacter(bufferFlush);
	}
}

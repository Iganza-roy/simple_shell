#include "shell.h"

/**
 * tokenize_me - creates tokens
 * @l: line to be tokenized
 * Return: strings array
 */
char **tokenize_me(char *l)
{
	char *bf1 = NULL, *bf2 = NULL, *tkn = NULL, *whites = " :\t\r\n";
	size_t i = 0, fg = 0;
	int tkn_size = 1;
	char **tkns = NULL;

	bf1 = _strdup(l);
	if (!bf1)
		return (NULL);
	bf2 = bf1;

	while (*bf2)
	{
		if (_strchr(whites, *bf2) != NULL && fg == 0)
		{
			tkn_size++;
			fg = 1;
		}
		else if (_strchr(whites, *bf2) == NULL && fg == 1)
			fg = 0;
		bf2++;
	}

	tkns = malloc(sizeof(char *) * (tkn_size + 1));
	tkn = strtok(bf1, whites);

	while (tkn)
	{
		tkns[i] = _strdup(tkn);
		if (tkns[i] == NULL)
		{
			free(tkns);
			return (NULL);
		}
		tkn = strtok(NULL, whites);
		i++;
	}
	tkns[i] = '\0';
	free(bf1);
	return (tkns);
}

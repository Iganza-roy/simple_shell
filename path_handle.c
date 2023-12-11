#include "shell.h"

/**
 * mk_path - creates a path list
 * @pth: the path address
 * @del: separator
 * Return: head
 */
struct node *mk_path(char *pth, char del)
{
	struct node *h = NULL;
	struct node *t = NULL;

	char *dir;

	dir = strtok(pth, &del);
	while (dir != NULL)
	{
		struct node *nnode;

		nnode = malloc(sizeof(struct node));
		nnode->dir = strdup(dir);
		nnode->next = NULL;
		if (h == NULL)
		{
			h = nnode;
			t = nnode;
		}
		else
		{
			t->next = nnode;
			t = nnode;
		}

		dir = strtok(NULL, &del);
	}

	return (h);
}

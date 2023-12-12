#include "shell.h"

int path(void)
{
	struct node *h = NULL;
	struct node *current;
	struct node *next;

	current = h;

	while (current != NULL)
	{
		_printme("%s\n", current->dir);
		current = current->next;
	}

	while (h != NULL)
	{
		next = h->next;
		free(h->dir);
		free(h);
		h = next;
	}
	return (0);
}

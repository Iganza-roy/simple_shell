#include "shell.h"

int path(void)
{
	struct node *h;

	struct node *current = h;

	while (current != NULL)
	{
		printf("%s\n", current->dir);
		current = current->next;
	}

	struct node *next;

	while (h != NULL)
	{
		next = h->next;
		free(h->dir);
		free(h);
		h = next;
	}
	return (0);
}

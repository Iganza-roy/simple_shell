#include "shell.h"

/**
 * ADDnode - adds node
 * @firstNode: ...
 * @string: ...
 * @number: ...
 * Return: ....
 */
stringlist_t *ADDnode(stringlist_t **firstNode, const char *string, int number)
{
	stringlist_t *newHead;

	if (!firstNode)
		return (NULL);

	newHead = malloc(sizeof(stringlist_t));
	if (!newHead)
		return (NULL);

	fillMemoryWith((void *)newHead, 0, sizeof(stringlist_t));

	newHead->number = number;

	if (string)
	{
		newHead->string = duplcatString(string);
		if (!newHead->string)
		{

			free(newHead);
			return (NULL);
		}
	}
	newHead->next_node = *firstNode;
	*firstNode = newHead;

	return (newHead);
}

/**
 * ADDnodeEn - adds end node
 * @firstNode: .
 * @string: ..
 * @number: ..
 * Return: ...
 */
stringlist_t *ADDnodeEn(stringlist_t **firstNode,
		const char *string, int number)
{
	stringlist_t *newNode, *currentNode;

	if (!firstNode)
		return (NULL);

	currentNode = *firstNode;

	newNode = malloc(sizeof(stringlist_t));
	if (!newNode)
		return (NULL);
	
	fillMemoryWith((void *)newNode, 0, sizeof(stringlist_t));

	newNode->number = number;

	if (string)
	{
		newNode->string = duplcatString(string);
		if (!newNode->string)
		{
			free(newNode);
			return (NULL);
		}
	}

	if (currentNode)
	{
		while (currentNode->next_node)
			currentNode = currentNode->next_node;
		currentNode->next_node = newNode;
	}
	else
		*firstNode = newNode;

	return (newNode);
}

/**
 * printListString - ...
 * @head: ...
 * Return: ..
 */
size_t printListString(const stringlist_t *head)
{
	size_t x = 0;

	while (head)
	{
		Puts(head->string ? head->string : "(Null)");
		Puts("\n");
		head = head->next_node;
		x++;
	}
	return (x);
}

/**
 * deletNode - ...
 * @firstNode: ...
 * @nodeindex: ...
 * Return: ...
 */
int deletNode(stringlist_t **firstNode, unsigned int nodeindex)
{
	stringlist_t *currentNode, *previousNode;
	unsigned int x = 0;


	if (!firstNode || !*firstNode)
		return (0);

	if (!nodeindex)
	{
		currentNode = *firstNode;
		*firstNode = (*firstNode)->next_node;
		free(currentNode->string);
		free(currentNode);
		return (1);
	}

	currentNode = *firstNode;
	while (currentNode)
	{
		if (x == nodeindex)
		{
			previousNode->next_node = currentNode->next_node;
			free(currentNode->string);
			free(currentNode);
			return (1);
		}
		x++;
		previousNode = currentNode;
		currentNode = currentNode->next_node;
	}

	return (0);
}

/**
 * freeList - ...
 * @headPointr: ...
 */
void freeList(stringlist_t **headPointr)
{
	stringlist_t *currentNode, *nextNode, *firstNode;

	if (!headPointr || !*headPointr)
		return;

	firstNode = *headPointr;
	currentNode = firstNode;

	while (currentNode)
	{
		nextNode = currentNode->next_node;
		free(currentNode->string);
		free(currentNode);
		currentNode = nextNode;
	}

	*headPointr = NULL;
}



#include "shell.h"

/**
 * _putchar - writes char to stdout
 * @c: print
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printme - prints string
 * @str: string
 * Return: number of characters
 */
int _printme(char *str)
{
	int x = 0;

	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}

	return (x);
}

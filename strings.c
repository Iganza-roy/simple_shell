#include "shell.h"

/**
 * _strcspn - return len of initial str segment
 * @s1: string 1
 * @s2: string 2
 * Return: len
 */
size_t _strcspn(const char *s1, const char *s2)
{
	size_t len = 0, i;

	while (s1[len] != '\0')
	{
		i = 0;

		while (s2[i] != '\0')
		{
			if (s1[len] == s2[i])
			{
				return (len);
			}
			i++;
		}
		len++;
	}
	return (len);
}

/**
 * _strlen - calculates string length
 * @s: string
 * Return: len
 */
size_t _strlen(const char *s)
{
	size_t len = 0;


	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

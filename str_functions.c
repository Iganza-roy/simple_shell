#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be counted
 * Return: length of the string
 */

int _strlen(char *s)
{
	int k;
	int cnt = 0;

	for (k = 0; s[k] != '\0'; k++)
		cnt++;
	return (cnt);
}

#include "shell.h"

/**
 *_strcpy - copies string to the buffer
 * @dest: destiation
 * @src: source
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int k;

	for (k = 0; src[k] != '\0'; k++)
		dest[k] = src[k];
	dest[k] = '\0';
	return (dest);
}

#include "shell.h"

/**
 * _strcat -  appends the source string to the destination string
 * @src: source string
 * @dest: destination string
 * Return: the new string
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int srclen = 0;
	int deslen = 0;

	for (i = 0; dest[i] != '\0'; i++)
		deslen++;
	for (i = 0; src[i] != '\0'; i++)
		srclen++;
	for (i = 0; i <= srclen; i++)
		dest[deslen + i] = src[i];
	return (dest);
}

#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 on success
 */

int _strcmp(char *s1, char *s2)
{
	int k;

	for (k = 0; s1[k] != '\0' || s2[k] != '\0'; k++)
	{
		if (s1[k] != s2[k])
		{
			if (s1[k] < s2[k])
				return (s1[k] - s2[k]);
			else if (s2[k] < s1[k])
				return (s1[k] - s2[k]);
		}
	}
	return (0);
}

/**
 * _strncmp - compares strings of n bytes
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes
 * Return: copied string
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * _strncpy - copies string of n bytes
 * @dest: destination
 * @src: source
 */
void _strncpy(char *dest, char *src, size_t n)
{
	size_t x;

	for (x = 0; x < n && src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}

	for (; x < n; ++x)
	{
		dest[x] = '\0';
	}
}

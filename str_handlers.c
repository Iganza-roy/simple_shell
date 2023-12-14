#include "shell.h"

/**
 * _strcmp - compares str 1 & str2
 * @str1: string 1
 * @str2: string 2
 * Return: Difference of str1 and str2
 */
int _strcmp(char *str1, char *str2)
{
	int x = 0;
	int result;

	while (*(str1 + x) == *(str2 + x) && *(str1 + x) != '\0')
	{
		x++;
	}

	result = (*(str1 + x) - *(str2 + x));

	return (result);
}

/**
 * _strlen - returns string length
 * @str: string
 * Return: length of string
 */
int _strlen(char *str)
{
	int x = 0;

	while (*str != '\0')
	{
		x++;
		str++;
	}
	return (x);
}

/**
 * _strncmp - compares str1 and str2 of n bytes
 * @str1: string 1
 * @str2: string 2
 * @n: bytes to br compared
 * Return: compared bytes
 */
int _strncmp(char *str1, char *str2, int n)
{
	int x;

	for (x = 0; str1[x] && str2[x] && x < n; x++)
	{
		if (str1[x] != str2[x])
		{
			return (str1[x] - str2[x]);
		}
	}

	return (0);
}

/**
 * _strchr - locates a char in str
 * @str: to be extracted from
 * @s: character to be extracted
 * Return: pointer to 1st occurence of s
 */
char *_strchr(char *str, char s)
{
	while (*str)
	{
		if (*str == s)
		{
			return (str);
		}
		str++;
	}

	if (!s)
		return (str);
	return (NULL);
}

/**
 * _strdup - duplicates str
 * @str: duplicated
 * Return: pointer to dup str
 */
char *_strdup(char *str)
{
	char *s;
	int x, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	s = malloc(sizeof(char) * (len + 1));

	if (!s)
		return (NULL);

	for (x = 0; *str != '\0'; str++, x++)
		s[x] = str[0];

	s[x++] = '\0';
	return (s);
}

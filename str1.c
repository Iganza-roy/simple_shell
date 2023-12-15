#include "shell.h"

/**
 * strl - str len
 * @str_ch: ...
 * Return: ...
 */
int strl(char *str_ch)
{
	int length = 0;

	if (!str_ch)
		return (0);

	while (*str_ch++)
		length++;
	return (length);
}

/**
 * cmpstr - ...
 * @strone: ...
 * @strtwo: ...
 * Return: ...
 */
int cmpstr(char *strone, char *strtwo)
{
	while (*strone && *strtwo)
	{
		if (*strone != *strtwo)
			return (*strone - *strtwo);

		strone++;
		strtwo++;
	}

	if (*strone == *strtwo)
		return (0);
	else
		return (*strone < *strtwo ? -1 : 1);
}

/**
 * startsWith - ...
 * @check_str: ...
 * @prefix_in: ...
 * Return: ...
 */
char *startsWith(const char *check_str, const char *prefix_in)
{
	while (*prefix_in)
		if (*prefix_in++ != *check_str++)
			return (NULL);

	return ((char *)check_str);
}

/**
 * concatenetStrings - strcat
 * @destination: ...
 * @source: ...
 * Return: strcat
 */
char *concatenetStrings(char *destination, char *source)
{
	char *res = destination;

	while (*destination)
		destination++;

	while (*source)
		*destination++ = *source++;

	*destination = *source;

	return (res);
}

/**
 * StringCopy - ...
 * @destination: ...
 * @source: src
 * @max_char: ...
 * Return: ...
 */
char *StringCopy(char *destination, char *source, int max_char)
{
	int x, y;
	char *str_ch = destination;

	x = 0;

	while (source[x] != '\0' && x < max_char - 1)
	{
		destination[x] = source[x];
		x++;
	}

	if (x < max_char)
	{
		y = x;
		while (y < max_char)
		{
			destination[y] = '\0';
			y++;
		}
	}
	return (str_ch);
}

#include "shell.h"

/**
 * concatenatesStrings - ...
 * @str_one: ..
 * @str_two: ..
 * @byt_num: ...
 * Return: ...
 */
char *concatenatesStrings(char *str_one, char *str_two, int byt_num)
{
	int x, y;
	char *z = str_one;

	if (str_one == NULL && str_two == NULL)
		return (NULL);

	x = 0;
	y = 0;

	while (str_one[x] != '\0')
		x++;

	while (str_two[y] != '\0' && y < byt_num)
	{
		str_one[x] = str_two[y];
		x++;
		y++;
	}

	if (y < byt_num)
		str_one[x] = '\0';

	return (z);
}

/**
 **locateChar - ...
 *@x: ...
 *@t: ..
 *Return: ...
 */
char *locateChar(char *x, char t)
{
	do {
		if (*x == t)
			return (x);
	} while (*x++ != '\0');

	return (NULL);
}

/**
 * SplitString2 - ...
 * @string: ...
 * @delimiter: ...
 * Return: ...
 */
char **SplitString2(char *string, char delimiter)
{
	int x, y, z, l, n = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);

	for (x = 0; string[x] != '\0'; x++)
		if ((string[x] != delimiter && string[x + 1] == delimiter) ||
		    (string[x] != delimiter && !string[x + 1]) || string[x + 1] == delimiter)
			n++;
	if (n == 0)
		return (NULL);

	s = malloc((1 + n) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < n; y++)
	{
		while (string[x] == delimiter && string[x] != delimiter)
			x++;
		z = 0;

		while (string[x + z] != delimiter && string[x + z] &&
		string[x + z] != delimiter)
			z++;
		s[y] = malloc((z + 1) * sizeof(char));
		if (!s[y])
		{
			for (z = 0; z < y; z++)
				free(s[z]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < z; l++)
			s[y][l] = string[x++];
		s[y][l] = 0;
	}
	s[y] = NULL;
	return (s);
}

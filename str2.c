#include "shell.h"

/**
 * copyStrings - ..
 * @destina: ...
 * @source: ...
 * Return: dest ptr
 */
char *copyStrings(char *destina, char *source)
{
	int i = 0;

	if (destina == source || source == 0)
		return (destina);

	while (source[i])
	{
		destina[i] = source[i];
		i++;
	}
	destina[i] = 0;
	return (destina);
}

/**
 * ptchr - ...
 * @x: ...
 * Return: ...
 */
int ptchr(char x)
{
	static int i;
	static char mybuff[writeBufferSize];

	if (x == bufferFlush || i >= writeBufferSize)
	{
		write(1, mybuff, i);
		i = 0;
	}

	if (x != bufferFlush)
		mybuff[i++] = x;

	return (1);
}

/**
 * pts - ...
 * @string: ...
 * Return: ...
 */
void pts(char *string)
{
	int i = 0;

	if (!string)
		return;

	while (string[i] != '\0')
	{
		ptchr(string[i]);
		i++;
	}
}

/**
 * duplcatString - ....
 * @string:...
 * Return: ...
 */
char *duplcatString(const char *string)
{
	int length = 0;
	char *ret;

	if (string == NULL)
		return (NULL);

	while (*string++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--string;
	return (ret);
}

/**
 * SplitString - ...
 * @string: ...
 * @deli: ...
 * Return: ...
 */

char **SplitString(char *string, char *deli)
{
	int x, y, z, l, n = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);

	if (!deli)
		deli = " ";

	for (x = 0; string[x] != '\0'; x++)
		if (!_isdelim(string[x], deli) &&
		(_isdelim(string[x + 1], deli) || !string[x + 1]))
			n++;
	if (n == 0)
		return (NULL);
	s = malloc((1 + n) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < n; y++)
	{
		while (_isdelim(string[x], deli))
			x++;
		z = 0;
		while (!_isdelim(string[x + z], deli) && string[x + z])
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



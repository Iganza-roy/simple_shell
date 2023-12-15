#include "shell.h"

/**
 * isCMD - ....
 * @infolist: ...
 * @str_path: ...
 * Return: integer
 */
int isCMD(infolist_t *infolist, char *str_path)
{
	struct stat fileStat;

	(void)infolist;

	if (!str_path || stat(str_path, &fileStat))
		return (0);

	if (fileStat.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * duplCharacters - ...
 * @patheString: ...
 * @startIndex: ...
 * @stopIndex: ...
 * Return: ...
 */
char *duplCharacters(char *patheString, int startIndex, int stopIndex)
{
	static char staBuff[1024];
	int y = 0, x = 0;

	for (x = 0, y = startIndex; y < stopIndex; y++)
		if (patheString[y] != ':')
			staBuff[x++] = patheString[y];

	staBuff[x] = 0;

	return (staBuff);
}

/**
 * findPath - ...
 * @infolist: ...
 * @patheString: ...
 * @CMD: ...
 * Return: ...
 */
char *findPath(infolist_t *infolist, char *patheString, char *CMD)
{
	int x = 0, currentPos = 0;
	char *str_path;

	if (!patheString)
		return (NULL);

	if ((getStringLength(CMD) > 2) && startsWith(CMD, "./"))
	{
		if (isCMD(infolist, CMD))
			return (CMD);
	}

	while (1)
	{
		if (!patheString[x] || patheString[x] == ':')
		{
			str_path = duplCharacters(patheString, currentPos, x);

			if (!*str_path)
				concatenetStrings(str_path, CMD);
			else
			{
				concatenetStrings(str_path, "/");
				concatenetStrings(str_path, CMD);
			}

			if (isCMD(infolist, str_path))
				return (str_path);

			if (!patheString[x])
				break;
			currentPos = x;
		}
		x++;
	}
	return (NULL);
}

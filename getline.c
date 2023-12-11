#include "shell.h"

/**
 * get_line - ...
 * Return: ...
 */
char *get_line(void)
{
	static char buf[BUFF_SIZE];
	static size_t buf_ind = 0;
	static ssize_t byr = 0;

	ssize_t byr_curr = 0;
	char *l = NULL;
	size_t l_len = 0;

	while (1)
	{
		if (buf_ind == byr)
		{
			byr = read(STDIN_FILENO, buf, BUFF_SIZE);

			if (byr <= 0)
			{
				if (l_len > 0)
				{
					return (l);
				}
				else
				{
					free(l);
					return (NULL);
				}
			}
			buf_ind = 0;
		}

		if (buf[buf_ind] == '\n')
		{
			buf_ind++;
			break;
		}

		l = realloc(l, l_len + 1);
		
		if (l == NULL)
		{
			return (NULL);
		}
		l[l_len++] = buf[buf_ind++];
	}
	l = realloc(l, l_len + 1);
	if (l == NULL)
	{
		return (NULL);
	}

	return (NULL);
}

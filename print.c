#include "shell.h"

/**
 * _print - ...
 * @text: ....
 */
void _print(const char *text)
{
	size_t len = 0;

	while (text[len] != '\0')
	{
		len++;
	}

	write(STDOUT_FILENO, text, len);
}

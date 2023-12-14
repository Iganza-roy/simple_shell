#include "shell.h"

/**
 * _prompt - prints $ in interactive mode
 */
void _prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	{
		fg.interact = 1;
	}

	if (fg.interact)
	{
		write(STDERR_FILENO, "$ ", 2);
	}
}

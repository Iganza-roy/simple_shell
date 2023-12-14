#include "shell.h"

/**
 * signal_me - signals interactive mode
 * @n: signal number
 */
void signal_me(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

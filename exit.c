#include "shell.h"

/**
 * exit_m - ...
 */
void exit_me(int status)
{
	_printme("%d\n", status);
	exit(status);
}

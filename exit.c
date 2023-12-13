#include "shell.h"

/**
 * exit_me - ...
 * @status: ...
 */
void exit_me(int status)
{
	_printme("%d\n", status);
	exit(status);
}

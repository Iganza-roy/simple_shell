#include "shell.h"

/**
 * _printme - prints to stdout
 * @text: to be printed
 */
void _printme(const char *text)
{
	write(STDOUT_FILENO, text, _strlen(text));
}

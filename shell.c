#include "shell.h"

/**
 * main - entry point
 * @argument_coun: ac
 * @argument_v: av
 * Return: ...
 */
int main(int argument_coun, char **argument_v)
{
	infolist_t infolist[] = { initialInformatio };
	int fileDes = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fileDes)
		: "r" (fileDes));

	if (argument_coun == 2)
	{
		fileDes = open(argument_v[1], O_RDONLY);
		if (fileDes == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				errPrintStr(argument_v[0]);
				errPrintStr(": 0: Can't open that file ");
				errPrintStr(argument_v[1]);
				errPrintChar('\n');
				errPrintChar(bufferFlush);/*-1*/
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infolist->rfd = fileDes;
	}

	populateEnvList(infolist);
	r_history(infolist);
	shellLoob(infolist, argument_v);
	return (EXIT_SUCCESS);
}

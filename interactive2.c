#include "shell.h"

/**
 * str_to_int - ...
 * @str: ...
 * Return: ...
 */
int str_to_int(char *str)
{
	int x = 0;
	unsigned long int rest = 0;

	if (*str == '+')
		str++;

	for (x = 0;  str[x] != '\0'; x++)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			rest *= 10;
			rest += (str[x] - '0');

			if (rest > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rest);
}

/**
 * _errpr - ...
 * @infolist: ...
 * @emst: ...
 * Return: ...
 */
void _errpr(infolist_t *infolist, char *emst)
{
	Printstrer(infolist->filename);
	Printstrer(": ");
	des_pr(infolist->err_line_num, STDERR_FILENO);
	Printstrer(": ");
	Printstrer(infolist->argument_v[0]);
	Printstrer(": ");
	Printstrer(emst);
}

/**
 * des_pr - ...
 * @int_put: ...
 * @fileDes: ...
 * Return: ...
 */
int des_pr(int int_put, int fileDes)
{
	int (*put_chr)(char) = ptchr;
	int iter, num = 0;
	unsigned int ABS, curdir;

	if (fileDes == STDERR_FILENO)
		put_chr = erprchar;

	if (int_put < 0)
	{
		ABS = -int_put;
		put_chr('-');
		num++;
	}
	else
		ABS = int_put;
	curdir = ABS;

	for (iter = 1000000000; iter > 1; iter /= 10)
	{
		if (ABS / iter)
		{
			put_chr('0' + curdir / iter);
			num++;
		}
		curdir %= iter;
	}
	put_chr('0' + curdir);
	num++;

	return (num);
}

/**
 * convert_number - ...
 * @number: ...
 * @my_base: ...
 * @my_flags: ...
 * Return: ...
 */
char *convert_number(long int number, int my_base, int my_flags)
{
	static char buf[50];
	static char *my_array;
	char *pointr;
	char num_sign = 0;
	unsigned long nu = number;

	if (!(my_flags & unsignedConverter) && number < 0)
	{
		nu = -number;
		num_sign = '-';

	}

my_array = (my_flags & lowerCaseConverter) ?
			"0123456789abcdef" : "0123456789ABCDEF";

	pointr = &buf[49];
	*pointr = '\0';

	do	{
		*--pointr = my_array[nu % my_base];
		nu /= my_base;
	} while (nu != 0);

	if (num_sign)
		*--pointr = num_sign;

	return (pointr);
}

/**
 * re_co - ...
 * @mybuff: ...
 * Return: 0 on success
 */
void re_co(char *mybuff)
{
	int x;

	for (x = 0; mybuff[x] != '\0'; x++)
		if (mybuff[x] == '#' && (!x || mybuff[x - 1] == ' '))
		{
			mybuff[x] = '\0';
			break;
		}
}

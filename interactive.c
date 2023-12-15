#include "shell.h"

/**
 * IsInteractive - ...
 * @infolist: ...
 * Return: ...
 */
int IsInteractive(infolist_t *infolist)
{
	return (isatty(STDIN_FILENO) && infolist->rfd <= 2);
}

/**
 * IsDelimeter - ...
 * @chr_ch: ...
 * @dlmtr_str: ...
 * Return: ...
 */
int IsDelimeter(char chr_ch, char *dlmtr_str)
{
	while (*dlmtr_str)
		if (*dlmtr_str++ == chr_ch)
			return (1);
	return (0);
}

/**
 * ISAlphabetic - ...
 * @chr_in: ...
 * Return: ...
 */
int ISAlphabetic(int chr_in)
{
	if ((chr_in >= 'a' && chr_in <= 'z') || (chr_in >= 'A' && chr_in <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * StrToInt - ...
 * @str: 
 * Return: int val
 */

int StrToInt(char *str)
{
	int i, my_sign = 1, my_flag = 0, my_output;
	unsigned int result = 0;

	for (i = 0;  str[i] != '\0' && my_flag != 2; i++)
	{
		if (str[i] == '-')
			my_sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			my_flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}

		else if (my_flag == 1)
			my_flag = 2;
	}

	if (my_sign == -1)
		my_output = -result;
	else
		my_output = result;

	return (my_output);
}

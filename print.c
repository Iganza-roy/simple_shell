#include "shell.h"

/**
 * _printme - custom print function
 * @output: printed output
 */
void _printme(const char *output, ...)
{
	size_t len = 0;
	char buf[MAX_OUTPUT_SIZE];
	va_list args;

	va_start(args, output);

	while (*output != '\0')
	{
		if (*output == '%' && *(output + 1) != '\0')
		{
			switch (*(output + 1))
			{
			case 's':
				len += snprintf(buf + len, sizeof(buf) - len, "%s", va_arg(args,
							 const char *));
				break;
			case 'd':
				len += snprintf(buf + len, sizeof(buf) - len, "%d", va_arg(args, int));
				break;
			default:
				buf[len++] = *output;
				break;
			}
			output += 2;
		}
		else
		{
			buf[len++] = *output++;
		}
		if (len >= sizeof(buf))
		{
			write(STDOUT_FILENO, buf, len);
			len = 0;
		}
	}
	if (len > 0)
	{
		write(STDOUT_FILENO, buf, len);
	}
	va_end(args);
}

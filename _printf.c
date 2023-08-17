#include "shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - output text to standard output specified by format
 * @format: directives for outputing text
 * Return: number of characters output
 */
int _printf(const char *format, ...)
{
	int maxx, sum = 0, val = -1, index = 0;
	char *arg = NULL;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (val);
	if (_strlen((char *)format) == 1 && format[0] == '%')
	{
		return (val);
	}
	maxx = 0;
	va_start(params, format);
	while (1)
	{
		if (index == BUFFER_SIZE)
		{
			sum += flush_buffer(buffer, &index);
		}
		if (format[maxx] == '%')
		{
			get_type((char *)format, &maxx);
			switch (format[maxx])
			{
				case 'c':
					buffer[index] = (char) va_arg(params, int);
					index++;
					maxx++;
					continue;
				case 's':
					arg = get_arg('s', va_arg(params, char*));
					break;
				case 'd':
				case 'i':
					arg = get_arg('d', va_arg(params, int));
					break;
				case 'b':
					arg = get_arg('b', va_arg(params, int));
					break;
				case 'r':
					arg = get_arg('r', va_arg(params, char *));
					break;
				case 'R':
					arg = get_arg('R', va_arg(params, char *));
					break;
				case '%':
					arg = malloc(2);
					arg[0] = '%';
					arg[1] = '\0';
					break;
				case '\0':
					buffer[index] = '%';
					index++;
					continue;
				default:
					arg = malloc(3);
					arg[0] = '%';
					arg[1] = format[maxx];
					arg[2] = '\0';
			}
			if (!arg)
			{
				va_end(params);
				free(arg);
				return (val);
			}
			sum += flush_buffer(buffer, &index);
			sum += print_arg(arg);
			free(arg);
			maxx++;
		}
		else if (format[maxx] != '\0')
		{
			buffer[index] = format[maxx];
			index++;
			maxx++;
		}
		else
		{
			sum += flush_buffer(buffer, &index);
			va_end(params);
			return (sum);
		}
	}
	return (sum);
}

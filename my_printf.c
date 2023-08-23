#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_printf - Output text to standard output specified by format
 * @format: Directives for outputting text
 *
 * Return: Number of characters output
 */
int my_printf(const char *format, ...)
{
	int formatIndex, charCount = 0, returnValue = -1, bufferIndex = 0;
	char buffer[BUFFER_SIZE] = {0};
	char *arg = NULL;
	va_list params;

	if (!format)
		return (returnValue);

	if (_strlen((char *)format) == 1 && format[0] == '%')
		return (returnValue);

	formatIndex = 0;
	va_start(params, format);

	while (1)
	{
		if (bufferIndex == BUFFER_SIZE)
		{
			charCount += write_and_reset_buffer(buffer, &bufferIndex);
		}

		if (format[formatIndex] == '%')
		{
			get_type((char *)format, &formatIndex);

			switch (format[formatIndex])
			{
				case 'c':
					buffer[bufferIndex] = (char) va_arg(params, int);
					bufferIndex++;
					formatIndex++;
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
					buffer[bufferIndex] = '%';
					bufferIndex++;
					continue;
				default:
					arg = malloc(3);
					arg[0] = '%';
					arg[1] = format[formatIndex];
					arg[2] = '\0';
			}

			if (!arg)
			{
				va_end(params);
				free(arg);
				return (returnValue);
			}

			charCount += write_and_reset_buffer(buffer, &bufferIndex);
			charCount += print_arg(arg);
			free(arg);
			formatIndex++;
		}
		else if (format[formatIndex] != '\0')
		{
			buffer[bufferIndex] = format[formatIndex];
			bufferIndex++;
			formatIndex++;
		}
		else
		{
			charCount += write_and_reset_buffer(buffer, &bufferIndex);
			va_end(params);
			return (charCount);
		}
	}

	return (charCount);
}

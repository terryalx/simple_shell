#include "shell.h"

#define BUFFER_SIZE 1024

int process_format(const char *format, va_list params,
		char *buffer, int *bufferIndex);

/**
 * my_printf - Custom printf function with variable arguments.
 * @format: Format string with format specifiers.
 * Return: Number of characters printed, excluding the null byte.
 */
int my_printf(const char *format, ...)
{
	int charCount = 0, returnValue = -1, bufferIndex = 0;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (returnValue);

	if (_strlen((char *)format) == 1 && format[0] == '%')
		return (returnValue);

	va_start(params, format);

	charCount = process_format(format, params, buffer, &bufferIndex);

	va_end(params);
	return (charCount);
}

/**
 * process_format - Process format string and print formatted output.
 * @format: Format string with format specifiers.
 * @params: Variable arguments list.
 * @buffer: Output buffer for formatted output.
 * @bufferIndex: Current index in the buffer.
 * Return: Number of characters printed, excluding the null byte.
 */
int process_format(const char *format, va_list params,
		char *buffer, int *bufferIndex)
{
	int formatIndex = 0, charCount = 0;
	char *arg = NULL;

	while (1)
	{
		if (*bufferIndex == BUFFER_SIZE)
		{
			charCount += write_and_reset_buffer(buffer, bufferIndex);
		}

		if (format[formatIndex] == '%')
		{
			get_type((char *)format, &formatIndex);

			switch (format[formatIndex])
			{
				case 'c':
					buffer[*bufferIndex] = (char)va_arg(params, int);
					(*bufferIndex)++;
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
					buffer[*bufferIndex] = '%';
					(*bufferIndex)++;
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
				return (charCount);
			}

			charCount += write_and_reset_buffer(buffer, bufferIndex);
			charCount += print_arg(arg);
			free(arg);
			formatIndex++;
		}
		else if (format[formatIndex] != '\0')
		{
			buffer[*bufferIndex] = format[formatIndex];
			(*bufferIndex)++;
			formatIndex++;
		}
		else
		{
			charCount += write_and_reset_buffer(buffer, bufferIndex);
			va_end(params);
			return (charCount);
		}
	}
}

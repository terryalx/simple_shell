#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _printf - Format and print data to the standard output.
 * @format: A format string specifying the format of the output.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int charCount = 0, returnValue = -1, bufferIndex = 0;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (returnValue);

	if (_strlen((char *)format) == 1 && format[0] == '%')
	{
		return (returnValue);
	}

	va_start(params, format);
	charCount = process_format(format, params, buffer, &bufferIndex);
	va_end(params);

	return (charCount);
}

/**
 * process_format - Process the format string and print to buffer.
 * @format: The format string.
 * @params: The variable argument list.
 * @buffer: The buffer to store the formatted output.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters printed.
 */
int process_format(const char *format, va_list params, char *buffer, int *bufferIndex)
{
	int formatIndex = 0, charCount = 0;
	char *arg = NULL;

	while (1)
	{
		if (*bufferIndex == BUFFER_SIZE)
		{
			charCount += flush_buffer(buffer, bufferIndex);
		}

		if (format[formatIndex] == '%')
		{
			formatIndex = handle_format(format, params, buffer, bufferIndex, &charCount, formatIndex);
		}
		else if (format[formatIndex] != '\0')
		{
			buffer[*bufferIndex] = format[formatIndex];
			(*bufferIndex)++;
			formatIndex++;
		}
		else
		{
			charCount += flush_buffer(buffer, bufferIndex);
			return (charCount);
		}
	}

	return (charCount);
}

/**
 * handle_format - Handle a format specifier.
 * @format: The format string.
 * @params: The variable argument list.
 * @buffer: The buffer to store the formatted output.
 * @bufferIndex: The current index in the buffer.
 * @charCount: The total character count.
 * @formatIndex: The current index in the format string.
 *
 * Return: The updated formatIndex.
 */
int handle_format(const char *format, va_list params, char *buffer, int *bufferIndex, int *charCount, int formatIndex)
{
	char *arg = NULL;

	formatIndex++;
	if (format[formatIndex] == '\0')
	{
		buffer[*bufferIndex] = '%';
		(*bufferIndex)++;
		return (formatIndex);
	}

	switch (format[formatIndex])
	{
		case 'c':
			buffer[*bufferIndex] = (char)va_arg(params, int);
			(*bufferIndex)++;
			formatIndex++;
			break;
		case 's':
		case 'd':
		case 'i':
		case 'b':
		case 'r':
		case 'R':
			arg = get_arg(format[formatIndex], va_arg(params, void *));
			*charCount += flush_buffer(buffer, bufferIndex);
			*charCount += print_arg(arg);
			free(arg);
			formatIndex++;
			break;
		case '%':
			buffer[*bufferIndex] = '%';
			(*bufferIndex)++;
			formatIndex++;
			break;
		default:
			arg = get_arg(format[formatIndex], NULL);
			*charCount += flush_buffer(buffer, bufferIndex);
			*charCount += print_arg(arg);
			free(arg);
			formatIndex++;
	}

	return (formatIndex);
}

/**
 * flush_buffer - Write buffer content to stdout.
 * @buffer: The buffer to be flushed.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters flushed.
 */
int flush_buffer(char *buffer, int *bufferIndex)
{
	int charCount = 0;

	if (*bufferIndex > 0)
	{
		charCount = write(1, buffer, *bufferIndex);
		*bufferIndex = 0;
	}

	return (charCount);
}

/**
 * print_arg - Print the argument string to buffer.
 * @arg: The argument string.
 *
 * Return: The number of characters printed.
 */
int print_arg(char *arg)
{
	int charCount = 0;

	if (arg)
	{
		charCount = _strlen(arg);
		write(1, arg, charCount);
	}

	return (charCount);
}

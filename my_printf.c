#include "shell.h"

#define BUFFER_SIZE 1024

static int print_char(char c, char *buffer, int *bufferIndex);
static int print_string(char *str, char *buffer, int *bufferIndex);
static int print_int(int num, char *buffer, int *bufferIndex);
static int print_binary(int num, char *buffer, int *bufferIndex);
static int print_reverse_string(char *str, char *buffer, int *bufferIndex);

/**
 * my_printf - Output text to standard output specified by format.
 * @format: Directives for outputting text.
 *
 * Return: Number of characters output.
 */
int my_printf(const char *format, ...)
{
	int charCount = 0, bufferIndex = 0;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (-1);

	va_start(params, format);

	while (*format)
	{
		if (bufferIndex == BUFFER_SIZE)
		{
			charCount += write_and_reset_buffer(buffer, &bufferIndex);
		}

		if (*format != '%')
		{
			charCount += print_char(*format, buffer, &bufferIndex);
		}
		else
		{
			format++;

			switch (*format)
			{
			case 'c':
				charCount += print_char(va_arg(params, int), buffer, &bufferIndex);
				break;
			case 's':
				charCount += print_string(va_arg(params, char *), buffer, &bufferIndex);
				break;
			case 'd':
			case 'i':
				charCount += print_int(va_arg(params, int), buffer, &bufferIndex);
				break;
			case 'b':
				charCount += print_binary(va_arg(params, int), buffer, &bufferIndex);
				break;
			case 'r':
				charCount += print_reverse_string(va_arg(params, char *), buffer, &bufferIndex);
				break;
			case 'R':
				charCount += print_reverse_string(va_arg(params, char *), buffer, &bufferIndex);
				break;
			case '%':
				charCount += print_char('%', buffer, &bufferIndex);
				break;
			default:
				charCount += print_char('%', buffer, &bufferIndex);
				charCount += print_char(*format, buffer, &bufferIndex);
				break;
			}
		}

		format++;
	}

	charCount += write_and_reset_buffer(buffer, &bufferIndex);
	va_end(params);
	return (charCount);
}

/**
 * print_char - Append a character to the buffer.
 * @c: The character to append.
 * @buffer: The buffer to append to.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: 1 for success, -1 for failure.
 */
static int print_char(char c, char *buffer, int *bufferIndex)
{
	if (*bufferIndex == BUFFER_SIZE)
	{
		return (write_and_reset_buffer(buffer, bufferIndex));
	}

	buffer[*bufferIndex] = c;
	(*bufferIndex)++;
	return (1);
}

/**
 * print_string - Append a string to the buffer.
 * @str: The string to append.
 * @buffer: The buffer to append to.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters added.
 */
static int print_string(char *str, char *buffer, int *bufferIndex)
{
	int i;
	int len = _strlen(str);

	if (*bufferIndex + len >= BUFFER_SIZE)
	{
		return (write_and_reset_buffer(buffer, bufferIndex));
	}

	for (i = 0; i < len; i++)
	{
		buffer[*bufferIndex] = str[i];
		(*bufferIndex)++;
	}

	return (len);
}

/**
 * print_int - Append an integer to the buffer.
 * @num: The integer to append.
 * @buffer: The buffer to append to.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters added.
 */
static int print_int(int num, char *buffer, int *bufferIndex)
{
	char numStr[12];
	
	write_and_reset_buffer(numStr, sizeof(numStr), "%d", num);
	return (print_string(numStr, buffer, bufferIndex));
}

/**
 * print_binary - Append a binary representation of an integer to the buffer.
 * @num: The integer to convert and append.
 * @buffer: The buffer to append to.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters added.
 */
static int print_binary(int num, char *buffer, int *bufferIndex)
{
	int i;
	char binStr[33];

	for (i = 0; i < 32; i++)
	{
		binStr[i] = (num & (1 << (31 - i))) ? '1' : '0';
	}
	binStr[32] = '\0';

	return (print_string(binStr, buffer, bufferIndex));
}

/**
 * print_reverse_string - Append a reversed string to the buffer.
 * @str: The string to reverse and append.
 * @buffer: The buffer to append to.
 * @bufferIndex: The current index in the buffer.
 *
 * Return: The number of characters added.
 */
static int print_reverse_string(char *str, char *buffer, int *bufferIndex)
{
	int i;
	int len = _strlen(str);

	if (*bufferIndex + len >= BUFFER_SIZE)
	{
		return (write_and_reset_buffer(buffer, bufferIndex));
	}

	for (i = len - 1; i >= 0; i--)
	{
		buffer[*bufferIndex] = str[i];
		(*bufferIndex)++;
	}

	return (len);
}

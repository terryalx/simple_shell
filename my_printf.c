#include "shell.h"

#define BUFFER_SIZE 1024

/* Function Declarations */
static int write_and_reset_buffer(char *buffer, int *index);
static int handle_char(char *buffer, int *index, va_list *params);
static int handle_string(char *buffer, int *index, va_list *params);
static int handle_int(char *buffer, int *index, va_list *params);

int my_printf(const char *format, ...);

/**
 * write_and_reset_buffer - Write the buffer content to standard output and reset it.
 * @buffer: The character buffer to write from.
 * @index: Pointer to the buffer index.
 *
 * Return: The number of characters written.
 */
static int write_and_reset_buffer(char *buffer, int *index)
{
	int charCount = write(1, buffer, *index);
	memset(buffer, 0, BUFFER_SIZE);
	*index = 0;
	return (charCount);
}

/**
 * handle_char - Handle the %c format specifier.
 * @buffer: The character buffer to write to.
 * @index: Pointer to the buffer index.
 * @params: The variable argument list.
 *
 * Return: The number of characters written.
 */
static int handle_char(char *buffer, int *index, va_list *params)
{
	char c = va_arg(*params, int);
	if (*index == BUFFER_SIZE)
		return (write_and_reset_buffer(buffer, index));
	buffer[(*index)++] = c;
	return (1);
}

/**
 * handle_string - Handle the %s format specifier.
 * @buffer: The character buffer to write to.
 * @index: Pointer to the buffer index.
 * @params: The variable argument list.
 *
 * Return: The number of characters written.
 */
static int handle_string(char *buffer, int *index, va_list *params)
{
	char *s = va_arg(*params, char *);
	int charCount = 0;
	while (*s)
	{
		if (*index == BUFFER_SIZE)
			charCount += write_and_reset_buffer(buffer, index);
		buffer[(*index)++] = *s;
		s++;
		charCount++;
	}
	return (charCount);
}

/**
 * handle_int - Handle the %d and %i format specifiers.
 * @buffer: The character buffer to write to.
 * @index: Pointer to the buffer index.
 * @params: The variable argument list.
 *
 * Return: The number of characters written.
 */
static int handle_int(char *buffer, int *index, va_list *params)
{
	int num = va_arg(*params, int);
	char numStr[32];
	snprintf(numStr, sizeof(numStr), "%d", num);
	return (handle_string(buffer, index, numStr));
}

/**
 * my_printf - Format and print text to standard output.
 * @format: The format string with optional format specifiers.
 *            Supported specifiers: %c, %s, %d, %i
 * @...: Variable number of arguments corresponding to the specifiers.
 *
 * Return: The number of characters printed.
 */
int my_printf(const char *format, ...)
{
	int charCount = 0;
	int bufferIndex = 0;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (format == NULL)
		return (-1);

	va_start(params, format);

	for (int i = 0; format[i]; i++)
	{
		if (bufferIndex == BUFFER_SIZE)
			charCount += write_and_reset_buffer(buffer, &bufferIndex);

		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				buffer[bufferIndex++] = '%';
			else if (format[i] == 'c')
				charCount += handle_char(buffer, &bufferIndex, &params);
			else if (format[i] == 's')
				charCount += handle_string(buffer, &bufferIndex, &params);
			else if (format[i] == 'd' || format[i] == 'i')
				charCount += handle_int(buffer, &bufferIndex, &params);
		}
		else
		{
			buffer[bufferIndex++] = format[i];
			charCount++;
		}
	}

	charCount += write_and_reset_buffer(buffer, &bufferIndex);

	va_end(params);
	return (charCount);
}

int main(void)
{
	my_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return (0);
}

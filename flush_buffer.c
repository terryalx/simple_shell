#include "shell.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * flush_buffer - print out the buffer up to the index and reset
 * @buffer: buffer string
 * @index: index
 * Return: total number of characters printed
 */
int flush_buffer(char *buffer, int *index)
{
	int num_chars_printed = 0;

	num_chars_printed = write(1, buffer, *index);

	for (*index = BUFFER_SIZE - 1; *index >= 0; (*index)--)
		buffer[*index] = 0;

	*index = 0;

	return num_chars_printed;
}

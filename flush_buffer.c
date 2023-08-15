#include "main.h"
#include "shell.h"
#include "list.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * flush_buffer - print out the buffer upto index and reset
 * @buffer: buffer string
 * @index: index
 * Return: total number of characters printed
 */

int flush_buffer(char *buffer, int *index)
{
	int num = 0;

	num = write(1, buffer, *index);
	*index = BUFFER_SIZE - 1;
	while (*index >= 0)
	{
		buffer[*index] = 0;
		*index -= 1;
	}
	*index = 0;
	return (num);
}

#include "shell.h"

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * realloc_line_buffer - Reallocates the line buffer
 * to a new size.
 * @line: Pointer to the line buffer.
 * @oldSize: Current size of the line buffer.
 * @newSize: New size of the line buffer.
 *
 * Return: Pointer to the new allocated buffer,
 * or NULL on failure.
 */
char *realloc_line_buffer(char **line, unsigned int oldSize,
		unsigned int newSize)
{
	char *newLine = NULL;
	unsigned int i;

	newLine = malloc(newSize);
	if (newLine)
	{
		for (i = 0; i < oldSize; i++)
			newLine[i] = (*line)[i];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}

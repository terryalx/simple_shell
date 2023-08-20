#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - reallocates the line buffer
 * @line: pointer to the line buffer
 * @oldSize: the current size of the buffer
 * @newSize: the new size of the buffer
 *
 * This function reallocates the line buffer to a new size.
 * It copies the contents of the old buffer to the new buffer
 * and frees the old buffer.
 *
 * Return: a pointer to the new allocated buffer, or NULL on failure
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *newBuffer = NULL;

	newBuffer = malloc(newSize);
	if (newBuffer)
	{
		memcpy(newBuffer, *line, oldSize);
		free(*line);
		*line = newBuffer;
	}
	return newBuffer;
}

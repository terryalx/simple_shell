#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - realloc the line buffer
 * @line: to be buffered
 * @oldSize: something borrowed
 * @newSize: something blue
 * Return: new allocated buffer
 */

char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
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

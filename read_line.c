#include "shell.h"

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * read_line - fetches a line of characters from stdin
 * @params: parameters
 *
 * Return: number of characters read
 */
int read_line(param_t *params)
{
	char *line = NULL;
	static unsigned int bufSize = BUFFER_SIZE;
	char *writeHead = line;
	unsigned int len;

	line = malloc(BUFFER_SIZE);
	do {
		len = read(0, writeHead, BUFFER_SIZE);
		if (len == 0)
			break;
		writeHead += len;
		if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = realloc_line_buffer(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (len == 0)
		return (-1);
	return (_strlen(params->buffer));
}

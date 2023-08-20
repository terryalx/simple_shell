#include "shell.h"

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * _getline - Fetches a line of characters from stdin
 * @params: Pointer to the parameters struct
 *
 * This function reads characters from the standard input until a newline character is encountered.
 * It dynamically allocates memory for the line and increases the buffer size if necessary.
 *
 * Return: The number of characters read
 */
int _getline(param_t *params)
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
			line = rlLine(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;
	if (len == 0)
		return (-1);
	return (_strlen(params->buffer));
}

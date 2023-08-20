#include "shell.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024
/**
 * _getline - Fetches a line of characters from stdin
 * @params: Pointer to the parameters struct
 * Return: The number of characters read
 */
int _getline(param_t *params)
{
    char *line = NULL, *writeHead = line;
    static unsigned int bufSize = BUFFER_SIZE;
    unsigned int len;

    line = malloc(BUFFER_SIZE);
    if (line == NULL)
		return (-1);

    do {
        len = read(0, writeHead, BUFFER_SIZE);
        if (len == 0)
            break;
        writeHead += len;
        if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
        {
            char *newLine = rlLine(&line, bufSize, bufSize * 2);
            if (newLine == NULL)
                free(line);
                return (-1);
            line = newLine;
            bufSize *= 2;
        }
    } while (*(writeHead - 1) != '\n');

    free(params->buffer);
    params->buffer = line;
    if (len == 0)
        return (-1);
    return (_strlen(params->buffer));
}

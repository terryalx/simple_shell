#include "shell.h"

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * read_dynamic_line - Reads a line of characters from stdin with dynamic allocation
 * @params: Pointer to the parameters struct
 *
 * This function reads characters from the standard input until a newline character is encountered.
 * It dynamically allocates memory for the line and increases the buffer size if necessary.
 *
 * Return: The number of characters read
 */
int read_dynamic_line(param_t *params) {
    char *line = NULL, *writeHead = line;
    static unsigned int bufSize = BUFFER_SIZE;
    unsigned int len;

    line = malloc(BUFFER_SIZE);
    if (!line) return (-1);

    do {
        len = read(0, writeHead, BUFFER_SIZE);
        if (len == 0) break;
        writeHead += len;
        if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE)) {
            if (!(line = rlLine(&line, bufSize, bufSize * 2))) {
                free(params->buffer);
                return (-1);
            }
            bufSize *= 2;
        }
    } while (*(writeHead - 1) != '\n');

    free(params->buffer);
    params->buffer = line;
    return (len == 0 ? -1 : _strlen(params->buffer));
}

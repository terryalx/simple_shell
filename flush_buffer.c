#include "shell.h"

#define BUFFER_SIZE 

/**
 * flush_buffer - Prints the contents of the buffer up to a specified index and resets it.
 * @buffer: Pointer to the buffer string.
 * @index: Pointer to the index of the buffer.
 *
 * This function writes the characters in the buffer up to the specified index to the standard output (stdout)
 * and then resets the buffer contents and index.
 *
 * Return: The total number of characters printed.
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

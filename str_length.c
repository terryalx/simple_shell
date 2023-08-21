#include "shell.h"

/**
 * str_length - Get the length of a string.
 *
 * This function calculates the length of a string, excluding the null terminator.
 *
 * @str: The input string.
 *
 * Return: The length of the string.
 */
void str_length(param_t *params)
{
    size_t length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

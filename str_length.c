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
size_t str_length(const char *str)
{
    size_t length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

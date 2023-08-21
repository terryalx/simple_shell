#include "shell.h"

/**
 * string_compare - compares two strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: an integer less than, equal to, or greater than 0 if str1 is,
 * respectively, less than, equal to, or greater than str2
 */
int string_compare(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

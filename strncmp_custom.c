#include "shell.h"

/**
 * strncmp_custom - Compare the first n bytes of two strings.
 * @str1: The first string.
 * @str2: The second string.
 * @n: The number of bytes to compare.
 *
 * Return: 0 if the first n bytes of str1 and str2 are equal,
 * a positive value if str1 is greater, or a negative value if str2 is greater.
 */
int strncmp_custom(char *str1, char *str2, int n)
{
    int i = 0;
    int result = 0;

    while (i < n)
    {
        result = *(str1++) - *(str2++);
        if (result != 0)
            break;
        i++;
    }

    return result;
}

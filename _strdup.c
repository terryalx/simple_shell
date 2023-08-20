#include "shell.h"

/**
 * _strdup - Duplicate a string to a new allocated block of memory
 * @str: String to duplicate
 *
 * Return: Pointer to duplicated string, NULL if insufficient memory
 */
char *_strdup(char *str)
{
    char *ptr = NULL;
    int len = 0;
    char *str_copy = str;

    if (!str)
    {
        return (NULL);
    }

    while (*str_copy)
    {
        len++;
        str_copy++;
    }

    ptr = (char *)malloc(sizeof(char) * (len + 1));

    if (ptr)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            ptr[i] = str[i];
        }
        ptr[len] = '\0';
    }

    return ptr;
}

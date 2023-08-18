#include "shell.h"

#include <stdlib.h>

/**
 * _strdup - copy a string to a new allocated block of memory
 * @str: string
 * Return: pointer to duplicated string, NULL if insufficient memory
 */
char *_strdup(char *str)
{
	char *ptr = NULL;

	int len;

	len = 0;

	if (!str)
	{
		return (NULL);
	}

	while (*str)
	{
		len++;
		str++;
	}

	ptr = (char *) malloc(sizeof(char) * (len + 1));

	if (ptr)
	{
		while (len >= 0)
		{
			*(ptr + len--) = *(str--);
		}
	}
	return (ptr);
}

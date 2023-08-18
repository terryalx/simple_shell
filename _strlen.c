#include "shell.h"

#include <stdlib.h>

/**
 *_strlen - returns the length of a string
 *@s: string
 *Return: 0 if null, else length without null byte
 */
int _strlen(char *s)
{
	int length;

	length = 0;

	if (s == NULL)
	{
		return (0);
	}

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

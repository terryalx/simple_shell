#include "shell.h"
#include <stdlib.h>

/**
 *_strlen - returns the length of a string
 *@s: string
 *Return: 0 if null, else length without null byte
 */

int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
	{
		return (0);
	}

	for (length = 0; s[length] != '\0'; length++)
		;
	return (length);
}

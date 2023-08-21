#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
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

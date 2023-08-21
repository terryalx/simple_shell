#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 *
 * This function returns the length of a string, excluding the null terminator.
 * If the input string is NULL, it returns 0.
 *
 * @s: The input string.
 *
 * Return: The length of the string, or 0 if the string is NULL.
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

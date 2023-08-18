#include "shell.h"
#include <stdlib.h>

/**
 * _strlen - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
	size_t length = 0;

	if (s == NULL)
		return (0);

	while (s[length] != '\0')
		length++;

	return (length);
}

#include "shell.h"
#include <stdlib.h>

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: character to be found
 *
 * Return: pointer to the first occurrence of the character in the string
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
	{
		return (s);
	}

	return (NULL);
}

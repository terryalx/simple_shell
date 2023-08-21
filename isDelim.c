#include "shell.h"

/**
 * is_delim - Check if a character is one of the delimiters.
 * @c: The character to be checked.
 * @delim: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

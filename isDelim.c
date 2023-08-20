#include "shell.h"
#include <stdlib.h>

/**
 * is_delim - Check if a character is one of the delimiters.
 * @c: The character to be checked.
 * @delim: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int isDelim(char c, char *delim)
{
	int val;
	val = 1;

	while (*delim)
	{
		if (c == *delim)
		{
			return (val);
		}
		delim++;
	}
	return (0);
}

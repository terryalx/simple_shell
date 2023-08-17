#include "shell.h"
#include <stdlib.h>

/**
 * isDelim - check if a character is one of the delimiters
 * @c: character
 * @delim: delimeters
 * Return: 1 if it is a delimiter, 0 otherwise
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

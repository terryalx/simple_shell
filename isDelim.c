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

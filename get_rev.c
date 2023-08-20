#include "shell.h"
#include <stdlib.h>

/**
 * get_rev - returns a reversed copy of a string
 * @s: string to be reversed
 *
 * Return: reversed string
 */
char *get_rev(char *s)
{
	char *reversed = NULL;

	reversed = get_string(s);
	if (!reversed)
	{
		return (NULL);
	}
	if (s)
	{
		rev_string(reversed);
	}
	return (reversed);
}

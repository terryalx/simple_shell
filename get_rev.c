#include "main.h"
#include "shell.h"
#include "list.h"
#include <stdlib.h>

/**
 * get_rev - returns a reversed copy of a string
 * @s: string to be reversed
 * Return: string reversed
 */

char *get_rev(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
	{
		return (NULL);
	}
	if (s)
	{
		rev_string(ptr);
	}
	return (ptr);
}

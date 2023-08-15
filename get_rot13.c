#include "main.h"
#include <stdlib.h>

/**
 * get_rot13 - get rot13
 * @s: string
 * Return: ptr to string
 */

char *get_rot13(char *s)
{
	char *ptr = NULL;

	ptr = get_string(s);
	if (!ptr)
		return (NULL);
	if (s)
	{
		rot13(ptr);
	}
	return (ptr);
}

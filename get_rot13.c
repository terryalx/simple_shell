#include "shell.h"

/**
 * get_rot13 - Applies the ROT13 encryption algorithm to a string.
 * @s: The input string.
 *
 * Return: A pointer to the encrypted string.
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

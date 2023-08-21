#include "shell.h"

/**
 * get_char - returns a copied char
 * @c: char to be copied
 * Return: ptr of copied char
 */

char *get_char(char c)
{
	char *ptr = NULL;

	ptr = malloc(2);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr[0] = c;
	ptr[1] = '\0';
	return (ptr);
}

#include "shell.h"
#include <stdlib.h>

/**
 * get_rot13 - Applies the ROT13 encryption algorithm to a string.
 * @s: The input string.
 *
 * Return: A pointer to the encrypted string.
 */
char *get_rot13(char *s)
{
	char *encrypted_str = NULL;

	encrypted_str = get_string(s);
	if (!encrypted_str)
		return (NULL);

	if (s)
		rot13(encrypted_str);

	return (encrypted_str);
}

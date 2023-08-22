#include "shell.h"

/**
 * find_character_in_string - Locates a character
 * in a string.
 * @s: Pointer to the string.
 * @c: Character to be found.
 *
 * Return: Pointer to the first occurrence of
 * the character in the string, or NULL if
 * the character is not found.
 */
char *find_character_in_string(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}

	if (c == '\0')
		return (&s[i]);

	return (NULL);
}

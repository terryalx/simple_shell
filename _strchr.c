#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: character to be found
 *
 * Return: pointer to the first occurrence of the character in the string
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	int rtn = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (rtn);
}

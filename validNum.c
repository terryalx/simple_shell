#include "shell.h"

/**
 * is_valid_number - Check if a string is a valid number.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int validNum(char *s)
{
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		s++;
	}
	return (1);
}

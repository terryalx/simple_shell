#include "shell.h"

/**
 * validNum - check if string is a valid number
 * @s: string
 * Return: 0 if false, 1 otherwise
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

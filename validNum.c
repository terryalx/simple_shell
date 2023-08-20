#include "shell.h"
#include <stdlib.h>
#include <limits.h>

/**
 * is_valid_number - Check if a string is a valid number.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_valid_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return 0;
		}
		str++;
	}
	return 1;
}

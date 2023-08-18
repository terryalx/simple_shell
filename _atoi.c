#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _atoi - Convert a string to an integer
 * @s: The string to be converted
 *
 * Return: The converted integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int save_tmp = 0;
	int len = _strlen(s);
	int mul = 1;
	int r_val = -1;

	len--;

	while (len >= 0)
	{
		save_tmp = i;
		i = i + (s[len] - '0') * mul;
		if (i < save_tmp || i > INT_MAX)
			return (r_val);
		len--;
		mul *= 10;
	}

	return (i);
}

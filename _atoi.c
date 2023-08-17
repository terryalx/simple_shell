#include "shell.h"

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: n the value of the first number in the st0ring
 */
int _atoi(char *s)
{
	int i;
	int save_tmp;
	int len;
	int mul = 1;
	int r_val = -1;

	i = 0;
	save_tmp = 0;

	len = _strlen(s);
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

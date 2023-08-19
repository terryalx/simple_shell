#include "main.h"
#include "shell.h"
#include "list.h"
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
	int n, tmp, len, mul = 1;

	n = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = n;
		n = n + (s[len] - '0') * mul;
		if (n < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (n);
}

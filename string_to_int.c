#include "shell.h"

/**
 * string_to_int - Convert a string to an integer
 * @s: The string to be converted
 *
 * Return: The converted integer value
 */
int string_to_int(char *s)
{
	int i = 0;
	int save_tmp = 0;
	int len = _strlen(s);
	int mul = 1;
	int r_val = -1;
	int cmp = 0;

	len--;

	while (len >= cmp)
	{
		save_tmp = i;
		i = i + (s[len] - '0') * mul;
		if (i < save_tmp || i > INT_MAX)
		{
			return (r_val);
		}
		len--;
		mul *= 10;
	}

	return (i);
}

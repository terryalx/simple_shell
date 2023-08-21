#include "shell.h"

/**
 * get_number - Convert an integer to a string.
 * @number: The integer to be converted.
 *
 * Return: A pointer to the string representation of the integer,
 *         or NULL if an error occurs.
 */
char *get_number(int n)
{
	int i, len = 0, tmp;
	char *buf = NULL;
	/* find number bytes to allocate */
	tmp = n;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	if (n < 0)
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		buf[len] = '\0';
		if (n < 0)
		{
			buf[0] = '-';
		}
		i = len - 1;
		while (n >= 10 || n <= -10)
		{
			tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
			buf[i] = tmp + '0';
			i--;
			n /= 10;
		}
		tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
		buf[i] = tmp + '0';
	}
	return (buf);
}

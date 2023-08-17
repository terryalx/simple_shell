#include "shell.h"

#include <stdlib.h>

/**
 * get_binary - converts an unsigned int to binary
 * @n: integer
 * Return: pointer to binary
 */
char *get_binary(unsigned int n)
{
	char *ptr = NULL;
	unsigned int i;
	unsigned int num = 0;
	unsigned int size = 0;

	if (n == 0)
	{
		ptr = malloc(2);
		if (ptr)
		{
			ptr[0] = '0';
			ptr[1] = '\0';
		}
		return (ptr);
	}
	size = sizeof(int) * 8 + 1;
	ptr = malloc(size);
	if (ptr)
	{
		for (i = 0; i < size; i++)
		{
			ptr[i] = '0';
		}
		ptr[size - 1] = '\0';

		i = size - 2;
		while (n != 0)
		{
			ptr[i] = n % 2 == 0 ? '0' : '1';
			num++;
			n = n / 2;
			i--;
		}
		num++;
		ptr = move_left(ptr, size, num);
	}
	return (ptr);
}

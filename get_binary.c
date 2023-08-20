#include "shell.h"
#include <stdlib.h>

/**
 * get_binary - converts an unsigned int to binary
 * @n: integer
 * Return: pointer to binary
 */
char *get_binary(unsigned int n)
{
	char *binary = NULL;
	unsigned int i;
	unsigned int num = 0;
	unsigned int size = 0;

	if (n == 0)
	{
		binary = malloc(2);
		if (binary)
		{
			binary[0] = '0';
			binary[1] = '\0';
		}
		return (binary);
	}

	size = sizeof(int) * 8 + 1;
	binary = malloc(size);
	if (binary)
	{
		for (i = 0; i < size; i++)
		{
			binary[i] = '0';
		}
		binary[size - 1] = '\0';

		i = size - 2;
		while (n != 0)
		{
			binary[i] = n % 2 == 0 ? '0' : '1';
			num++;
			n = n / 2;
			i--;
		}
		num++;
		binary = move_left(binary, size, num);
	}
	return (binary);
}

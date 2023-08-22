#include "shell.h"

/**
 * move_left -removes leading 0's
 * @a: buffer
 * @size: size of array
 * @num: number of digits in the binary number
 * Return: buffer
 */
char *move_left(char *a, int size, int num)
{
	int i;
	char *ptr;

	for (i = 0, ptr = (a + size - num); i < num; i++, ptr++)
		*(a + i) = *ptr;
	*(a + num) = '\0';
	return (a);
}

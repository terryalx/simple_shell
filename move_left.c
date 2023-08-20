#include "shell.h"

/**
 * move_left - Removes leading 0's from a binary number
 * @binaryNumber: Buffer containing the binary number
 * @bufferSize: Size of the buffer
 * @numDigits: Number of digits in the binary number
 *
 * Return: Pointer to the modified buffer
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

#include "shell.h"
#include <stdlib.h>

/**
 * move_left - Removes leading 0's from a binary number
 * @binaryNumber: Buffer containing the binary number
 * @bufferSize: Size of the buffer
 * @numDigits: Number of digits in the binary number
 *
 * Return: Pointer to the modified buffer
 */
char *move_left(char *binaryNumber, int bufferSize, int numDigits)
{
	int i;
	char *ptr;

	for (i = 0, ptr = (binaryNumber + bufferSize - numDigits); i < numDigits; i++, ptr++)
	{
		*(binaryNumber + i) = *ptr;
	}

	*(binaryNumber + numDigits) = '\0';

	return (binaryNumber);
}

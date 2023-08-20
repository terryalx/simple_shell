#include "shell.h"
#include <stdlib.h>


/**
 * get_number - Convert an integer to a string.
 * @number: The integer to be converted.
 *
 * Return: A pointer to the string representation of the integer,
 *         or NULL if an error occurs.
 */
char *get_number(int number)
{
	int i, string_length = 0, temp;
	char *result = NULL;

	temp = number;

	while (temp != 0)
	{
		temp /= 10;
		string_length++;
	}
	string_length++;

	if (number < 0)
		string_length++;

	result = malloc(sizeof(char) * (string_length + 1));

	if (result)
	{
		result[string_length] = '\0';

		i = string_length - 1;

		do
		{
			temp = (number % 10) >= 0 ? number % 10 : -(number % 10);
			result[i] = temp + '0';
			i--;
			number /= 10;
		} while (number != 0);

		if (number < 0)
			result[0] = '-';
	}

	return result;
}

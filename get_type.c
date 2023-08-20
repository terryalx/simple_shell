#include "shell.h"

/**
 * get_type - get type from the specifier from format string
 * @format: format string
 * @index: current index of format string
 *
 * This function is responsible for extracting the type specifier from the format string.
 * It takes the format string and the current index as parameters.
 * The function iterates through the format string until it finds a non-space character.
 * The index is then updated to point to the next character after the type specifier.
 */
void get_type(char *format, int *index)
{
	do {
		*index += 1;
	} while (format[*index] == ' ');
}

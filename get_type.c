#include "shell.h"

/**
 * get_type - get type from the specifier from format string
 * @format: format string
 * @index: current index of format string
 */
void get_type(char *format, int *index)
{
	do {
		*index += 1;
	} while (format[*index] == ' ');
}

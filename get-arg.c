#include "shell.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - Returns formatted argument based on the type specifier.
 * @type: specifier ('c', 's', 'd', 'i', 'b', 'r', 'R').
 * @...: Arguments depending on the type specifier.
 *
 * Return: Dynamically allocated string -> argument
 *         or NULL if an unsupported type specifier
 */
char *get_arg(char type, ...)
{
	va_list params;
	char *result = NULL;

	va_start(params, type);

	switch (type)
	{
		case 'c':
			result = get_char(va_arg(params, int));
			break;
		case 's':
			result = get_string(va_arg(params, char *));
			break;
		case 'd':
		case 'i':
			result = get_number(va_arg(params, int));
			break;
		case 'b':
			result = get_binary(va_arg(params, int));
			break;
		case 'r':
			result = get_rev(va_arg(params, char *));
			break;
		case 'R':
			result = get_rot13(va_arg(params, char *));
			break;
		default:
			result = NULL;
			break;
	}

	va_end(params);

	return (result);
}

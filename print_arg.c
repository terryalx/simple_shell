#include "shell.h"
#include <unistd.h>

/**
 * print_arg - Prints a string to the standard output
 * @arg: The string to be printed
 *
 * Return: The number of bytes printed
 */
int print_arg(char *arg)
{
	return (write(STDOUT_FILENO, arg, _strlen(arg)));
}

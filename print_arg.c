#include "shell.h"

/**
 * print_arg - print argument string
 * @arg: string
 * Return: number of bytes printed
 */
int print_arg(char *arg)
{
	return (write(1, arg, _strlen(arg)));
}

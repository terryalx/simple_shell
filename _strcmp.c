#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 *
 * Return: an integer less than, equal to, or greater than 0 if str1 is,
 * respectively, less than, equal to, or greater than str2
 */
int _strcmp(char *str1, char *str2)
{
	int res = 0;

	do {
		res = *str1 - *str2;
		if (*str1 == 0 || *str2 == 0)
			break;
		str1++;
		str2++;
	} while (res == 0);

	return (res);
}

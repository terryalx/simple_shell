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
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}
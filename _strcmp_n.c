#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _strcmp_n - compares n bytes of two strings
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: an integer less than, equal to, or greater than 0 if str1 is,
 * respectively, less than, equal to, or greater than s2
 *
 * Description: This function compares the first `num` bytes of the strings
 * `s1` and `s2`. It returns an integer value that indicates whether `1`
 * is less than, equal to, or greater than `s2`. The comparison is performed
 * by subtracting the corresponding characters of the strings. If the result is
 * 0, the characters are equal; if the result is positive, `str1` is greater;
 * if the result is negative, `s1` is smaller.
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
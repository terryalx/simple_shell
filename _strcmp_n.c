#include "shell.h"

/**
 * _strcmp_n - compares n bytes of two strings
 * @str1: the first string to compare
 * @str2: the second string to compare
 * @num: the number of bytes to compare
 *
 * Return: an integer less than, equal to, or greater than 0 if str1 is,
 * respectively, less than, equal to, or greater than str2
 *
 * Description: This function compares the first `num` bytes of the strings
 * `str1` and `str2`. It returns an integer value that indicates whether `str1`
 * is less than, equal to, or greater than `str2`. The comparison is performed
 * by subtracting the corresponding characters of the strings. If the result is
 * 0, the characters are equal; if the result is positive, `str1` is greater;
 * if the result is negative, `str1` is smaller.
 */
int _strcmp_n(char *str1, char *str2, int num)
{
	int i = 0;
	int res = *str1 - *str2;

	while (i <= num)
	{
		res = *(str1++) - *(str2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}

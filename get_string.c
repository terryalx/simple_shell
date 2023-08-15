#include <stdlib.h>

/**
 * get_string - returns a new duplicated string
 * @s: string to be copied
 * Return: Null if string is null, else pointer of copied string
 */

char *get_string(char *s)
{
	char *ptr = NULL;
	int i, j;

	if (s == NULL)
	{
		ptr = malloc(7);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '(';
		ptr[1] = 'n';
		ptr[2] = 'u';
		ptr[3] = 'l';
		ptr[4] = 'l';
		ptr[5] = ')';
		ptr[6] = '\0';
		return (ptr);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		ptr[j] = s[j];
	}
	ptr[j] = '\0';
	return (ptr);
}

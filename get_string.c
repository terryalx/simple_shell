#include "shell.h"
#include <stdlib.h>

/**
 * get_string - returns a new duplicated string
 * @s: string to be copied
 *
 * Return: Null if string is null, else pointer of copied string
 */
char *get_string(char *s)
{
	char *duplicated_string = NULL;
	int string_length = 0, i;

	if (s == NULL)
	{
		duplicated_string = malloc(7);
		if (duplicated_string == NULL)
			return (NULL);
		duplicated_string[0] = '(';
		duplicated_string[1] = 'n';
		duplicated_string[2] = 'u';
		duplicated_string[3] = 'l';
		duplicated_string[4] = 'l';
		duplicated_string[5] = ')';
		duplicated_string[6] = '\0';
		return (duplicated_string);
	}

	while (s[string_length] != '\0')
	{
		string_length++;
	}

	duplicated_string = malloc((string_length + 1) * sizeof(char));
	if (duplicated_string == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= string_length; i++)
	{
		duplicated_string[i] = s[i];
	}

	return (duplicated_string);
}

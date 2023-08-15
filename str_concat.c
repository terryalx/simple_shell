#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string argument
 * @s2: second string argument
 * Return: Null on failure, else ptr to malloc
 */

char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i = 0;
	int j = 0;
	int x = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i] != '\0'; i++)
	{
		ptr[i] = s1[i];
		x++;
	}
	for (j = 0; s2[j] != '\0'; j++)
	{
		ptr[x] = s2[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

#include "shell.h"

/**
 * concatenate_strings_with_limit - Concatenates two strings.
 * @s1: First string argument.
 * @s2: Second string argument.
 * @n: Maximum number of bytes to concatenate from s2.
 *
 * Return: Pointer to a newly allocated string containing the
 * concatenated result, or NULL on failure.
 */
char *concatenate_strings_with_limit(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int j = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	if (n > j)
		n = j;

	ptr = malloc(sizeof(char) * (n + i) + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		ptr[i] = s1[i];

	for (j = 0; j < n; j++)
		ptr[i + j] = s2[j];

	ptr[i + j] = '\0';
	return (ptr);
}

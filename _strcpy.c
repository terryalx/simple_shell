#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _strcpy - copies a string to another memory address
 * @src: pointer to the source string
 * @dest: pointer to the destination address
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}
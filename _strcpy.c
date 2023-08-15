#include "main.h"
#include "shell.h"
#include "list.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _strcpy - copies a string to anther memory adress
 * @src: pointer to the source string
 * @dest: pointer to the dest address
 * Return: pointer to the dest
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

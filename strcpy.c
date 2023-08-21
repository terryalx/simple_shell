#include "shell.h"

/**
 * strcpy - Copy a string to another memory address
 * @dest: Pointer to the destination address
 * @src: Pointer to the source string
 *
 * Return: Pointer to the destination
 */
char *strcpy(char *dest, const char *src)
{
    int i = 0;

   while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

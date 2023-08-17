#include "shell.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: old block
 * @old_size: size of the old block
 * @new_size: size of the new block
 * Return: pointer to new block
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr = NULL;
	unsigned int numb;
	unsigned int i;

	if (!ptr)
	{
		free(ptr);
		return (malloc(sizeof(*ptr) * new_size));
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	numb = old_size < new_size ? old_size : new_size;
	new_ptr = malloc(8 * new_size);
	if (new_ptr)
	{
		for (i = 0; i < new_size; i++)
			new_ptr[i] = NULL;
		for (i = 0; i < numb; i++)
			new_ptr[i] = ptr[i];
		free(ptr);
	}
	return (new_ptr);
}

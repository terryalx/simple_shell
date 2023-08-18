#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - Reallocates a memory block using malloc.
 * @ptr: Pointer to the old block.
 * @old_size: Size of the old block.
 * @new_size: Size of the new block.
 *
 * Return: Pointer to the new block.
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr = NULL;
	unsigned int min_size;
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
	min_size = old_size < new_size ? old_size : new_size;
	new_ptr = malloc(sizeof(*new_ptr) * new_size);
	if (new_ptr)
	{
		for (i = 0; i < new_size; i++)
			new_ptr[i] = NULL;
		for (i = 0; i < min_size; i++)
			new_ptr[i] = ptr[i];
		free(ptr);
	}
	return (new_ptr);
}

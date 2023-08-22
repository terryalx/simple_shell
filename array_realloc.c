#include "shell.h"

/**
 * array_realloc - Reallocates an array of pointers with memory copying.
 * @ptr: Pointer to the old array.
 * @old_size: Size of the old array.
 * @new_size: Size of the new array.
 *
 * Return: Pointer to the new array.
 */
char **array_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr = NULL;
	unsigned int i;

	if (!ptr)
		return (malloc(sizeof(*ptr) * new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(sizeof(*new_ptr) * new_size);
	if (!new_ptr)
		return (NULL);

	for (i = 0; i < new_size; i++)
		new_ptr[i] = NULL;

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);
	return (new_ptr);
}

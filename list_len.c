#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - Returns the number of elements in a linked list_t list.
 * @h: The head of the list.
 *
 * Return: The length of the list.
 */
size_t list_len(list_t *h)
{
	size_t length = 0;

	while (h != NULL)
	{
		length++;
		h = h->next;
	}

	return (length);
}

#include "shell.h"

/**
 * list_len - Returns the number of elements in a linked list_t list.
 * @h: The head of the list.
 *
 * Return: The length of the list.
 */
size_t list_len(list_t *h)
{
	size_t i;

	for (i = 0; h != 0; i++)
		h = h->next;
	return (i);
}

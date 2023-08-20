#include "shell.h"

/**
 * get_node - Search for a node in a linked list.
 * @head: Pointer to the head of the list.
 * @str: Key to search for.
 *
 * Return: Pointer to the desired node, NULL if not found.
 */
list_t *get_node(list_t *head, char *str)
{
	list_t *h;

	if (!head)
		return (NULL);
	h = head;
	while (h)
	{
		if (!string_compare(h->str, str))
			break;
		h = h->next_node;
	}
	return (h);
}

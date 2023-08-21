#include "shell.h"
/**
 * get_node - search for a node
 * @head: start of list
 * @str: key
 * Return: ptr to desired node, NULL if not found
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

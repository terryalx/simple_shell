#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_node - Search for a node in a linked list.
 * @head: Pointer to the head of the list.
 * @str: Key to search for.
 *
 * Return: Pointer to the desired node, NULL if not found.
 */
list_t *get_node(list_t *head, char *str)
{
	list_t *current = head;

	while (current != NULL)
	{
		if (!_strcmp(current->str, str))
		{
			break;
		}
		current = current->next;
	}

	return current;
}

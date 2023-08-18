#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - Clears a linked list from memory.
 * @head: Pointer to the head of the linked list.
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next;

	while (current)
	{
		next = current->next;
		free(current->str);
		free(current->val);
		free(current);
		current = next;
	}
}

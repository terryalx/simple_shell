#include "shell.h"

/**
 * free_list - clears a linked list from mem
 * @head: ptr to head of linked list
 */
void free_list(list_t *head)
{
	list_t *ptr = head;

	while (head)
	{
		ptr = head->next_node;
		free(head->str);
		free(head->value);
		free(head);
		head = ptr;
	}
}

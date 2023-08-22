#include "shell.h"

/**
 * free_list - Frees a linked list and its nodes from memory.
 * @head: Pointer to the head of the linked list.
 *
 * This function frees the memory allocated for a linked list and its nodes.
 * It iterates through the list, deallocating the strings and values associated
 * with each node and then frees the node itself.
 *
 * @head: Pointer to the head of the linked list.
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

#include "main.h"
#include "shell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_list - clears a linked list from mem
 * @head: ptr to head of linked list
 */

void free_list(list_t *head)
{
	list_t *ptr = head;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head->val);
		free(head);
		head = ptr;
	}
}

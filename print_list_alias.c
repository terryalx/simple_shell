#include "main.h"
#include "shell.h"
#include "list.h"
#include <stdlib.h>

/**
 * print_list_alias - function that prints the name
 * and value of each alias in a linked list.
 * @head: pointer to the head of the linked list.
*/

void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}

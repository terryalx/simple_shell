#include "shell.h"

/**
 * print_list_alias - Prints the name and value of
 * each alias in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * This function recursively traverses a linked list
 * of aliases, printing the name and value of each
 * alias to stdout. It starts from the beginning of
 * the list and works its way to the end.
 */
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next_node);
		if (head->str != NULL)
			my_printf("%s=\'%s\'\n", head->str, head->value);
	}
}

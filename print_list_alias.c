#include "shell.h"

/**
 * print_alias_list - Prints the name and value of each alias in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * This function recursively traverses a linked list of aliases, printing the
 * name and value of each alias to stdout. It starts from the beginning of
 * the list and works its way to the end.
 */
void print_alias_list(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}

#include "shell.h"
#include <stdlib.h>

/**
 * print_list_alias - Prints the name and value of each alias in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Description: This function recursively traverses the linked list and prints
 * the name and value of each alias. It uses the _printf function to format
 * the output.
 */
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
		{
			_printf("%s='%s'\n", head->str, head->val);
		}
	}
}

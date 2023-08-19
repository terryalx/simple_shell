#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Start of the list
 *
 * Return: Length of the list
 */
size_t print_list(list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			break;
		printf("%s\n", h->str);
		h = h->next;
		count++;
	}

	return count;
}

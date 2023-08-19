#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - prints all the elements of a list_t list.
 * @h: start of list
 *
 * Return: length of list
 */

size_t print_list(list_t *h)
{
	int count;

	for (count = 0; h != 0; count++)
	{
		if (h->str == NULL)
			break;
		_printf("%s\n", h->str);
		h = h->next;
	}
	return (count);
}

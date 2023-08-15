#ifndef LIST
#define LIST
#include <unistd.h>

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int val_len;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(list_t *h);
size_t list_len(list_t *h);
list_t *add_node(list_t **head, char *str, char *val);
void free_list(list_t *head);
list_t *get_node(list_t *head, char *str);

#endif /*end LIST*/

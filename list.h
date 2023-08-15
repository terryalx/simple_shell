#ifndef _LIST_H
#define _LIST_H

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

char *move_left(char *a, int size, int num);
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize);
void rev_string(char *s);
char *rot13(char *s);
param_t *init_param(char **argv, char **env);
int validNum(char *s);
int flush_buffer(char *buffer, int *index);
void get_type(char *format, int *index);
int print_arg(char *arg);
int isDelim(char c, char *delim);

#endif /*end _LIST_H*/

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * Data structure to hold information about environment variables.
 */
typedef struct list_s
{
    char *str;                  /* The name of the environment variable */
    char *val;                  /* The value of the environment variable */
    unsigned int val_len;       /* Length of the value */
    struct list_s *next;        /* Pointer to the next node in the list */
} list_t;

/**
 * Data structure to hold shell parameters.
 */
typedef struct param_s
{
    unsigned int argsCap;       /* Capacity of args array */
    unsigned int lineCount;     /* Line count */
    unsigned int tokCount;      /* Token count */
    int status;                 /* Exit status */
    char **argv;                /* Command-line arguments */
    char *nextCommand;          /* Next command string */
    char *buffer;               /* Input buffer */
    char **args;                /* Argument list */
    list_t *env_head;           /* Environment variables list */
    list_t *alias_head;         /* Alias list */
} param_t;

/* Function prototypes */

/* main.c */
int main(int __attribute__((unused)) argc, char **argv, char **env);

/* list.c */
list_t *add_node(list_t **head, char *str, char *val);
void free_list(list_t *head);
list_t *get_node(list_t *head, char *str);
size_t print_list(list_t *h);
size_t list_len(list_t *h);

/* shell.c */
void run_command(param_t *params);
void sigint_handler(int __attribute__((unused)) s);

/* helpers.c */
int _putchar(char c);
int _puts(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char *_strtok(char *str, char *delim, char **saveptr);
int _strcmp(char *s1, char *s2);
int _strcmp_n(char *s1, char *s2, size_t n);
int _atoi(char *s);
char *get_number(unsigned int n);
void free_params(param_t *params);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string_functions.c */
char *get_string(char *s);
char *get_rev(char *s);
char *get_rot13(char *s);
char *str_concat(char *s1, char *s2);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *move_left(char *a, int size, int num);
void rev_string(char *s);
char *rot13(char *s);

/* list_helpers.c */
void print_list_env(list_t *head);
void print_list_alias(list_t *head);
void print_all_aliases(param_t *params);
void print_arg(char *arg);
void _printenv(param_t *params);
void make_alias(char *name, char *val, param_t *params);
void print_alias(char *name, param_t *params);

/* validation.c */
int validNum(char *s);
void write_error(param_t *params, char *msg);

/* getline.c */
int _getline(param_t *params);
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize);

/* init_param.c */
param_t *init_param(char **argv, char **env);

#endif /* SHELL_H */

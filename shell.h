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

/*
 * Macro
 */
#define NULL_PTR -1
#define WRONG_SPECIFIER -2
#define _GNU_SOURCE

/**
 * Data structure to hold information about environment variables.
 */
typedef struct list_s {
    char *str;
    char *value;
    unsigned int length;
    unsigned int value_length;
    struct list_s *next_node;
} list_t;

/**
 * param_t struct holds parameters
*/
typedef struct param_s
{
	char **argv;
	char *buffer;
	char **args;
	char *nextCommand;
	unsigned int argsCap;
	unsigned int lineCount;
	unsigned int tokCount;
	int status;
	list_t *env_head;
	list_t *alias_head;
} param_t;

typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

/**
 * Main functions
*/
int read_dynamic_line(param_t *);
int string_compare(char *, char *);
int _strncmp(char *, char *, int n);
int split_command_into_tokens(param_t *);
char *str_duplicate(char *);
char *string_copy(char *dest, const char *src);
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size);
char *token_(char *str, char *delim, char **savePtr);
char *_getenv(char *name, param_t *params);
char *get_file(param_t *params);
void run_command(param_t *);
void _printenv(param_t *);
void sigint_handler(int);
void _setenv(param_t *params);
void _unsetenv(param_t *params);
void (*get_builtin(param_t *params))(param_t *);
void _myExit(param_t *params);
void _cd(param_t *params);
void _alias(param_t *params);
void set_alias(char *name, param_t *params);
void make_alias(char *name, char *val, param_t *params);
void print_alias(char *name, param_t *params);
void print_all_aliases(param_t *params);
void print_list_env(list_t *);
void print_list_alias(list_t *);
void free_params(param_t *params);
void write_error(param_t *params, char *msg);
void _clear(param_t *params);
void handle_alias(param_t *params, char *token, list_t *node);
void handle_regular(param_t *params, char *token, char *state);

param_t *init_param(char **argv, char **env);


/**
 * MAIN
*/
/*
 * List of my main.h prototypes
 */

char *get_char(char c);
char *get_string(char *s);
char *get_number(int n);
char *get_arg(char type, ...);
char *get_binary(unsigned int n);
char *get_rev(char *s);
char *get_rot13(char *s);
char *str_concat(char *, char *);
char *string_nconcat(char *, char *, unsigned int);
int _strlen(char *);
int _printf(const char *, ...);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);


/**
 * LIST
*/

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
int validNum(char *s);
int flush_buffer(char *buffer, int *index);
void get_type(char *format, int *index);
int print_arg(char *arg);
int isDelim(char c, char *delim);


#endif /*end _SHELL_H*/
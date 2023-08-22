#ifndef __SHELL__H__
#define __SHELL__H__

/* System Calls */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

/*
 * M a c r o
 */
#define NULL_PTR -1
#define WRONG_SPECIFIER -2
#define _GNU_SOURCE

/**
 * Linked List
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

/* */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

/* M A I N */
int process_string(param_t *);
void execute_external_command(param_t *);
void _printenv(param_t *);
void sigint_handler(int);
char *_getenv(char *name, param_t *params);
char *get_file(param_t *params);

void _alias(param_t *params);
void set_alias(char *name, param_t *params);



void print_alias(char *name, param_t *params);
void print_all_aliases(param_t *params);
void print_list_env(list_t *);
void print_list_alias(list_t *);
void free_params(param_t *params);
void __write_error__(param_t *params, char *msg);

param_t *init_param(char **argv, char **env);

/* M A I N */

#define NULL_PTR -1
#define WRONG_SPECIFIER -2

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
char *concatenate_strings_with_limit(char *, char *, unsigned int);
int _strlen(char *);

/* L I S T */
size_t print_list(list_t *h);
size_t list_len(list_t *h);

void free_list(list_t *head);
list_t *get_node(list_t *head, char *str);

char *move_left(char *a, int size, int num);
void rev_string(char *s);
char *rot13(char *s);
int validNum(char *s);
void get_type(char *format, int *index);
int print_arg(char *arg);
int isDelim(char c, char *delim);


/* M A I N */

int string_to_int(char *s);
int my_printf(const char *, ...);
int string_compare(char *, char *);
int strncmp_custom(char *str1, char *str2, int n);
void set_or_update_environment_variable(param_t *params);
char *str_duplicate(char *);
char *find_character_in_string(char *s, char c);
char **array_realloc(char **ptr, unsigned int old_size, unsigned int new_size);
char *string_copy(char *dest, const char *src);
char *token_(char *str, char *delim, char **savePtr);
void remove_environment_variable(param_t *params); /* _unsetenv | str_length */
list_t *prepend_list_node(list_t **head, char *str, char *val); /* add_node */
void change_directory(param_t *params); /* _cd */
void clear_terminal_screen(param_t *params); /* _clear */
void (*find_builtin_function(param_t *params))(param_t *); /* get_builtin */
void create_alias(char *name, char *value, param_t *params); /* make_alias */
void myExit(param_t *params); /* _myExit */
int read_line(param_t *); /* _getline */
char *realloc_line_buffer(char **line, unsigned int oldSize, unsigned int newSize); /* rlLine */
int write_and_reset_buffer(char *buffer, int *index); /* flush_buffer */

#endif /* end __SHELL__H__ */

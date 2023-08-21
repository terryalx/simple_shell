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
 * Macro
 */
#define NULL_PTR -1
#define WRONG_SPECIFIER -2
#define _GNU_SOURCE

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int val_len;
	struct list_s *next;
} list_t;

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

int process_string(param_t *);
char *_strdup(char *);
char *_strcpy(char *dest, const char *src);
int _getline(param_t *);
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);
char *_strtok(char *str, char *delim, char **savePtr);
void run_command(param_t *);
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size); /*Here*/
void _printenv(param_t *);
void sigint_handler(int);
char *_getenv(char *name, param_t *params);
void _setenv(param_t *params);
void _unsetenv(param_t *params);
char *get_file(param_t *params);
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
char *string_nconcat(char *, char *, unsigned int);
int _strlen(char *);
int _printf(const char *, ...);
char *_strchr(char *s, char c);
int string_to_int(char *s); /*_atoi */
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);

/* L I S T */

#include <unistd.h>

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

#endif /* end __SHELL__H__ */
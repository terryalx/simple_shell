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
typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int val_len;
	struct list_s *next;
} list_t;

/**
 * Data structure to hold shell parameters.
 */
typedef struct param_s
{
	unsigned int argsCap;
	unsigned int lineCount;
	unsigned int tokCount;
	int status;
	char **argv;
	char *nextCommand;
	char *buffer;
	char **args;
	list_t *env_head;
	list_t *alias_head;
} param_t;

/*
 * Data structure to hold information about environment variables.
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;

/* Function prototypes */

/* main helper */
char *get_char(char c);
char *get_string(char *s);
char *get_number(int n);
char *get_arg(char type, ...);
char *get_binary(unsigned int n);
char *get_rev(char *s);
char *get_rot13(char *s);
char *str_concat(char *, char *);
char *string_nconcat(char *, char *, unsigned int);
size_t _strlen(const char *s);
int _printf(const char *, ...);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);

/* linked list */
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
int is_valid_number(char *str);
int flush_buffer(char *buffer, int *index);
void get_type(char *format, int *index);
int print_arg(char *arg);
int isDelim(char c, char *delim);

/* shell helper */
int process_string(param_t *);
char *_strdup(char *);
char *_strcpy(char *dest, const char *src);
int _getline(param_t *);
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);
char *token_(char *str, char *delim, char **savePtr);
void run_command(param_t *);
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size); /*Here*/
void _printenv(param_t *);
void sigint_handler(int);
char *_getenv(const char *name, param_t *params);
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
void clear_screen(param_t *params);

/* init_param.c */
param_t *init_param(char **argv, char **env);

void handle_dash(param_t *params);
void handle_malloc_error(void);
void handle_chdir_error(param_t *params, char *target);
void update_oldpwd(param_t *params);
char **create_tmp_args(param_t *params);
void setenv_oldpwd(char *pwd, param_t *params);
void setenv_pwd(char **tmpArgs, char *cwd, param_t *params);
void free_tmp_args(char **tmpArgs);
void restore_original_args(param_t *params, char **originArgs);

char **create_setenv_args(char *command, char *variable, char *value);


#endif /* SHELL_H */

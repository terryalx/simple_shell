#ifndef _MAIN_H_
#define _MAIN_H_
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
int _atoi(char *s);
int _strcmp(char *, char *);
int _strcmp_n(char *, char *, int n);

#endif /*end MAIN*/

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMETERS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/**
 * struct parameters - structure that contains all the parameters (flags )
 * @unsign: unsigned value flag
 * @plus_flag: plus flag
 * @hashtag_flag: hashtag flag
 * @zero_flag: zero flag
 * @space_flag: space flag
 * @minus_flag: minus flag (left justified)

 * @width: field width
 * @precision: field precision

 * @h_modifier: h modifier specifications(short int)
 * @l_modifier: l modifier specifications(long int)

 */
typedef struct parameters
{
  unsigned int unsign        : 1;


  unsigned int plus_flag     : 1;
  unsigned int space_flag    : 1;
  unsigned int hashtag_flag  : 1;
  unsigned int zero_flag     : 1;
  unsigned int minus_flag    : 1;

  unsigned int width         : 1;
  unsigned int precision     : 1;

  unsigned int h_modifier    : 1;
  unsigned int l_modifier    : 1;
} parameters_t;

/**
 * struct specifier - structure that contains all the specifiers

 * @specifier: specifier
 * @f: function associated
 */
typedef struct specifier
{
  char *specifier;
  int (*f)(va_list, parameters_t *);
} specifier_t;

/* output.c functions */
int _putchar(int c);
int _puts(char *str);

/* print_functions.c functions */
int print_char(va_list list, parameters_t *params);
int print_string(va_list list, parameters_t *params);
int print_percent(va_list list, parameters_t *params);
int print_integer(va_list list, parameters_t *params);
int print_S(va_list list, parameters_t *params);

/* num_functions.c functions */
char *convert_number(long int numb, int base, int flag, parameters_t *params);
int print_unsigned(va_list list, parameters_t *params);
int print_address(va_list list, parameters_t *params);

/* specifiers.c functions */
int (*get_specifier(char *s))(va_list list, parameters_t *params);
int get_print_func(char *s, va_list list, parameters_t *params);
int get_flag(char *s, parameters_t *params);
char *get_width(char *s, va_list list, parameters_t *params);
int get_modifier(char *s, parameters_t *params);

/* convert_num.c functions */
int print_hex(va_list list, parameters_t *params);
int print_HEX(va_list list, parameters_t *params);
int print_octal(va_list list, parameters_t *params);
int print_binary(va_list list, parameters_t *params);

/* other_print.c functions */
int print_out(char *start, char *stop, char *except);
int print_rev(va_list list, parameters_t *params);
int print_rot13(va_list list, parameters_t *params);

/* print_num.c functions */
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, parameters_t *params);
int print_num_right(char *str, parameters_t *params);
int print_num_left(char *str, parameters_t *params);

/* parameters.c functions */
void init_params(parameters_t *params, va_list list);

/* string_precision.c functions */
char *get_precision(char *p, va_list list, parameters_t *params);

/* _printf.c functions */
int _printf(const char *format, ...);

#endif

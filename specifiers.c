#include "main.h"

/**
 * get_specifier - function to handle specifiers
 * @s: function parameter
 * @va_list: argument the function
 * @parameters_t: another argument
 * Return: bytes
 */

int (*get_specifier(char *s))(va_list list, parameters_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_integer},
		{"i", print_integer},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - function to find format function
 * @s: function parameter (input string)
 * @list: another function parameter (input arguments list)
 * @params: another function parameter (input parameters)
 * Return: bytes
 */

int get_print_func(char *s, va_list list, parameters_t *params)
{
	int (*f)(va_list, parameters_t *) = get_specifier(s);

	if (f)
		return (f(list, params));
	return (0);
}

/**
 * get_flag - function to handle flag
 * @s: function parameter (input string)
 * @params: innput parameters
 * Return: result
 */

int get_flag(char *s, parameters_t *params)
{
	int i;

	i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - function to handle modifiers
 * @s: input string parameter
 * @params: parameters struct
 * Return: result
 */

int get_modifier(char *s, parameters_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - function to handle width
 * @s: input string
 * @list: argument list input
 * @params: parameter struct
 * Return: result
 */

char *get_width(char *s, va_list list, parameters_t *params)
{
	int a = 0;

	if (*s == '*')
	{
		a = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			a = a * 10 + (*s++ - '0');
	}
	params->width = a;
	return (s);
}


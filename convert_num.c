#include "main.h"

/**
 * print_hex - function that prints a hexadeciamal lowercase
 * @list: function input parameter
 * @params: parameters structure set
 * Return: characters printed
 */

int print_hex(va_list list, parameters_t *params)
{
	unsigned long l;
	int k = 0;
	char *s;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	s = convert_number(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (k += print_num(s, params));
}

/**
 * print_HEX - function that prints a hexadecimal in upper case
 * @list: function input parameter
 * @params: parameters structure set
 * Return: characters printed
 */

int print_HEX(va_list list, parameters_t *params)
{
	unsigned long l;
	int k = 0;
	char *s;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	s = convert_number(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (k += print_num(s, params));
}

/**
 * print_binary - function that prints a binary number
 * @list: functiom input (argument list)
 * @params: parameters structure set
 * Return: characters printed
 */

int print_binary(va_list list, parameters_t *params)
{
	unsigned int k = va_arg(list, unsigned int);
	char *s = convert_number(k, 2, CONVERT_UNSIGNED, params);
	int i = 0;

	if (params->hashtag_flag && k)
		*--s = '0';
	params->unsign = 1;
	return (i += print_num(s, params));
}

/**
 * print_octal - function that print a number in octal (base 8)
 * @list: function input (argument)
 * @params: prameters
 * Return: characters outputted
 */

int print_octal(va_list list, parameters_t *params)
{
	unsigned long l;
	char *s;
	int k = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	s = convert_number(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--s = '0';
	params->unsign = 1;
	return (k += print_num(s, params));
}

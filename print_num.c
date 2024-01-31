#include "main.h"

/**
 * _isdigit - function that checks for a digit
 * @c: input
 * Return: result
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - function to find the length of a string
 * @s: input string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int k = 0;

	while (*s++)
		k++;
	return (k);
}

/**
 * print_num - function to print a number
 * @s: input string
 * @params: parameters structre set
 * Return: characters printed
 */

int print_num(char *s, parameters_t *params)
{
	unsigned int k = _strlen(s);
	int val = (!params->unsign && *s == '-');

	if (!params->precision && *s == '0' && !s[1])
		s = "";
	if (val)
	{
		s++;
		k--;
	}
	if (params->precision != UINT_MAX)
		while (k++ < params->precision)
			*--s = '0';
	if (val)
		*--s = '-';

	if (!params->minus_flag)
		return (print_num_right(s, params));
	else
		return (print_num_left(s, params));
}

/**
 * print_num_right - function that print a number with conditions
 * @str: function input string
 * @params: parameters structure set
 * Return: characaters printed
 */

int print_num_right(char *str, parameters_t *params)
{
	unsigned int k = 0;
	unsigned int val1, val2, j = _strlen(str);
	char space = ' ';

	if (params->zero_flag && !params->minus_flag)
		space = '0';
	val1 = val2 = (!params->unsign && *str == '-');
	if (val1 && j < params->width && space == '0' && !params->minus_flag)
		str++;
	else
		val1 = 0;
	if ((params->plus_flag && !val2) || (!params->plus_flag && params->space_flag && !val2))
		j++;
	if (val1 && space == '0')
		k += _putchar('-');
	if (params->plus_flag && !val2 && space == '0' && !params->unsign)
		k += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !val2 && !params->unsign && params->zero_flag)
		k += _putchar(' ');
	while (j++ < params->width)
		k += _putchar(space);
	if (val1 && space == ' ')
		k += _putchar('-');
	if (params->plus_flag && !val2 && space == ' ' && !params->unsign)
		k = _putchar('+');
	else if (!params->plus_flag && params->space_flag && !val2 && !params->unsign && !params->unsign && !params->zero_flag)
		k += _putchar(' ');
	k += _puts(str);
	return (k);
}

/**
 * print_num_left - function that prints a number under conditions
 * @str: input
 * @params: parameters structure set
 * Return: characters printed
 */

int print_num_left(char *str, parameters_t *params)
{
	unsigned int k = 0;
	unsigned int val1, val2, j = _strlen(str);
	char space = ' ';

	if (params->zero_flag && !params->minus_flag)
		space = '0';
	val1 = val2 = (!params->unsign && *str == '-');
	if (val1 && j < params->width && space == '0' && !params->minus_flag)
		str++;
	else
		val1 = 0;

	if (params->plus_flag && !val2 && !params->unsign)
		k += _putchar('+'), j++;
	else if (params->space_flag && !val2 && !params->unsign)
		k += _putchar(' '), j++;
	k += _puts(str);
	while (j++ < params->width)
		k += _putchar(space);
	return (k);
}

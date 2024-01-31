#include "main.h"

/**
 * print_char - function that prints a character
 * @list: function argument
 * @params: parameters
 * Return: characters printed
 */

int print_char(va_list list, parameters_t *params)
{
	char space = ' ';
	unsigned int pad = 1;
	unsigned int sum = 0;
	unsigned int i = va_arg(list, int);

	if (params->minus_flag)
		sum += _putchar(i);
	while (pad++ < params->width)
		sum += _putchar(space);
	if (!params->minus_flag)
		sum += _putchar(i);
	return (sum);
}

/**
 * print_integer - function to print an integer
 * @list: function argument
 * @params; parameters
 * Return: characters printed
 */

int print_integer(va_list list, parameters_t *params)
{
	long i;

	if (params->l_modifier)
		i = va_arg(list,long);
	else if (params->h_modifier)
		i = (short int)va_arg(list, int);
	else
		i = (int)va_arg(list, int);
	return (print_num(convert_number(i, 10, 0, params), params));
}

/**
 * print_string - function to print a string
 * @list: function argument
 * @params: parameters
 * Return: characters printed
 */

int print_string(va_list list, parameters_t *params)
{
	char *s = va_arg(list, char *);
	char space = ' ';
	unsigned int pad = 0;
	unsigned int sum = 0;
	unsigned int i = 0;
	unsigned int j;

	(void)params;
	switch ((int)(!s))
	case 1:
		s = NULL_STRING;

	j = pad = _strlen(s);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _puts(s);
	}
	while (j++ < params->width)
		sum += _putchar(space);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _puts(s);
	}
	return (sum);
}

/**
 * print_percent - function to print percent sign
 * @list: function argument
 * @params: parameters
 * Return: characters printd
 */

int print_percent(va_list list, parameters_t *params)
{
	(void)list;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - function o print custom S specifier
 * @list: function argument
 * @params: parameters
 * Return: charcters printed
 */

int print_S(va_list list, parameters_t *params)
{
	char *s = va_arg(list, char *);
	char *h;
	int sum = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			h = convert_number(*s, 16, 0, params);
			if (!h[1])
				sum += _putchar('0');
			sum += _puts(h);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}

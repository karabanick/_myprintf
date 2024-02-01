#include "main.h"

/**
 * get_precision - function to get string precision
 * @p: pointer to string
 * @list: argument list
 * @params: parameters struct under consideration
 * Return: result
 */

char *get_precision(char *p, va_list list, parameters_t *params)
{
	int a = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		a = va_arg(list, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			a = a * 10 + (*p++ - '0');
	}
	params->precision = a;
	return (p);
}


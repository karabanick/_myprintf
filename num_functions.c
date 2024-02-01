#include "main.h"

/**
 * convert_number - function that converts input
 * @numb: input number
 * @base: base of conversion
 * @flag: flags for convrsion
 * @params: parameters in consideration
 * Return: result
 */

char *convert_number(long int numb, int base, int flag, parameters_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = numb;
	(void)params;

	if (!(flag & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - function that prints unsigned integers
 * @list: input
 * @params: parameters structure set
 * Return: characters printd
 */

int print_unsigned(va_list list, parameters_t *params)
{
	unsigned long i;

	if (params->l_modifier)
		i = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(list, unsigned int);
	else
		i = (unsigned int)va_arg(list, unsigned int);
	params->unsign = i;
	return (print_num(convert_number(i, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - function to print an address (pointer)
 * @list: input
 * @params: paramters struct
 * Return: characters printed
 */

int print_address(va_list list, parameters_t *params)
{
	unsigned long int i = va_arg(list, unsigned long int);
	char *s;

	if (!i)
		return (_puts("(nill)"));
				s = convert_number(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
				*--s = 'x';
				*--s = '0';
				return (print_num(s, params));
}


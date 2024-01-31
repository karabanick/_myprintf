#include "main.h"

/**
 * _printf - function that prints according to format & specifiers
 * @format: input format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list list;
	char *p, *start;
	parameters_t params = PARAMETERS;

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, list);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, list, &params);
		p = get_precision(p, list, &params);

		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_out(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, list, &params);
	}
	_putchar(BUFF_FLUSH);
	va_end(list);
	return (sum);
}


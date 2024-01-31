#include "main.h"

/**
 * print_out - function to print a range of characters
 * @start: start
 * @stop: stop
 * @except: exclude
 * Return: characters printed
 */

int print_out(char *start, char *stop, char *except)
{
	int sum;

	sum = 0;
	while (start != stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - function to print string in reverse
 * @list: input string
 * @params: struct set of parameters
 * Return: chracters printed
 */

int print_rev(va_list list, parameters_t *params)
{
	int len = 0;
	int sum = 0;
	char *str = va_arg(list, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
		       sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - function to print rot13
 * @list: input
 * @params:struct set of parameters
 * Return: characters printd
 */

int print_rot13(va_list list, parameters_t *params)
{
	int i;
	int index;
	int count = 0;
	char arry[] = "NOPQRSTUVWXYZABCDEFGHIJKLM       nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arry[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return(count);
}

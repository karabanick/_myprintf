#include "main.h"

/**
 * _puts - function to print a string
 * @str: function parameter
 * Return: nothing
 */

int _puts(char *str)
{
	char *p;

	p = str;

	while (*str)
		_putchar(*str++);
	return (str - p);
}

/**
 * _putchar - function that prints a character
 * @c: function parameter
 * Return: 1
 */

int _putchar(int c)
{
	static int i;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}

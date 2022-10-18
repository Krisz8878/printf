#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - A function that prints to stdout like printf.
 * @format: A string with maybe or not include various arguments passed to the
 * function.
 * Return: length of format string
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char *temp;
	int i = 0, num, rem, bin = 0, mon = 1;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
			case 'c':
				_putchar((char) va_arg(ap, int));
				break;
			case '%':
				_putchar('%');
				break;
			case 's':
				temp = va_arg(ap, char*);
				while (*temp)
					_putchar(*temp++);
				break;
			case 'd':
				num = va_arg(ap, int);
					print_number(num);
				break;
			case 'i':
				num = va_arg(ap, int);
					print_number(num);
				break;
			case 'b':
				num = va_arg(ap, int);
					if (num == 0)
						_putchar(num);
					if (num > 0)
					{
					while (num != 0)
					{
					rem = num % 2;
					num /= 2;
					bin += rem * mon;
					mon *= 10;
					}
					}
				print_number(bin);
				break;
			}
			++i;
			continue;
		}
		_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (i);
}

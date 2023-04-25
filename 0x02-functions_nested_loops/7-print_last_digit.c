#include <stdio.h>
#include "main.h"
#include "6-abs.c"

/**
 * print_last_digit - main function
 *
 * @a: integer to get last digit of
 * Return: last digit of n
 *
 */
int print_last_digit(int a)
{
	_putchar('0' + _abs(a % 10));
	return (_abs(a % 10));

}

#include <stdio.h>
#include "main.h"
#include "6-abs.c"

/**
 * _print_last_digit - main function
 *
 * @a: integer to make absolute
 * Return: int or int times negative
 *
 */
int print_last_digit(int a)
{
	if (a >= 0 && a <= 9)
	{
		return (a);
	}
	else
	{
		a = _abs(a % 10);
		return (a);
	}
}

#include "main.h"

/**
 * print_binary - prints binary
 *
 * @n: unsigned long int
 *
 * return: 0
 *
 */
void print_binary(unsigned long int n)
{
	if (n >> 0)
	{
		print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
	else
	{
		_putchar('0');
	}
}

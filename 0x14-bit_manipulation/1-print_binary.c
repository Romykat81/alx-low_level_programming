#include "main.h"

/**
 * print_binary - converts dec to bin
 * @n: dec
 */
void print_binary(unsigned long int n)
{
	int tmp;
	static int c;

	if (n == 0 && c > 0)
		return;
	else if (n == 0)
	{
		_putchar('0');
		return;
	}

	tmp = (n & 1);
	c++;
	print_binary(n >>= 1);
	_putchar('0' + tmp);
}

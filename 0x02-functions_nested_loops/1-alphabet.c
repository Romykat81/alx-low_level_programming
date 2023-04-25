#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always returns 0
 *
 */
void print_alphabet(void)
{
	char a = 'a';

	while (a <= 'z')
	{
		_putchar(a);
		a++;
	}
	_putchar(a);

	return(0);
}

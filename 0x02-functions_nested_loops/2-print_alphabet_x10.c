#include <stdio.h>
#include "main.h"

/**
 * print_alphabet_x10 - print alphabet ten times
 *
 *Return: always 0
 */
void print_alphabet_x10(void)
{
	int b;
	char a;

	for (b = 0; b < 10; b++)
	{
		for (a = 'a'; a <= 'z'; a++)
		{
			_putchar(a);
		}
		_putchar('\n');
	}
}

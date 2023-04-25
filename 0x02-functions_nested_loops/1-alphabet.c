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
	char a;
	
	for(a = 'a'; a <= 'z'; a++)
		_putchar(a);

	_putchar ('\n');
}

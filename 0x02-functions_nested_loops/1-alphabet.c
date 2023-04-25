#include <main.h>
/**
 *main - print alphabet
 *
 *Return: always 0
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

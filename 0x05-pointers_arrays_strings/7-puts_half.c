#include "main.h"
#include "2-strlen.c"
/**
 * puts_half - puts half an int
 *
 * @str: string to split
 */
void puts_half(char str)
{
	int i;
	int c = 0;

	if (_strlen(str) % 2 != 0)
	{
		c += 1;
	}
	for (i = (_strlen(str) + c / 2; i < _strlen(str); i++))
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

#include "main.h"
#include <stdio.h>

/**
 * more_numbers - prints the numbers
 *
 * _puchar only 3 times
 * Return: 0-14 x10 and new line
 *
 */
void more_numbers(void)
{
	int i;
	int h;

	for (h = 0; h < 10; h++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i >= 10)
			{
				_putchar((i / 10) + '0')
			}
			_putchar((i % 10) + '0');
		}
		_putchar('\n');
	}
}

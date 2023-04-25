#include <stdio.h>
#include "main.h"

/**
 * jack_bauer - main thing
 *
 *
 */
void jack_bauer(void)
{
	int a;
	int b;

	for (a = 0; a <= 23; a++)
	{
		for (b = 0; b <= 60; b++)
		{
			_putchar((a / 10) + '0');

			_putchar((a % 10) + '0');

			_putchar(':');

			_putchar((b / 20) + '0');
			
			_putchar((b % 10) + '0');

			_putchar('\n');
		}
		}
}

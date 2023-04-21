#include <stdio.h>
/**
 * main - prints all numbers of base 16
 *
 * Return: 0
 **/
int main(void)
{
	int i;
	unsigned char a = '0';

	for (i = 0; i < 10; i++)
	{
		putchar(a);
		a++;
	}
	a = '1';
	for (i = 0; i < 6; i++)
	{
		putchar('0' + a);
		a++;
	}
	putchar('\n');
	return (0);
}

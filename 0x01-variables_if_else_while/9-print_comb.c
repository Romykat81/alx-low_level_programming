#include <stdio.h>
/**
 * main - Write a program that prints all possible combinations of single-digit numbers
 *
 * return: 0
 **/
int main(void)
{
	int i;

	for (int i = 10; i < 20; i++)
	{
		putchar((i % 10) + '0');
		if (i != 19)
		{
			putchar(',');
			putchar(' ');	
		}
	}
	putchar('\n');
	return (0);
}

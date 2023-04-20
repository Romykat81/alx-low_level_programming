/*
 *
 * File:101-quote.c
 * Auth: Romykat81 <romaana.k7@gmail.com>
 */

#include <stdio.h>
#include <unistd.h>
/**
 *main  - prints "and that piece of art is useful" - Dora Korpar, 2015-10-19,
 *      followed by a new line, to standard error.
 *
 *Return: 1 if success.
 */
int main(void)
{
	write(2,
		"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
		59);

	return (1);
}

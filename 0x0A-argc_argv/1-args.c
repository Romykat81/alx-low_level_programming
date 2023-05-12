#include "main.h"
#include <stdio.h>
#define UNUSED(x) (void)(x)

/**
 * main - main func
 * @argc: argument c
 * @argv: vector
 * return: always 0
 */
int main(int argc, char *argv[])
{
	UNUSED(argv);
	printf("%d\n", argc - 1);
	return (0);
}

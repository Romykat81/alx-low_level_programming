#include "variadic_functions.h"

/**
 * print_strings - prints two strings
 * @separator: character that separates the strings
 * @n: number of strings
 */
void print_strings(const char *seperator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (seperator != NULL && i > 0)
			printf("%s", seperator);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
	}
	va_end(args);
	printf("\n");
}

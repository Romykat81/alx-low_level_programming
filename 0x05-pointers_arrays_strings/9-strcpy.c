#include "main.h"
#include "2-strlen.c"
#include <stdio.h>
/**
 * _strcpy - main to copy
 *
 * @dest: copy to
 * @src: copy from
 *
 * return: a char
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; <= _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

#include "main.h"
#include <stdio.h>
/**
 * _strcat - concats 2 arrays
 *
 * @dest: destination
 * @src: source
 *
 * Return: char
 */
char *strcat(char *dest, char *src)
{
	int i;
	int j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}

	return (dest);
}

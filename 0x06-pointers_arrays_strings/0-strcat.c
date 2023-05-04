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
	int i = 0;
	int j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}

	while (j >= 0)
	{
		*(dest + i) = *(src + j);
		if (*(src + j) == '\0')
			break;
			i++;
			j++;
	}
	return (dest);
	
}

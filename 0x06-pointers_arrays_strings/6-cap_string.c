#include "main.h"
/**
 * _indexOf - returns special character
 * @a: character to return
 * Return: true or false
 */
int _indexOf(char a)
{
	int i;

	char capArr[13] = {'\n', '\t', ' ', '.', ',', ';', ',', '!', '?', '(', ')', '{', '}'};

	for (i = 0; i < 13; i++)
	{
		if (capArr[i] == a)
			return (1);
	}
	return (0);
}

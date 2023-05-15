#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * wordcheck-checks word
 * @word: wordcount
 * @len: length
 * @str: string to go through
 * @s: array you are assigning
 * Return: char value
 */
char **wordcheck(int word, int len, char *str, char **s)
{
	int i, k, j;

	j = 0;
	for (i = 0; i < word; i++)
	{
		k = 0;
		for ( ; j < len; j++)
		{
			if (str[0] != ' ' || str[j] != ' ')
			{
				s[i][k] = str[j];
				k++;
			}
			if (j != 0 && str[j] == ' ' && str[j - 1] != ' ')
			{
				j++;
				break;
			}
		}
		s[i][k + 1] = '\0';
	}
	s[word + 1] = NULL;
	return (s);
}
/**
 * strtow - string to words
 * @str: string to check
 * Return: return char value
 */
char **strtow(char *str)
{
	int i, j, k, w, size, l;
	char **s;

	if (str == NULL)
		return (NULL);
	l = 0;
	w = 0;
	while (str[l] != '\0')
	{
		if (str[0] != ' ')
			w++;
		if (str[l] != ' ' && str[l - 1] == ' ' && l != 0)
			w++;
		l++;
	}
	s = (char **)malloc(sizeof(char *) * w + 1);
	if (s == NULL)
		return (NULL);
	j = 0;
	for (i = 0; i < w; i++)
	{
		size = 0;
		for (; j < l; j++)
		{
			if (str[0] != ' ' || str[j] != ' ')
				size++;
			if (str[j] == ' ' && size > 0)
				break;
		}
		printf("%d\n", size);
		s[i] = (char *)malloc(sizeof(char) * size + 1);
		if (s[i] == NULL)
		{
			for (k = i - 1; k >= 0; k--)
				free(s[k]);
			free(s);
		}
	}
	s = wordcheck(w, l, str, s);
	return (s);
}

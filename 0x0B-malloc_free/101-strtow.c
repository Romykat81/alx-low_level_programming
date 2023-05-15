#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * wordcounter - counts words and the letters in them
 * @str: string to count
 * @pos: position of the word to count characters from
 * @firstchar: position of the first letter of the word
 * if pos = 0, count the number of chars in the word
 * else count number of words
 * Return: wordcount if pos == 0,
 * length of word if pos > 0,
 * position of word if pos > 0 && firstchar > 0
 */
int wordcounter(char *str, int pos, char firstchar)
{
	int i, wordcount, charc, k;

	str[0] != ' ' ? (wordcount = 1) : (wordcount = 0);
	for (i = 0, k = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0' && k == 0)
		{
			wordcount++;
			k = 1;
		}
		if (pos > 0 && pos == wordcount)
		{
			if (pos > 0 && pos == wordcount && firstchar > 0)
				return (i);
			for (charc = 0; str[i + charc + 1] != ' '; charc++)
				;
			return (charc);
		}
		if (str[i] == ' ')
			k = 0;
	}
	return (wordcount);
}
/**
 * strtow - convert a string into a 2d array of words
 * @str: string to convert
 * Return: double pointer to 2d array
 */
char **strtow(char *str)
{
	int wc, wordlen, char1, k, i, j;
	char **p;

	for (k = 0; str[k]; k++)
		;
	if (str == NULL)
		return (NULL);
	wc = wordcounter(str, 0, 0);
	if (k == 0 || wc == 0)
		return (NULL);
	p = malloc((wc + 1) * sizeof(void *));
	if (p == NULL)
		return (NULL);

	for (i = 0, wordlen = 0; i < wc; i++)
	{
		/* Allocate mem for neted elements */
		wordlen = wordcounter(str, i + 1, 0);
		if (i == 0 && str[i] != ' ')
			wordlen++;
		p[i] = malloc(wordlen * sizeof(char) + 1);
		if (p[i] == NULL)
		{
			for ( ; i >= 0; --i)
				free(p[i]);
			free(p);
			return (NULL);
		}
		/* intialize ea element of nested array */
		char1 = wordcounter(str, i + 1, 1);
		if (str[0] != ' ' && i > 0)
			char1++;
		else if (str[0] == ' ')
			char1++;
		for (j = 0; j < wordlen; j++)
			p[i][j] = str[char1 + j];
		p[i][j] = '\0';
	}
	p[i] = NULL;
	return (p);
}

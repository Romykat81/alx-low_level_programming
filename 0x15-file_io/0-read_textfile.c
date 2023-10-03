#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints
 * @filename: name of the file
 * @letters: number of letters
 *
 * Return: no. of letters to read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	ssize_t j, k;
	char *buffer;

	if (filename == NULL)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(f);
		return (0);
	}
	j = read(f, buffer, letters);
	close(f);
	if (j == -1)
	{
		free(buffer);
		return (0);
	}
	k = write(STDOUT_FILENO, buffer, j);
	free(buffer);
	if (j != k)
		return (0);
	return (k);
}

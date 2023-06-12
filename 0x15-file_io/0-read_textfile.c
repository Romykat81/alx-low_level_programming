#include "main.h"

/**
* read_textfile - reads a textfile and prints
* @filename: file name
* @letters: no. of letters printed
* return: no. of letters printed
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t j, k;
	char *buff;

	if (!filename)
		return (0);

	i = open(filename, O_RDONLY);

	if (i == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	j = read(i, buff, letters);
	k = write(STDOUT_FILENO, buff, j);

	close(i);

	free(buff);

	return (k);
}

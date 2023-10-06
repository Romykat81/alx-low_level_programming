#include "main.h"

/**
 * append_text_to_file - appends text at end of a file
 * @filename: file name
 * @text_content: adds content
 *
 * return: 1 if true, -1 if false.
 *
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, letters, rdrw;

	if (!filename)
		return (-1);

	fd = open(filename, 0_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (letters = 0; text_content[letters]; letters++)
			;

		rdrw = write(dr, text_content, letters);

		if (rdrw == -1)
			return (-1);
	}

	close(fd);

	return (1);
}

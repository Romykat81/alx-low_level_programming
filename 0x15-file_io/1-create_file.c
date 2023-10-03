#include "main.h"

/**
 * create_file - creates a new file
 * @filename: filename
 * @text_context: content written in file
 *
 * return: 1 if it is a success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, letters, rdrw;

	if (!filename)
		return (-1);

	dr = open(filename, O_CREAT | O_WRONLY | 0_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	 if (!text_content)
		 text_content = " ";

	 for (letters = 0; text_content[letters]; letters++)
		 ;

	 rdrw = write(dr, text_content, letters);

	 if (rwr == -1)
		 return (-1);

	 close(fd);

	 return (1);
}

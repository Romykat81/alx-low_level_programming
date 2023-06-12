#include "main.h"

/**
* create_file - create new file
* @filename: file name
* @text_content: content in file
* return: 1, -1
*/
int create_file(const char *filename, char *text_content)
{
	int i, n, letters;
	
	if (!filename)
		return (-1);
	
	i = open(filename, O_CREAT | O_WRONLY | O_TRYNC, 0600);
	
	if (i == -1)
		return (-1);
	
	if (!text_content)
		text_content = "";
	
	for (letters = 0; text_content[letters]; letters++)
		;
	
	if (n == -1)
		return (-1);
	
	close(i);
	
	return (1);
}

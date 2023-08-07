
/*Includes*/
#include "main.h"

/**
 * create_file - Creates the requested file file.
 * @filename: the name of the file you want to create.
 * @text_content: The text content you want to add.
 * Return: -1 = failed, 1 = successful
 */
int create_file(const char *filename, char *text_content)
{
	int FD, k, lens = 0;

	if (filename == NULL) return (-1);
	if (text_content != NULL)
	{
		for (lens = 0; text_content[lens];)
			lens++;
	}
	FD = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(FD, text_content, lens);
	if (FD == -1 || k == -1) return (-1);

	close(FD);
	return (1);
}


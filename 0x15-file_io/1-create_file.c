#include "main.h"

/**
 * create_file - Creates the required file.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: fails - -1.
 */
int create_file(const char *filename, char *text_content)
{
	int b, k, len = 0;


	if (filename == NULL)
		return (-1);


	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	b = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(b, text_content, len);


	if (b == -1 || k == -1)
		return (-1);

	close(b);
	return (1);
}

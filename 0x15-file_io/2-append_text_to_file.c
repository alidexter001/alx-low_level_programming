#include "main.h"

/**
 * append_text_to_file - text at the end.
 * @filename: The name of the file.
 * @text_content: content to add at the end of the file.
 *
 * Return: fails - -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, b, len = 0;
	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	a = open(filename, O_WRONLY | O_APPEND);
	b = write(a, text_content, len);
	if (a == -1 || b == -1)
		return (-1);

	close(a);
	return (1);
}

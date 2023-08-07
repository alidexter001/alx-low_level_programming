#include "main.h"
#include <stdlib.h>



/**
 * read_textfile - Reads the text file and re print it.
 * @filename: the the name of the file.
 * @letters: the number of the letters on the file, will be counted and added.
 *
 * Return: if successful = 1, if failed = -1,
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a, b, c;
	char *buffer;
	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	a = open(filename, O_RDONLY);
	b = read(a, buffer, letters);
	c = write(STDOUT_FILENO, buffer, b);

	if (a == -1 || b == -1 || c == -1 || c != b)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(a);
	return (c);
}

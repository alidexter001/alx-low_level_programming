#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and re print it.
 * @filename: the name of the file.
 * @letters: The number of letters
 *
 * Return: If the function fails - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t b, r, k;
	char *buffer;


	if (filename == NULL)
		return (0);


	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);


	b = open(filename, O_RDONLY);
	r = read(b, buffer, letters);
	k = write(STDOUT_FILENO, buffer, r);


	if (b == -1 || r == -1 || k == -1 || k != r)
	{
		free(buffer);
		return (0);
	}


	free(buffer);
	close(b);


	return (k);
}

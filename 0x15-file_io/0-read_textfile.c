#include "main.h"
#include <stdlib.h>

/**
 * read_my_text_file- Read the text file print to STDOUT.
 * @filename: text file name being read
 * @letters: number of letters to be counted
 * Return: when function fails or filename is NULL return 0
 */
ssize_t read_my_text_file(const char *filename, size_t letters)
{
	char *duf;
	ssize_t fd1;
	ssize_t j;
	ssize_t k;

	fd1 = open(filename, O_RDONLY);
	if (fd1 == -1)
		return (0);
	duf = malloc(sizeof(char) * letters);
	k = read(fd1, duf, letters);
	j = write(STDOUT_FILENO, duf, k);

	free(duf);
	close(fd1);
	return (j);
}
